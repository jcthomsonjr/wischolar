<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_software_context_default_contexts() {
  module_load_include('inc', 'scholar_software', 'scholar_software.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_software_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_software_menu_default_items() {
  module_load_include('inc', 'scholar_software', 'scholar_software.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_software_menu_default_items', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_software_user_default_permissions() {
  module_load_include('inc', 'scholar_software', 'scholar_software.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_software_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_software_views_default_views() {
  module_load_include('inc', 'scholar_software', 'scholar_software.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_software_views_default_views', $args);
}
