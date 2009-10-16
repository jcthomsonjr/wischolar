<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_widgets_user_default_permissions() {
  module_load_include('inc', 'vsite_widgets', 'vsite_widgets.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_widgets_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function vsite_widgets_views_default_views() {
  module_load_include('inc', 'vsite_widgets', 'vsite_widgets.features.views');
  $args = func_get_args();
  return call_user_func_array('_vsite_widgets_views_default_views', $args);
}
