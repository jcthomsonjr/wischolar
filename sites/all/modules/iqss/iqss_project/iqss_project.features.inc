<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function iqss_project_imagecache_default_presets() {
  module_load_include('inc', 'iqss_project', 'iqss_project.defaults');
  $args = func_get_args();
  return call_user_func_array('_iqss_project_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function iqss_project_views_default_views() {
  module_load_include('inc', 'iqss_project', 'iqss_project.features.views');
  $args = func_get_args();
  return call_user_func_array('_iqss_project_views_default_views', $args);
}
