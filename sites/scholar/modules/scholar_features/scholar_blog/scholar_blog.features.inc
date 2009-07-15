<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_blog_context_default_contexts() {
  module_load_include('inc', 'scholar_blog', 'scholar_blog.defaults');
  return _scholar_blog_context_default_contexts();
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_blog_menu_default_items() {
  module_load_include('inc', 'scholar_blog', 'scholar_blog.defaults');
  return _scholar_blog_menu_default_items();
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_blog_views_default_views() {
  module_load_include('inc', 'scholar_blog', 'scholar_blog.defaults');
  return _scholar_blog_views_default_views();
}
