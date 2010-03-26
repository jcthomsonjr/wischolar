<?php

/**
 * Implementation of hook_menu_default_items().
 */
function scholar_dvn_menu_default_items() {
  module_load_include('inc', 'scholar_dvn', 'scholar_dvn.defaults');
  $args = func_get_args();
  return call_user_func_array('_scholar_dvn_menu_default_items', $args);
}
