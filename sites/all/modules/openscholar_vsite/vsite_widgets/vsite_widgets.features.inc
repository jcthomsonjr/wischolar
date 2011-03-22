<?php

/**
 * Implementation of hook_flag_default_flags().
 */
function vsite_widgets_flag_default_flags() {
$flags = array();
// Exported flag: "Featured Posts".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'featuredposts',
  'title' => 'Featured Posts',
  'global' => '1',
  'types' => 
  array (
  ),
  'flag_short' => 'Feature this post',
  'flag_long' => 'Make this a featured post',
  'flag_message' => '',
  'unflag_short' => 'Un-feature this post',
  'unflag_long' => 'No longer feature this post',
  'unflag_message' => '',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 2,
    ),
    'unflag' => 
    array (
      0 => 2,
    ),
  ),
  'show_on_page' => 0,
  'show_on_teaser' => 0,
  'show_on_form' => 0,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'vsite_widgets',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
return $flags;
}

/**
 * Implementation of hook_views_api().
 */
function vsite_widgets_views_api() {
  return array(
    'api' => '2',
  );
}
