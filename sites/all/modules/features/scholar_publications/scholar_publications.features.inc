<?php

/**
 * Implementation of hook_node_info().
 */
function scholar_publications_node_info() {
  module_load_include('inc', 'scholar_publications', 'scholar_publications.features.node');
  $args = func_get_args();
  return call_user_func_array('_scholar_publications_node_info', $args);
}
