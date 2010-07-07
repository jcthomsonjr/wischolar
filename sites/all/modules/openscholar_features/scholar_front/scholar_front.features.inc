<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_front_context_default_contexts() {
  module_load_include('inc', 'scholar_front', 'scholar_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_front_context_default_contexts', $args);
}

/**
 * Implementation of hook_flag_default_flags().
 */
function scholar_front_flag_default_flags() {
  module_load_include('inc', 'scholar_front', 'scholar_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_front_flag_default_flags', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_front_views_default_views() {
  module_load_include('inc', 'scholar_front', 'scholar_front.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_front_views_default_views', $args);
}
