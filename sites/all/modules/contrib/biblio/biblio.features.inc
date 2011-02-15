<?php

/*
 * @file
 * Hooks and implementations for Features
 */

/**
 * Implementation of hook_features_export_options.
 */
function biblio_config_features_export_options() {
  $options = array(
    'biblio_field_type' => t('Biblio Field Types'),
    'biblio_field_type_data' => t('Biblio Field Type Data'),
    'biblio_contributor_type' => t('Biblio Contributer Type'),
    'biblio_contributor_type_data' => t('Biblio Contributer Type Data'),
  );
  
  return $options;
}

/**
 * Implementation of hook_features_export
 */
function biblio_config_features_export($data, &$export, $module_name) {
  $export['dependencies']['biblio'] = 'biblio';
  
  foreach ($data as $component) {
    $export['features']['biblio_config'][$component] = $component;
  }
  
  return array();
}

/**
 * Implementation of hook_features_export_render.
 */
function biblio_config_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '  $biblio_configs = array();';
  $code[] = '';
  foreach ($data as $table) {
    $item = _biblio_config_get_data($table);
    if (isset($item[$table])) {
      $code[] = '  $biblio_configs[] = '.features_var_export($item,'  ').';';  
    }
  }
  $code[] = '  return $biblio_configs;';
  $code = implode("\n", $code);
  return array('biblio_config_features_default_settings' => $code);
}

/** 
 * Gets the form config into an array
 * @param unknown_type $name
 */
function _biblio_config_get_data($table) {
  $data = array();
  $q = db_query("SELECT * FROM {".$table."}");
  while ($r = db_fetch_array($q)) {
    $arr = array();
    foreach ($r as $k => $v) {
      $arr[$k] = $v;
    }
    $data[$table][] = $arr;
  }
  
  return $data;
}

/**
 * Implementation of hook_features_rebuild().
 */
function biblio_config_features_rebuild($module) {
  $items = module_invoke($module, 'biblio_config_features_default_settings');
  foreach ($items as $idx => $item) {
    $saved = _biblio_config_set_data($item);
  }
}

/** 
 * Puts the form config data into the database
 */
function _biblio_config_set_data($item) {
  $table = key($item);
  $schema = drupal_get_schema($table);
  $primary = $schema['primary key'];
  foreach ($item[$table] as $row) {
    $query = $where = $w_args = $u_args = $q_args = array();
    foreach ($row as $k => $v) {
      if (in_array($k, $primary)) {
        $where[] = "%s = ".(gettype($v)=="string"?"'%s'":"%d");
        $w_args[] = $k;
        $w_args[] = $v;
      }
      else {
        $query[] = "%s = ".(gettype($v)=="string"?"'%s'":"%d");
        $u_args[] = $k;
        $u_args[] = $v;
      }
    }
  
    $q_args = array_merge($u_args, $w_args);
    array_unshift($q_args,  "INSERT INTO {".$table."} SET ".implode(', ',array_merge($query, $where)));
    
    // try inserting
    if (!@call_user_func_array('db_query', $q_args) && count($query)) {
      // it failed, so update, but only if all the fields arent primary keys.
      // if all the fields are primary keys, they exist and there's no other parameters so we're good
      $q_args[0] = "UPDATE {".$table."} SET ".implode(', ',$query)." WHERE ".implode(' AND ',$where);
      call_user_func_array('db_query', $q_args);
    }
  }
}

/**
 * Implementation of hook_features_revert.
 */
function biblio_config_features_revert($module) {
  biblio_config_features_rebuild($module);
}