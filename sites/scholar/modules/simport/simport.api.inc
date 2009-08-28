<?php

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
  $node -> field_link_image[$i]['filepath'] =  ''; //TODO: need to define filepath here
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
  $full_dest_path = PATH_TO_ROOT . '/' . $dest_path;

  //make the directory
  mkdir($full_dest_path);

  //copy the file to the new location
  file_copy(&$src_path, $full_dest_path, $replace = FILE_EXISTS_REPLACE);

  //write the file data to the files table - TODO: not sure where to get timestamp???
  $sql = db_query("INSERT INTO {files} (uid, filename, filepath, filemime, filesize, status, timestamp)
  VALUES (%d, '%s', '%s', '%s', %d, %d, %d,'%s' )", (int)$uid, $file['filename'], $dest_path .'/' . $file['filename'], $file['filemime'], $file['filesize'], 1, now());

  return db_last_insert_id('files', 'fid');
}

