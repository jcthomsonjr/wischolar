<?php

/** API Funciton and utilities **/

/**
 * Add a node to an OG
 */
function psrimport_node_to_og($nid){
  $sid = psrimport_get_sid();
  
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
  if (PSR_SID) return PSR_SID;
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

        db_set_active('default');
        //write data to files table
        drupal_write_record('files', $file);
        $fid = db_last_insert_id('files', 'fid');
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