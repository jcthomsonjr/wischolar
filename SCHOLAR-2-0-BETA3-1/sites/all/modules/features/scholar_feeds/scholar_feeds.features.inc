<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_feeds_context_default_contexts() {
  module_load_include('inc', 'scholar_feeds', 'scholar_feeds.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_feeds_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_feeds_menu_default_items() {
  module_load_include('inc', 'scholar_feeds', 'scholar_feeds.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_feeds_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_feeds_node_info() {
  module_load_include('inc', 'scholar_feeds', 'scholar_feeds.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_feeds_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_feeds_user_default_permissions() {
  module_load_include('inc', 'scholar_feeds', 'scholar_feeds.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_feeds_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_feeds_views_default_views() {
  module_load_include('inc', 'scholar_feeds', 'scholar_feeds.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_feeds_views_default_views', $args);
}
