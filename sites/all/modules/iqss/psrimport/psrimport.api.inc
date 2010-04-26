<?php

/** API Functions and utilities **/

/**
 * Add a node to an OG
 */
function psrimport_node_to_og($nid){
  $sid = psrimport_get_sid();
  //$sid = 30;
if(!$sid){  
  $account = user_load(array('name' => 'pmoynihan'));
  if($spaces = vsite_get_vsite_by_owner($account -> uid)){
  if(!$sid = $spaces[0] -> group -> nid) psrimport_print("Error: Could not obtain SID when trying to add node to og"); 
  }
}
if($sid){  
    db_query("DELETE FROM {og_ancestry} WHERE nid = %d AND group_nid = %d", $nid, $sid);
    db_query("INSERT INTO {og_ancestry} (nid, group_nid) VALUES (%d, %d)", $nid, $sid);
  }
}

/**
 * Get the psr site id
 */
  function psrimport_get_sid(){
  db_set_active('default');
  if (is_int(PSR_SID) && (PSR_SID !== 0) ) return PSR_SID;
  $account = user_load(array('name' => 'pmoynihan'));
  if($spaces = vsite_get_vsite_by_owner($account -> uid)){
    return $spaces[0] -> group -> nid;
  }
  return false;
}

/**
 * Create files directory for the domain in 
 * preparation for files import
 */
function psrimport_create_files_directory($domain){
  $dst_domain = variable_get('file_directory_path', conf_path() .'/files') . '/' .  $domain;
  $dst_domain_files = variable_get('file_directory_path', conf_path() .'/files') . '/' .  $domain . '/files';
  file_check_directory($dst_domain, 1);

  if(file_check_directory($dst_domain_files, 1)){
    psrimport_print("Created files directory for $domain site: $dst_domain_files");
  }
}

/**
 * Enable features for PSR site
 */
function psrimport_enable_features(&$vsite, $features = array()){
  if (!is_array($features) || !count($features)) return false;
  vsite_include('vsiteapi');
  foreach ($features as $feature){
    $vsite -> features[$feature] = FEATURE_PUBLIC;
  }
  return spaces_save($vsite);
}

/**
 * Attach a file to an existing node for upload module
 *
 * @param object $node
 *  existing $node object
 * @param integer $old_nid
 *  previous node id
 * @param string $domain
 *  vsite domain or purl
 */
function psrimport_get_files($node,  $old_nid, $domain = 'psr'){
  db_set_active('psrd5');
  $dst = PSRIMPORT_FS_PATH . '/' . file_directory_path() . '/' .  $domain . '/files';
  $res = db_query("SELECT * FROM {files} WHERE nid = %d", $old_nid);
  db_set_active('default');
  while ($data = db_fetch_object($res)){
     
    //define source and check if file exists
    $src = PSR_FS_PATH . '/' . $data -> filepath;
    if (is_file($src)){
      //copy the file
      if(file_copy($src, $dst, $replace = FILE_EXISTS_REPLACE)){
        $filename = basename($src);

        //if file copied successfully then build the file object
        $file = new stdClass();
        $file -> uid = $node -> uid;
        $file -> nid = $node -> nid;
        $file -> vid = $node -> vid;
        $file -> description = $filename;
        $file ->list = 1;
        $file -> weight = 0;
        $file -> filename = $filename;
        $file -> filepath = file_directory_path(). '/' .  $domain . '/files/' . basename($src);
        $file -> filemime = $data -> filemime;
        $file -> filesize = $data -> filesize;
        $file -> status =1;
        $file -> timestamp = filemtime($src);

      
        //write data to files table
        drupal_write_record('files', $file);
      //  $fid = db_last_insert_id('files', 'fid');
        //write data to upload table
        drupal_write_record('upload', $file);
        psrimport_print("Imported file: " . basename($src));
      }
      else{
        psrimport_print("Error: Could not copy file: " . basename($src));
      }
    }
    else{
      psrimport_print("Error: source file not found: $src");
    }
  }
  return;
}

