<?php

/**
 * Implementation of hook_flag_default_flags().
 */
function vsite_news_flag_default_flags() {
$flags = array();
// Exported flag: "Follow".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'vsite_follow',
  'title' => 'Follow',
  'global' => '0',
  'types' => 
  array (
    0 => 'vsite',
  ),
  'flag_short' => 'follow',
  'flag_long' => 'follow activity in other web sites',
  'flag_message' => '',
  'unflag_short' => 'Dont follow',
  'unflag_long' => 'Removed from your following list',
  'unflag_message' => '',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => '3',
    ),
    'unflag' => 
    array (
      0 => '3',
    ),
  ),
  'show_on_page' => false,
  'show_on_teaser' => true,
  'show_on_form' => false,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'vsite_news',
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
function vsite_news_views_api() {
  return array(
    'api' => '2',
  );
}
