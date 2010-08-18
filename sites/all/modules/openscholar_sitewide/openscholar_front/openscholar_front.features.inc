<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function openscholar_front_context_default_contexts() {
  module_load_include('inc', 'openscholar_front', 'openscholar_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_openscholar_front_context_default_contexts', $args);
}

/**
 * Implementation of hook_flag_default_flags().
 */
function openscholar_front_flag_default_flags() {
  module_load_include('inc', 'openscholar_front', 'openscholar_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_openscholar_front_flag_default_flags', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function openscholar_front_imagecache_default_presets() {
  module_load_include('inc', 'openscholar_front', 'openscholar_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_openscholar_front_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function openscholar_front_node_info() {
  module_load_include('inc', 'openscholar_front', 'openscholar_front.features.node');
  $args = func_get_args();
  return call_user_func_array('_openscholar_front_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function openscholar_front_views_default_views() {
  module_load_include('inc', 'openscholar_front', 'openscholar_front.features.views');
  $args = func_get_args();
  return call_user_func_array('_openscholar_front_views_default_views', $args);
}
