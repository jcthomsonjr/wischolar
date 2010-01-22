<?php

/**
 * Helper to implementation of hook_flag_default_flags().
 */
function _scholar_front_flag_default_flags() {
$flags = array();
// Exported flag: "Save to Front Page".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'scholar_frontpage',
  'title' => 'Save to Front Page',
  'global' => true,
  'flag_short' => 'Save to Front',
  'flag_long' => 'Save post to front page',
  'flag_message' => 'Saved to Front Page!',
  'unflag_short' => 'Remove from Front',
  'unflag_long' => 'Remove post from Front Page',
  'unflag_message' => 'Removed from Front Page',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => '2',
    ),
    'unflag' => 
    array (
      0 => '2',
    ),
  ),
  'show_on_page' => false,
  'show_on_teaser' => false,
  'show_on_form' => false,
  'access_author' => '',
  'i18n' => 0,
  'flag_confirmation' => 'Saved to Front Page',
  'locked' => 
  array (
    'types' => 'types',
    'name' => 'name',
    'show_on_page' => 'show_on_page',
    'show_on_teaser' => 'show_on_teaser',
    'show_on_form' => 'show_on_form',
    'global' => 'global',
  ),
  'module' => 'scholar_front',
  'api_version' => 2,
  'status' => true,
  'is_new' => true,
);
return $flags;
}
