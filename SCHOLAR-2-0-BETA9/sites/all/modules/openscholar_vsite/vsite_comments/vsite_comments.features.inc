<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_comments_user_default_permissions() {
  module_load_include('inc', 'vsite_comments', 'vsite_comments.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_comments_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function vsite_comments_views_default_views() {
  module_load_include('inc', 'vsite_comments', 'vsite_comments.features.views');
  $args = func_get_args();
  return call_user_func_array('_vsite_comments_views_default_views', $args);
}
