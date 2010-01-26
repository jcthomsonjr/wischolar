<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_profiles_content_default_fields() {
  $fields = array();

  // Exported field: field_person_photo
  $fields[] = array(
    'field_name' => 'field_person_photo',
    'type_name' => 'person',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'collapsible' => '2',
      'resolution' => '200x150',
      'enforce_ratio' => 1,
      'croparea' => '500x500',
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Photo',
      'weight' => '31',
      'description' => '',
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Translatables
  array(
    t('Photo'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_profiles_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'People',
    'path' => 'people',
    'weight' => '0',
    'description' => 'List of profiles',
  );
  // Translatables
  array(
    t('List of profiles'),
    t('People'),
  );


  return $items;
}
