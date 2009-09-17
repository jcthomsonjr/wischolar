<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_biocv_context_default_contexts() {
  module_load_include('inc', 'scholar_biocv', 'scholar_biocv.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_biocv_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_biocv_menu_default_items() {
  module_load_include('inc', 'scholar_biocv', 'scholar_biocv.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_biocv_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_biocv_node_info() {
  module_load_include('inc', 'scholar_biocv', 'scholar_biocv.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_biocv_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_biocv_user_default_permissions() {
  module_load_include('inc', 'scholar_biocv', 'scholar_biocv.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_biocv_user_default_permissions', $args);
}
