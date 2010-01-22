<?php

/**
 * Implementation of hook_flag_default_flags().
 */
function vsite_front_flag_default_flags() {
  module_load_include('inc', 'vsite_front', 'vsite_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_front_flag_default_flags', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function vsite_front_views_default_views() {
  module_load_include('inc', 'vsite_front', 'vsite_front.features.views');
  $args = func_get_args();
  return call_user_func_array('_vsite_front_views_default_views', $args);
}
