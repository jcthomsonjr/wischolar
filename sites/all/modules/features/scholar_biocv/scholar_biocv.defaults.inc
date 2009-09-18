<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_biocv_content_default_fields() {
  $fields = array();

  // Exported field: field_cv_attach
  $fields[] = array(
    'field_name' => 'field_cv_attach',
    'type_name' => 'cv',
    'display_settings' => array (
      'label' => array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'columns' => array (
      'fid' => 
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' => 
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' => 
      array (
        'type' => 'text',
        'serialize' => true,
        'views' => true,
      ),
    ),
    'label' => 'PDF Upload',
    'type' => 'filefield',
    'widget_type' => 'filefield_widget',
    'change' => 'Change basic information',
    'weight' => '31',
    'file_extensions' => 'pdf',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'description' => '',
    'ffp_field_cv_pdf' => 
    array (
      'file_path' => '',
      'file_path_cleanup' => 
      array (
        'file_path_pathauto' => 0,
        'file_path_tolower' => 0,
        'file_path_transliterate' => 0,
      ),
      'file_name' => 'cv_[filefield-onlyname-original].[filefield-extension-original]',
      'file_name_cleanup' => 
      array (
        'file_name_pathauto' => 0,
        'file_name_tolower' => 0,
        'file_name_transliterate' => 0,
      ),
      'retroactive_update' => '',
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'op' => 'Save field settings',
    'module' => 'filefield',
    'widget_module' => 'filefield',
  );

  // Translatables
  array(
    t('cv attachment'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_biocv_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'biocv',
    'description' => 'scholar > bio / cv',
    'path' => array(
      'bio' => 'bio',
    ),
    'menu' => 'bio',
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_biocv_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Bio',
    'path' => 'bio',
    'weight' => '0',
  );
  // Translatables
  array(
    t('Bio'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_biocv_user_default_permissions() {
  $permissions = array();

  // Exported permission: create bio content
  $permissions[] = array(
    'name' => 'create bio content',
    'roles' => array(),
  );

  // Exported permission: create cv content
  $permissions[] = array(
    'name' => 'create cv content',
    'roles' => array(),
  );

  // Exported permission: delete own bio content
  $permissions[] = array(
    'name' => 'delete own bio content',
    'roles' => array(),
  );

  // Exported permission: delete own cv content
  $permissions[] = array(
    'name' => 'delete own cv content',
    'roles' => array(),
  );

  // Exported permission: edit own bio content
  $permissions[] = array(
    'name' => 'edit own bio content',
    'roles' => array(),
  );

  // Exported permission: edit own cv content
  $permissions[] = array(
    'name' => 'edit own cv content',
    'roles' => array(),
  );

  return $permissions;
}
