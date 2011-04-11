<?php

/**
 * Implementation of hook_views_default_views().
 */
function iqss_openscholar_front_views_default_views() {
  module_load_include('inc', 'iqss_openscholar_front', 'iqss_openscholar_front.features.views');
  $args = func_get_args();
  return call_user_func_array('_iqss_openscholar_front_views_default_views', $args);
}
