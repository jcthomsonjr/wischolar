<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_book_context_default_contexts() {
  module_load_include('inc', 'scholar_book', 'scholar_book.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_book_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_book_menu_default_items() {
  module_load_include('inc', 'scholar_book', 'scholar_book.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_book_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_book_node_info() {
  module_load_include('inc', 'scholar_book', 'scholar_book.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_book_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_book_views_default_views() {
  module_load_include('inc', 'scholar_book', 'scholar_book.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_book_views_default_views', $args);
}
