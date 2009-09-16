<?php

function _vsite_filefield_paths_config() {
  $return = array();
  
  $types = og_get_types('group_post');
  $file_name = array(
    'value' => '[filefield-onlyname-original].[filefield-extension-original]',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0,
  );
  
  $file_path = array(
    'value' => '[space-og-path-raw]/files',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0,
  );
  foreach ($types as $type){
    //if (variable_get("upload_$type", "0") === "1"){
      db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath) VALUES ('%s', '%s', '%s', '%s')", $type, "upload", serialize($file_name), serialize($file_path));
    //}
  }
  
  $return[] = array('success' => TRUE,
                   'query' => "the upload file paths were inserted in the filefield_paths table");
  
  return $return;
}

function _vsite_global_taxonomy(){
  // Create the global vocab
  $vocab_nodes = array();
  $types =  og_get_types('group_post');
  foreach($types as $type){
    $vocab_nodes[$type] = 1;
  }
  $vocab = array(
    'name' => 'Scholar Taxonomy', 
    'multiple' => 0, 
    'required' => 0, 
    'hierarchy' => 0, 
    'relations' => 0, 
    'module' => 'vsite', 
    'weight' => 0, 
    'nodes' => $vocab_nodes,  
    'tags' => TRUE,
    'help' => t('Scholar global taxonomy'),
  );
  taxonomy_save_vocabulary($vocab);
}