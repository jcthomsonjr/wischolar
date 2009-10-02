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
function simport_import_file(&$node, $source, $file = NULL, $vsite = NULL){

  //determine site files directory, if set
  $dir = isset($vsite)? '/'. $vsite -> purl : '';

  //create full path to destination directory TODO: should get destination path token/filefield paths in content type settings.
  $full_dest_path = variable_get('simport_current_path', '') . '/' . variable_get('file_directory_path', '') . $dir;

  //create directory
  file_check_directory($full_dest_path, $mode = 1, $form_item = NULL);

  //copy file
  file_copy($source, $full_dest_path, $replace = FILE_EXISTS_REPLACE);

  if ($file){
    //customize a object a little bit
    $file -> uid = $node -> uid;
    $file-> filepath = variable_get('file_directory_path', '') . $dir .  '/' . $file-> filename;
    $file -> status = 1;
    $file -> timestamp = time();
  }

  // Get file information from source
  else{
    $file = new stdClass();
    $file -> uid = $node -> uid;
    $file -> filename = basename($source);
    $file -> filepath = dirname($source);
    $file -> filemime = file_get_mimetype($source);
    $file -> filesize = filesize($source);
    $file -> status =1;
    $file -> timestamp = filemtime($source); // TODO: should use modified time as timestamp?
  }

  //write data to files table
  drupal_write_record('files', $file);

  //return file object
  return $file;
}

/**
 * Pass it a vocalulary id and returns array of terms belonging to it
 * @param int $vid- vocabulary id
 */
function simport_import_list_terms($vid){
  $vocab = taxonomy_get_tree($vid);
  foreach ($vocab as $term){    
  $terms[] = strtolower($term -> name);    
  }
  return $terms;
}