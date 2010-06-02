<?php

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
 