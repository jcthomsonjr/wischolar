<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_projects_front_context_default_contexts() {
  module_load_include('inc', 'scholar_projects_front', 'scholar_projects_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_projects_front_context_default_contexts', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function scholar_projects_front_imagecache_default_presets() {
  module_load_include('inc', 'scholar_projects_front', 'scholar_projects_front.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_projects_front_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_projects_front_views_default_views() {
  module_load_include('inc', 'scholar_projects_front', 'scholar_projects_front.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_projects_front_views_default_views', $args);
}
