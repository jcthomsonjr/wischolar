<?php

/**
 * Implementation of hook_content_default_fields().
 */
function vsite_users_content_default_fields() {
  module_load_include('inc', 'vsite_users', 'vsite_users.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_users_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function vsite_users_node_info() {
  module_load_include('inc', 'vsite_users', 'vsite_users.features.node');
  $args = func_get_args();
  return call_user_func_array('_vsite_users_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_users_user_default_permissions() {
  module_load_include('inc', 'vsite_users', 'vsite_users.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_users_user_default_permissions', $args);
}
