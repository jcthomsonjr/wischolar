<?php

/**
 * Implementation of hook_content_default_fields().
 */
function vsite_support_content_default_fields() {
  module_load_include('inc', 'vsite_support', 'vsite_support.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_support_content_default_fields', $args);
}

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_support_context_default_contexts() {
  module_load_include('inc', 'vsite_support', 'vsite_support.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_support_context_default_contexts', $args);
}

/**
 * Implementation of hook_node_info().
 */
function vsite_support_node_info() {
  module_load_include('inc', 'vsite_support', 'vsite_support.features.node');
  $args = func_get_args();
  return call_user_func_array('_vsite_support_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function vsite_support_views_default_views() {
  module_load_include('inc', 'vsite_support', 'vsite_support.features.views');
  $args = func_get_args();
  return call_user_func_array('_vsite_support_views_default_views', $args);
}