/*** Taxonomy API and Utils ***/

function psrimport_get_terms($old_vid){
  //get the vocab data
  db_set_active('psrd5');

  $term_data = array();
  //get all terms to merge into default vocab
  $res = db_query("SELECT * FROM {term_data} WHERE vid = %d", $old_vid);
  while ($data = db_fetch_object($res)){
    $term_data[] = array(
    'name' => $data -> name,
    'description' => $data -> description,
    'properties' => array (),
    );
  }
  return $term_data;
}

/**
 * Get terms associated with the node from old database and assign equivilent term to node.
 * Assumes that all terms have already been imported
 *
 * @param  object $node  - the new  node object  which must have value for $node ->nid
 * @param  array  $terms - list of terms which must already exist
 */
function psrimport_terms_to_node($node, $terms = array()){
  install_include(array('taxonomy'));
  
  if(count($terms)){
    foreach($terms as $old_vid => $term){ 
      //get new vid
      $vid = psrimport_get_new_vid($old_vid, $node -> type);  
      //get new tid    
      $tid = install_taxonomy_get_tid($term, $vid);

      db_query("DELETE FROM {term_node} WHERE nid = %d AND vid = %d AND tid = %d" , $node -> nid, $node -> nid, $tid);      
      db_query("INSERT INTO {term_node} (nid, vid, tid) VALUES (%d, %d, %d)", $node -> nid, $node -> nid, $tid);
    }
  }
}




/**
 * Returns new vocabulary id when passed old vocabulary id
 * @return integer
 *  vocabulary id
 */
function psrimport_get_new_vid($old_vid, $new_type = NULL){
   db_set_active('psrd5');
   $vocab_name = db_result(db_query("SELECT name FROM {vocabulary} WHERE vid = %d", $old_vid));
   
   db_set_active('default');
   if ($new_type){
   $data = db_fetch_object(db_query_range("SELECT v.vid, v.name, vnt.type FROM {vocabulary} v
    INNER JOIN {vocabulary_node_types} vnt USING(vid) HAVING v.name = '%s' AND vnt.type = '%s'", $vocab_name, $new_type, 0, 1 ));  
   return $data -> vid;
   }
   else{
     //very unlikely to have duplicate vocab names, but try to pass $new_type if possible to be sure to right vid 
     return db_result(db_query_range("SELECT vid FROM {vocabulary} WHERE name = '%s' ", $vocab_name, 0, 1));     
  }     
}

/*** Field Helper Functions **/

/**
 * Return event times for node
 */
function psrimport_get_event_times($old_nid){
  db_set_active('psrd5');  // datetime example  - '2010-04-15T15:11:00' 
  $table = 'event';
  $times = db_fetch_array(db_query("SELECT * FROM {$table} WHERE nid = %d", $old_nid));
  $start = date("Y-m-d", $times['event_start']). 'T' . date("H:i:s", $times['event_start']);
  $end = date("Y-m-d", $times['event_end']). 'T' . date("H:i:s", $times['event_end']);
  return array('value' => $start, 'value2' => $end); 
}

/**
 * Retruns cck links in a node and returns markup containing links
 */
function psrimport_get_links($table , $field, $old_nid){
  db_set_active('psrd5');
  $additional_text ='';
  //multiple links
  $res = db_query("SELECT * FROM {$table} WHERE nid = %d", $old_nid);
  while($data = db_fetch_object($res)){
    $links[] = $data -> $field;
  }

  if(count($links)){
    $additional_text .= '<p>Link(s): </p>';
    foreach($links as $link){
      $additional_text .= '<p>' . $link .   '</p>';
    }
    return $additional_text;
  }
}

/**
 * Abstraction function to print real time feedback
 * and to prevent errors if script is not run with drush
 */
function psrimport_print($text){
  switch(PSR_DRUSH_RUN){
    case 0;
    return print (t("$text"));
    break;

    case 1:
      return drush_print (t("$text"));
      break;

    default:
      return print (t("$text"));
      break;
  }
}