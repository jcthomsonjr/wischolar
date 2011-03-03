<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_front_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function scholar_front_flag_default_flags() {
$flags = array();
// Exported flag: "Save to Front Page".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'scholar_frontpage',
  'title' => 'Save to Front Page',
  'global' => '1',
  'types' => 
  array (
  ),
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
  'module' => 'scholar_front',
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
function scholar_front_views_api() {
  return array(
    'api' => '2',
  );
}
