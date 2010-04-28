<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_search_luceneapi_user_default_permissions() {
  module_load_include('inc', 'vsite_search_luceneapi', 'vsite_search_luceneapi.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_search_luceneapi_user_default_permissions', $args);
}


/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_search_luceneapi_context_default_contexts() {
  module_load_include('inc', 'vsite_search_luceneapi', 'vsite_search_luceneapi.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_search_luceneapi_context_default_contexts', $args);
}

/**
 * Implementation of hook_strongarm().
 * 
 * Uncomment this function for Strongarm 6.x-2.x
 */
/**
function vsite_search_luceneapi_strongarm() {
  module_load_include('inc', 'vsite_search_luceneapi', 'vsite_search_luceneapi.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_search_luceneapi_strongarm', $args);
}
**/