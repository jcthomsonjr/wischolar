<?php

function _openscholar_front_osboot(){
  /*
  system_theme_data(); // Rebuild theme cache.
  _block_rehash(); // Rebuild block cache.
  views_invalidate_cache(); // Rebuild the views.
  menu_rebuild(); // Rebuild the menu.
  features_revert(); // Features rebuild scripts.
  */
  

  //_scholar_testingcontent();
  //_vsite_filefield_paths_config();
  //_vsite_global_taxonomy();
  //_vsite_flags_boot();

  //Create Vsite Taxonomies
  //_vsite_object_create_taxonomys();
    
  //Create default sitewide contact form
  //_vsite_default_contact_form();

  variable_set('scholar_installed', 1);
  //variable_set('site_frontpage', 'welcome');
}


/**
 * Updates the filefield settings for group content types
 */
/*
function _vsite_filefield_paths_config(){
  $return = array();
  
  //set the "upload" paths
  $types = og_get_types('group_post');
  $file_name = array(
    'value' => '[filefield-onlyname-original].[filefield-extension-original]',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0
  );
  
  $file_path = array(
    'value' => '[space-og-path-raw]/files',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0
  );
  
  $file_alias = array(
    'value' => '[space-og-path-raw]/files/[filefield-onlyname-original].[filefield-extension-original]',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0,
    'display' => 1,
  );
  
  
  foreach ( $types as $type ) {
    $file_alias['display'] = ($type == 'image')?0:1; //turn on display for all but image
    db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath, filealias) VALUES ('%s', '%s', '%s', '%s', '%s')", $type, "upload", serialize($file_name), serialize($file_path), serialize($file_alias));
  }
  
  //set the "filefield" paths
  reset($types);
  
  //find the fields
  foreach ( content_fields() as $field ) {
    if (($field['module'] == 'filefield') && in_array($field['type_name'], $types)) {
      //add settings to database if applicable
      db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath) VALUES ('%s', '%s', '%s', '%s')", $field['type_name'], $field['field_name'], serialize($file_name), serialize($file_path));
    }
  }
  
  $return[] = array(
    'success' => TRUE,
    'query' => "the upload and filefield file paths were inserted in the filefield_paths table"
  );
  
  return $return;
}
*/

/*
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
  
  $vid = db_last_insert_id('vocabulary', 'vid');
  variable_set('scholar_global_taxonomy', $vid);
}
*/







