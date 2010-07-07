<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_support_context_default_contexts() {
  module_load_include('inc', 'vsite_support', 'vsite_support.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_support_context_default_contexts', $args);
}
