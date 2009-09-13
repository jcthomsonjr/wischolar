<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_classes_context_default_contexts() {
  module_load_include('inc', 'scholar_classes', 'scholar_classes.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_classes_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_classes_menu_default_items() {
  module_load_include('inc', 'scholar_classes', 'scholar_classes.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_classes_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_classes_node_info() {
  module_load_include('inc', 'scholar_classes', 'scholar_classes.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_classes_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_classes_user_default_permissions() {
  module_load_include('inc', 'scholar_classes', 'scholar_classes.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_classes_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_classes_views_default_views() {
  module_load_include('inc', 'scholar_classes', 'scholar_classes.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_classes_views_default_views', $args);
}
