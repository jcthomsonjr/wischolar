<?php

/**
 * Imports an image as a filefield image of a given node
 * 
 * Usage example:
 * --------------
 * $node = node_load(array('nid' => 61));
 * $image = drupal_get_path('module', 'vsite_design').'/theme/images/default_logo.jpg';
 * simport_node_add_imagefield_image($image, 'field_img', $node);
 * 
 * @param $source  the path to the source image
 * @param $field_name the name of the cck field 
 * @param $node the node object to upload the image to (passed by reference)
 */
function simport_node_add_imagefield_image($source, $field_name, &$node){

  // get the cck filefield
  $field = content_fields($field_name, $node -> type);

  // validators (can add our own validators if we want)
  $validators = array_merge(filefield_widget_upload_validators($field), imagefield_widget_upload_validators($field));

  // where to store the file
  $files_path = filefield_widget_file_path($field);
  
  // create the file object
  $file = field_file_save_file($source, $validators, $files_path);

  //set uid to the node -> uid
 // $file -> uid = $node -> uid;

  // attach it to the filefield field
  $node->$field_name = array(
  0 => array(
  'fid' => $file['fid'],
  'uid' => $node -> uid,
  'list' => 1,
    )
  ); 
  
  // save the node (optional)
  node_save($node);
}


/**
 * API function - Transfers the file, creates entry in the files table, returns the file id
 * @param unknown_type $file
 */
function simport_import_filefield_file(&$node, $src_path, $file, $i=0){

  //get dest path TODO: should get destination path token/filefield paths in content type settings.
  $dest_path = variable_get('file_directory_path', '') . '/' . $node -> og_groups [0];

  $fid = _simport_import_file($src_path, $dest_path, $file, $node ->uid);

  $node -> field_link_image[$i]['fid'] = $fid;
  $node -> field_link_image[$i]['list'] = 1;
  $node -> field_link_image[$i]['uid'] = $node -> uid;
  $node -> field_link_image[$i]['filename'] =  $file['filename'];
  $node -> field_link_image[$i]['filepath'] =  $dest_path;
  $node -> field_link_image[$i]['filemime'] =   $file['filemime'];
  $node -> field_link_image[$i]['filesize'] =   $file['filesize'];
  $node -> field_link_image[$i]['status '] =  1;
}

 /**
  * API function - saves a single file to a node
  *
  * @param unknown_type $node
  * @param unknown_type $path
  */
 function simport_save_filefield_file(&$node, $path){
 //nothing here yet - should save node with node_save()  
}

/**
 * Helper function to transfer the file and create entry in files table
 * Returns file id
 *
 * @param unknown_type $src_path
 * @param unknown_type $dest_path
 * @param unknown_type $file
 * @param unknown_type $uid
 */
function _simport_import_file($src_path, $dest_path, $file, $uid){
  //create full path to destination directory
  $full_dest_path = variable_get('simport_current_path', '') . '/' . $dest_path;

  //make the directory
  mkdir($full_dest_path);

  //copy the file to the new location
  file_copy(&$src_path, $full_dest_path, $replace = FILE_EXISTS_REPLACE);

  //write the file data to the files table - TODO: not sure where to get timestamp???
  $sql = db_query("INSERT INTO {files} (uid, filename, filepath, filemime, filesize, status, timestamp)
  VALUES (%d, '%s', '%s', '%s', %d, %d, %d,'%s' )", (int)$uid, $file['filename'], $dest_path .'/' . $file['filename'], $file['filemime'], $file['filesize'], 1, now());

  return db_last_insert_id('files', 'fid');
}

