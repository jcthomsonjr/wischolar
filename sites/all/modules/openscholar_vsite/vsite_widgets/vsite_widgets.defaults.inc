<?php

/**
 * Helper to implementation of hook_flag_default_flags().
 */
function _vsite_widgets_flag_default_flags() {
$flags = array();
// Exported flag: "Featured Posts".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'featuredposts',
  'title' => 'Featured Posts',
  'global' => '1',
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
  'api_version' => 2,
  'locked' =>
  array (
    0 => 'name',
  ),
);
return $flags;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_widgets_user_default_permissions() {
  $permissions = array();

  // Exported permission: search content
  $permissions[] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: view addthis
  $permissions[] = array(
    'name' => 'view addthis',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
