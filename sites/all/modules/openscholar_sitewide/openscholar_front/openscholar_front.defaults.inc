<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _openscholar_front_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'openscholar',
    'attribute' => 'section',
    'value' => 'sitewide',
    'description' => 'openscholar sitewide, no vsite context',
    'block' => array(
      'openscholar_front_site_info' => array(
        'module' => 'openscholar_front',
        'delta' => 'site_info',
        'weight' => 37,
        'region' => 'header_main',
        'status' => '0',
        'label' => 'OpenScholar: Site info',
        'type' => 'context_ui',
      ),
      'openscholar_front_top_links' => array(
        'module' => 'openscholar_front',
        'delta' => 'top_links',
        'weight' => 37,
        'region' => 'header_right',
        'status' => '0',
        'label' => 'OpenScholar: Top links',
        'type' => 'context_ui',
      ),
    ),
  );
  $items[] = array(
    'namespace' => 'openscholar',
    'attribute' => 'section',
    'value' => 'sitewide_front',
    'description' => 'openscholar front context',
    'path' => array(
      '<front>' => '<front>',
    ),
    'block' => array(
      'openscholar_front_site_info' => array(
        'module' => 'openscholar_front',
        'delta' => 'site_info',
        'weight' => 36,
        'region' => 'header_main',
        'status' => '0',
        'label' => 'OpenScholar: Site info',
        'type' => 'context_ui',
      ),
      'openscholar_front_top_links' => array(
        'module' => 'openscholar_front',
        'delta' => 'top_links',
        'weight' => 36,
        'region' => 'header_right',
        'status' => '0',
        'label' => 'OpenScholar: Top links',
        'type' => 'context_ui',
      ),
      'openscholar_front_video_info' => array(
        'module' => 'openscholar_front',
        'delta' => 'video_info',
        'weight' => 36,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'OpenScholar: Video info',
        'type' => 'context_ui',
      ),
      'views_openscholar_sites-block_2' => array(
        'module' => 'views',
        'delta' => 'openscholar_sites-block_2',
        'weight' => 36,
        'region' => 'content_bottom',
        'status' => '0',
        'label' => 'Latest Web Sites',
        'type' => 'context_ui',
      ),
      'openscholar_front_site_mission' => array(
        'module' => 'openscholar_front',
        'delta' => 'site_mission',
        'weight' => 37,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'OpenScholar: Mission Statement',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_flag_default_flags().
 */
function _openscholar_front_flag_default_flags() {
$flags = array();
// Exported flag: "Featured web sites".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'featured_web_sites',
  'title' => 'Featured web sites',
  'global' => '1',
  'types' => 
  array (
    0 => 'vsite',
  ),
  'flag_short' => 'feature',
  'flag_long' => 'make it featured web site',
  'flag_message' => 'featured',
  'unflag_short' => 'unfeature',
  'unflag_long' => 'remove from featured web site',
  'unflag_message' => 'unfeature',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
    ),
    'unflag' => 
    array (
    ),
  ),
  'show_on_page' => 0,
  'show_on_teaser' => 0,
  'show_on_form' => 0,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'openscholar_front',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
return $flags;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _openscholar_front_imagecache_default_presets() {
  $items = array(
    'openscholar_front_logo' => array(
      'presetname' => 'openscholar_front_logo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
          ),
        ),
      ),
    ),
  );
  return $items;
}
