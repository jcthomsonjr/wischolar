<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_reader_context_default_contexts() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_context_default_contexts', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_reader_ctools_plugin_api() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_data_default().
 */
function scholar_reader_data_default() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_data_default', $args);
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function scholar_reader_feeds_importer_default() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_feeds_importer_default', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_reader_menu_default_items() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_reader_node_info() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_reader_user_default_permissions() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_reader_views_default_views() {
  module_load_include('inc', 'scholar_reader', 'scholar_reader.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_reader_views_default_views', $args);
}
