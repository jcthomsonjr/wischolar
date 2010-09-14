<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function iqss_remote_source_user_default_permissions() {
  module_load_include('inc', 'iqss_remote_source', 'iqss_remote_source.defaults');
  $args = func_get_args();
  return call_user_func_array('_iqss_remote_source_user_default_permissions', $args);
}