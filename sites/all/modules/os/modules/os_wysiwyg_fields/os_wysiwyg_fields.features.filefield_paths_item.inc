<?php

/**
 * Implementation of hook_filefield_paths_item_default_items().
 */
function os_wysiwyg_fields_filefield_paths_item_default_items() {
  $settings = array();

  // Exported page-field_os_inline_files
  $settings['page-field_os_inline_files'] = array(
    'type' => 'page',
    'field' => 'field_os_inline_files',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => '',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filealias' => array(
      'value' => 'sites/localhost.scholar/files/[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
      'display' => 0,
    ),
  );
  // Exported page-field_os_inline_image
  $settings['page-field_os_inline_image'] = array(
    'type' => 'page',
    'field' => 'field_os_inline_image',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => '',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filealias' => array(
      'value' => 'sites/localhost.scholar/files/[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
      'display' => 0,
    ),
  );

  return $settings;
}
