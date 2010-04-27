<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_search_apachesolr_user_default_permissions() {
  module_load_include('inc', 'vsite_search_apachesolr', 'vsite_search_apachesolr.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_search_apachesolr_user_default_permissions', $args);
}


/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_search_apachesolr_context_default_contexts() {
  module_load_include('inc', 'vsite_search_apachesolr', 'vsite_search_apachesolr.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_search_apachesolr_context_default_contexts', $args);
}