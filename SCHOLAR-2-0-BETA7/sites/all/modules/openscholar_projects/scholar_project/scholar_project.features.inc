<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_project_content_default_fields() {
  module_load_include('inc', 'scholar_project', 'scholar_project.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_project_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function scholar_project_node_info() {
  module_load_include('inc', 'scholar_project', 'scholar_project.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_project_node_info', $args);
}
