<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_publications_content_default_fields() {
  module_load_include('inc', 'scholar_publications', 'scholar_publications.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_publications_content_default_fields', $args);
}

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_publications_context_default_contexts() {
  module_load_include('inc', 'scholar_publications', 'scholar_publications.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_publications_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_publications_menu_default_items() {
  module_load_include('inc', 'scholar_publications', 'scholar_publications.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_publications_menu_default_items', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_publications_user_default_permissions() {
  module_load_include('inc', 'scholar_publications', 'scholar_publications.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_publications_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_publications_views_default_views() {
  module_load_include('inc', 'scholar_publications', 'scholar_publications.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_publications_views_default_views', $args);
}
