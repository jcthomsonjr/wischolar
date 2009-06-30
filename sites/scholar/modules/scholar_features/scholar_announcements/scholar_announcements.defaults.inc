<?php

/**
 * Helper to implemetation of hook_content_default_fields().
 */
function _scholar_announcements_content_default_fields() {
  $fields = array();

  // Exported field: field_file
  $fields[] = array(
    'field_name' => 'field_file',
    'type_name' => 'announcement',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '1',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => 'doc pdf odt',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Files',
      'weight' => '1',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_image
  $fields[] = array(
    'field_name' => 'field_image',
    'type_name' => 'announcement',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '1',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
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
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Images',
      'weight' => '2',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('Files'),
    t('Images'),
  );

  return $fields;
}

/**
 * Helper to implemetation of hook_context_default_contexts().
 */
function _scholar_announcements_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'section',
    'value' => 'scholar_announcements',
    'description' => 'Maintain announcements in your site',
    'node' => array(
      '0' => 'announcement',
    ),
    'views' => array(
      '0' => 'scholar_announcements',
    ),
    'block' => array(
      'views_scholar_announcements-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_announcements-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_announcements: Block',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implemetation of hook_node_info().
 */
function _scholar_announcements_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'module' => 'node',
      'description' => t('Manage announcements in your web site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}

/**
 * Helper to implemetation of hook_views_default_views().
 */
function _scholar_announcements_views_default_views() {
  $views = array();

  return $views;
}
