<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_user_default_permissions() {
  module_load_include('inc', 'scholar', 'scholar.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_user_default_permissions', $args);
}
