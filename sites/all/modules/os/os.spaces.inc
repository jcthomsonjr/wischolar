<?php

/**
 * Implementation of hook_spaces_presets().
 */
function os_spaces_presets() {
  $export = array();
  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'scholar';
  $spaces_presets->title = 'OS personal';
  $spaces_presets->description = 'OpenScholar personal site';
  $spaces_presets->space_type = 'og';
  $spaces_presets->value = array(
    'variable' => array(
      'spaces_features' => array(
        'scholar_announcements' => 0,
        'scholar_publications' => 2,
        'scholar_front' => 2,
        'scholar_biocv' => 2,
        'scholar_classes' => 2,
        'scholar_pages' => 2,
        'scholar_image_gallery' => 0,
        'scholar_reader' => 0,
        'scholar_announcements' => 0,
        'scholar_blog' => 0,
        'scholar_dvn' => 0,
        'scholar_links' => 0,
        'scholar_software' => 0
      ),
      'spaces_og_selective' => 0,
      'spaces_og_register' => 1,
      'spaces_og_directory' => 1,
      'spaces_og_private' => 0,
      'site_frontpage' => 'home',
      'site_frontpage_path' => 'home',
      'default_theme' => 'scholar_airstream',
    ),
    'vsite_menu' => array(
      'vsite_menu_weights' => array(
        "features:presentations" => 10,
        "features:software" => 12,
        "features:publications" => 11,
        "features:links" => 8,
        "features:classes" => 4,
        "features:data" => 1,
        "features:people" => 9,
        "features:images" => 7,
        "features:documents" => 5,
        "features:blog" => 3,
        "features:biocv" => 2,
        "features:announcements" => 0,
        "features:reader" => 6,
      ),
    )
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('OS personal');
  t('OpenScholar personal site');

  $export['scholar'] = $spaces_presets;
  return $export;
}
