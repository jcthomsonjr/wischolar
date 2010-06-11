<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_presentations_content_default_fields() {
  module_load_include('inc', 'scholar_presentations', 'scholar_presentations.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_presentations_content_default_fields', $args);
}

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_presentations_context_default_contexts() {
  module_load_include('inc', 'scholar_presentations', 'scholar_presentations.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_presentations_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_presentations_menu_default_items() {
  module_load_include('inc', 'scholar_presentations', 'scholar_presentations.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_presentations_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_presentations_node_info() {
  module_load_include('inc', 'scholar_presentations', 'scholar_presentations.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_presentations_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_presentations_user_default_permissions() {
  module_load_include('inc', 'scholar_presentations', 'scholar_presentations.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_presentations_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_presentations_views_default_views() {
  module_load_include('inc', 'scholar_presentations', 'scholar_presentations.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_presentations_views_default_views', $args);
}
