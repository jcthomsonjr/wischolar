<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _vsite_content_default_fields() {
  $fields = array();

  // Exported field: field_vsite_logo
  $fields[] = array(
    'field_name' => 'field_vsite_logo',
    'type_name' => 'vsite',
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
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
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
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => array(
        'filename' => 'uniprofs1.jpg',
        'filepath' => drupal_get_path('module','vsite_design')."/theme/images/default_logo.jpg",
        'filemime' => 'image/jpeg',
        'source' => 'default_image_upload',
        'destination' => drupal_get_path('module','vsite_design')."/theme/images/default_logo.jpg",
        'filesize' => 37046,
        'uid' => '1',
        'status' => 1,
        'timestamp' => 1253894074,
        'origname' => '',
        'fid' => '23',
      ),
      'use_default_image' => 1,
      'label' => 'Site logo',
      'weight' => '31',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('Site logo'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _vsite_imagecache_default_presets() {
  $items = array(
    'square_35_35' => array(
      'presetname' => 'square_35_35',
      'actions' => array(
        '0' => array(
          'actionid' => '1',
          'presetid' => '1',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '35',
            'height' => '35',
          ),
        ),
      ),
    ),
    'square_50_50' => array(
      'presetname' => 'square_50_50',
      'actions' => array(
        '0' => array(
          'actionid' => '2',
          'presetid' => '2',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '50',
            'height' => '50',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_user_default_permissions() {
  $permissions = array();

  // Exported permission: configure spaces features
  $permissions[] = array(
    'name' => 'configure spaces features',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: search content
  $permissions[] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: upload files
  $permissions[] = array(
    'name' => 'upload files',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: view advanced help popup
  $permissions[] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: view advanced help topic
  $permissions[] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: view uploaded files
  $permissions[] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: view users outside groups
  $permissions[] = array(
    'name' => 'view users outside groups',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );
  

  return $permissions;
}
