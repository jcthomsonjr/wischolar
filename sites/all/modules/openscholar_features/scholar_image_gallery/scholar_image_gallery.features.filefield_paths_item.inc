<?php

/**
 * Implementation of hook_filefield_paths_item_default_items().
 */
function scholar_image_gallery_filefield_paths_item_default_items() {
  $settings = array();

  // Exported image-field_gallery_image
  $settings['image-field_gallery_image'] = array(
    'type' => 'image',
    'field' => 'field_gallery_image',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => '[space-og-path-raw]/files',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filealias' => FALSE,
  );

  return $settings;
}
