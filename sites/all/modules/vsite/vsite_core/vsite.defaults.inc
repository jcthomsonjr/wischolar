<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _vsite_content_default_fields() {
  $fields = array();

  // Exported field: field_file
  $fields[] = array(
    'field_name' => 'field_file',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => '',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Files',
      'weight' => '2',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_image
  $fields[] = array(
    'field_name' => 'field_image',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'image_s_linked',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_s_default',
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
      'max_resolution' => 0,
      'min_resolution' => 0,
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Images',
      'weight' => '4',
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
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _vsite_imagecache_default_presets(){
  $presets = array();
  $presets['vsite_image_teaser_thumb'] = array(
    'presetname' => 'vsite_image_teaser_thumb', 
    'actions' => array(
      0 => array(
        'weight' => '0', 
        'module' => 'imagecache', 
        'action' => 'imagecache_scale', 
        'data' => array(
          'width' => '', 
          'height' => '150', 
          'upscale' => 0 
        ) 
      ) 
    ) 
  );
  $presets['vsite_image_page_thumb'] = array(
    'presetname' => 'vsite_image_teaser_thumb', 
    'actions' => array(
      0 => array(
        'weight' => '0', 
        'module' => 'imagecache', 
        'action' => 'imagecache_scale', 
        'data' => array(
          'width' => '', 
          'height' => '250', 
          'upscale' => 0 
        ) 
      ) 
    ) 
  );
  return $presets;
}
