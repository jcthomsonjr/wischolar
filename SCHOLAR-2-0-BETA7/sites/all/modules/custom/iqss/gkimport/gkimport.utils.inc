<?php


function gkimport_taxonomy_get_tid($name, $vid = 0, $parent_tid = 0) {
  $tids = array();
  // if a vid is passed in, limit to it
  if ($vid) {
    $res = db_query("SELECT tid FROM {term_data} WHERE name = '%s' and vid = %d", $name, $vid);
    while($data = db_fetch_object($res)){
      $tids[] = $data -> tid;
    }
  }
//return drush_print_r($tids);
  if (count($tids) == 1){
    return $tids[0];
  }
  else {
    if(!count($tids)){
      drush_print("term: $name not found");
      return NULL;
    }
    else{
      $children =  taxonomy_get_children($parent_tid, $vid, $key = 'tid');
      foreach($children as $term){
        if ($term ->name == $name) return $term -> tid;
      }
    }
  }
}


function  gkimport_get_term_tid($term_name, $parent_name, $parent_tid = NULL, $tree){
  install_include(array('taxonomy'));
  $ri_vid = variable_get('gkimport_ri_vocab_id', '');
  //check for level 2 match
  if($parent_tid){
    $parent_matches = taxonomy_get_term_by_name($parent_tid);
    if (count($parent_matches)){
      foreach ($parent_matches as $parent){
        if ($parent-> vid == $ri_vid && $parent -> name  == $parent_name){
          //level 2 match
          return $parent_tid;
        }
      }
    }
    //check for sub terms
    reset($tree);
    foreach($tree as $level_1){
      foreach($level_1->children as $level_2) {
        if (count($level_2 -> children)){
          foreach($level_2 -> children as $level_3){
            if ($level_3-> name ==  $term_name) return $level_3 -> tid;
            if (count($level_3->children)){
              foreach ($level_3->children as $level_4){
                if ($level_4-> name ==  $term_name) return $level_4 -> tid;
              }
            }
          }
        }
      }
    }
  }
  else{
    return NULL;
  }
}
 
 function taxonomy_get_nested_tree($terms = array(), $max_depth = NULL, $parent = 0, $parents_index = array(), $depth = 0) {
  if (is_int($terms)) {
    $terms = taxonomy_get_tree($terms);
  }

  foreach($terms as $term) {
    foreach($term->parents as $term_parent) {
      if ($term_parent == $parent) {
        $return[$term->tid] = $term;
      }
      else {
        $parents_index[$term_parent][$term->tid] = $term;
      }
    }
  }

  foreach($return as &$term) {
    if (isset($parents_index[$term->tid]) && !is_null($max_depth) && $depth < $max_depth) {
      $term->children = taxonomy_get_nested_tree($parents_index[$term->tid], $max_depth, $term->tid, $parents_index, $depth + 1);
    }
  }

  return $return;
}
 

/**
 * Utility function - used to generate table data for biblio notes
 */
function gkimport_add_notes(){
  $filepath = GKIMPORT_FS_PATH . '/' . drupal_get_path('module', 'gkimport') . '/files/generate_pubnotes.txt';
  $data = unserialize(file_get_contents($filepath));
  //return dpm($data);

 foreach ($data as $info){
  db_query("INSERT INTO {biblio_notes_import} (title, notes) VALUES ('%s', '%s' ) ", $info['title'], $info['notes']);
  }

  foreach(_gkimport_generate_pubnotes_additional() as $info){
  db_query("INSERT INTO {biblio_notes_import} (title, notes) VALUES ('%s', '%s' ) ", $info['title'], $info['notes']);
  }
}
/**
 * Utility function - used to generate serialized data pubnotes file
 */
function gkimport_generate_notes_file(){
  $filepath = GKIMPORT_FS_PATH . '/' . drupal_get_path('module', 'gkimport') . '/files/generate_pubnotes.txt';
  $data_arr = array();
  $res=  db_query("SELECT * FROM {biblio_notes_import}");
  while ($data = db_fetch_object($res)){
    $data_arr[] = array('title' => $data -> title, 'notes' => $data -> notes);
  }
  $str = serialize($data_arr);
  file_put_contents($filepath, $str);
}
 

