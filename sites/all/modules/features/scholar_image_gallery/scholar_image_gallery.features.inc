<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_image_gallery_content_default_fields() {
  module_load_include('inc', 'scholar_image_gallery', 'scholar_image_gallery.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_image_gallery_content_default_fields', $args);
}

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_image_gallery_context_default_contexts() {
  module_load_include('inc', 'scholar_image_gallery', 'scholar_image_gallery.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_image_gallery_context_default_contexts', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function scholar_image_gallery_imagecache_default_presets() {
  module_load_include('inc', 'scholar_image_gallery', 'scholar_image_gallery.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_image_gallery_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_image_gallery_menu_default_items() {
  module_load_include('inc', 'scholar_image_gallery', 'scholar_image_gallery.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_image_gallery_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_image_gallery_node_info() {
  module_load_include('inc', 'scholar_image_gallery', 'scholar_image_gallery.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_image_gallery_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_image_gallery_user_default_permissions() {
  module_load_include('inc', 'scholar_image_gallery', 'scholar_image_gallery.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_image_gallery_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function scholar_image_gallery_views_default_views() {
  module_load_include('inc', 'scholar_image_gallery', 'scholar_image_gallery.features.views');
  $args = func_get_args();
  return call_user_func_array('_scholar_image_gallery_views_default_views', $args);
}
