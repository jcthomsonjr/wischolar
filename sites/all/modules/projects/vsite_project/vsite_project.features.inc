<?php

/**
 * Implementation of hook_node_info().
 */
function vsite_project_node_info() {
  module_load_include('inc', 'vsite_project', 'vsite_project.features.node');
  $args = func_get_args();
  return call_user_func_array('_vsite_project_node_info', $args);
}