/**
 * Return formatted times for node submission
 */
function gkimport_convert_date_times($start, $end = array()){ 
  $start_val = date('c', mktime(0, 0, 0, $start[0], $start[1], $start[2]));  //month, day, year
  $end_val =  count($end) ? date('c', mktime(0, 0, 0, $end[0], $end[1], $end[2])) : NULL;
  return array('value' => $start_val , 'value2' => $end_val); 
}

/**
 * Submit function for adding 'Data' type in biblio
 */
function gkimport_biblio_admin_types_add_form_submit($form, & $form_state){
  $values = $form_state['values'];
  $values['tid'] = variable_get('biblio_max_user_tid', '999') + 1;
  drupal_write_record('biblio_types', $values);
  variable_set('biblio_max_user_tid', $values['tid']);
  for ($f = 1; $f <= 51; $f++) {
    $ft_vals = array(
      'tid'       => $values['tid'],
      'fid'       => $f,
      'ftdid'     => $f,
      'cust_tdid' => $f,
      'weight'    => $f,
      'visible'    => 1,
    );
    drupal_write_record('biblio_field_type', $ft_vals);
  }
  // Fill contributor types. Use the first 4 defaults.
  for ($type = 1; $type <= 4; $type++) {
    $ct_vals = array (
      'auth_category' => $type,
      'biblio_type' => $values['tid'],
      'auth_type' => $type,
      );
    drupal_write_record('biblio_contributor_type', $ct_vals);
  }

  // Refresh publication type string for translation.
  biblio_locale_refresh_types($values['tid']);
}

/**
 * Function to add filefield file to node
 *
 * @param $source  the path to the source image
 * @param $field_name the name of the cck field 
 * @param $node the node object to upload the image to (passed by reference)
 * @param  $save TRUE to save the node, FALSE to just return the node object
 * @param  $sid - site id (optional)
 * @param  $num - used for importing multiple files
 * @param  $account - user account object for which the file should belong to
 */
function gkimport_add_filefield_file($source, $field_name, &$node, $save = TRUE, $sid = NULL, $num = NULL, $account = NULL){
    
  if(!$num) $num = 0;
  // get the cck filefield
  $field = content_fields($field_name, $node -> type);

  // validators (can add our own validators if we want)
  $validators = filefield_widget_upload_validators($field);

  // where to store the file
  $files_path = filefield_widget_file_path($field);

  if(og_is_group_type($node->type) || $sid){
    $site_id = og_is_group_type($node->type) ? $node->nid : $sid;
    $vsite = spaces_load('og', $site_id);
    $files_path .= $vsite->purl;
    file_check_directory($files_path,FILE_CREATE_DIRECTORY);
    $files_path .= '/files';
    file_check_directory($files_path,FILE_CREATE_DIRECTORY);
  }//If this is the group node lets put it in the group directory

  // create the file object
  if(!@filesize($source)){
    error_log("could not get file size for [$source] ");
    return false;
  }//if the file does not exsit dont try and save

  //unset size limit for Gary's pdf's (FOR IMPORT ONLY)
  unset($validators['filefield_validate_size']);  
  $file = field_file_save_file($source, $validators, $files_path, $account);

  // attach it to the filefield field
  $node->field_presentation_file[$num] = array(
  'fid' => $file['fid'],
  'uid' => $node -> uid,
  'list' => 1,
  );

  // if $save param is set to FALSE, then return the $node object without saving
  if(!$save) return $node;

  // otherwise, save the node and return the file destination
  node_save($node);

  return $file['destination'];
}



function gkimport_test_term_assignments(){
  $res = db_query("SELECT nid, biblio_type FROM biblio");
  while($data = db_fetch_object($res)){
    $match = db_result(db_query("SELECT * FROM term_node WHERE nid = %d", $data -> nid));
    if($match){
      $matches[] = $data -> nid;
    }
    else{
      $node = node_load($data -> nid);
      $nonmatches[] = $data -> nid . ' ' . $data ->biblio_type . ' ' . $node -> title;

      $arr = array(100,101);
      if (!in_array($data -> biblio_type, $arr)){
        $relnonmatches[] = $data -> nid . ' ' . $data ->biblio_type . ' ' . $node -> title;
      }
    }
  }
}
