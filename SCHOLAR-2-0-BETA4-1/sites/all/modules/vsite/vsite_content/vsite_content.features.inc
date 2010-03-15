<?php

/**
 * Implementation of hook_views_default_views().
 */
function vsite_content_views_default_views() {
  module_load_include('inc', 'vsite_content', 'vsite_content.features.views');
  $args = func_get_args();
  return call_user_func_array('_vsite_content_views_default_views', $args);
}
