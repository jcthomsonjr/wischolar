<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_announcements_content_default_fields() {
  module_load_include('inc', 'scholar_announcements', 'scholar_announcements.defaults');
  return _scholar_announcements_content_default_fields();
}

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_announcements_context_default_contexts() {
  module_load_include('inc', 'scholar_announcements', 'scholar_announcements.defaults');
  return _scholar_announcements_context_default_contexts();
}

/**
 * Implementation of hook_node_info().
 */
function scholar_announcements_node_info() {
  module_load_include('inc', 'scholar_announcements', 'scholar_announcements.defaults');
  return _scholar_announcements_node_info();
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_announcements_views_default_views() {
  module_load_include('inc', 'scholar_announcements', 'scholar_announcements.defaults');
  return _scholar_announcements_views_default_views();
}
