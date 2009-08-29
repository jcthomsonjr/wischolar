<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_links_content_default_fields() {
  module_load_include('inc', 'scholar_links', 'scholar_links.defaults');
  return _scholar_links_content_default_fields();
}

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_links_context_default_contexts() {
  module_load_include('inc', 'scholar_links', 'scholar_links.defaults');
  return _scholar_links_context_default_contexts();
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function scholar_links_imagecache_default_presets() {
  module_load_include('inc', 'scholar_links', 'scholar_links.defaults');
  return _scholar_links_imagecache_default_presets();
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_links_menu_default_items() {
  module_load_include('inc', 'scholar_links', 'scholar_links.defaults');
  return _scholar_links_menu_default_items();
}

/**
 * Implementation of hook_node_info().
 */
function scholar_links_node_info() {
  module_load_include('inc', 'scholar_links', 'scholar_links.defaults');
  return _scholar_links_node_info();
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_links_views_default_views() {
  module_load_include('inc', 'scholar_links', 'scholar_links.defaults');
  return _scholar_links_views_default_views();
}
