<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_software_content_default_fields() {
  $fields = array();

  // Exported field: field_scholar_software_logo
  $fields[] = array(
    'field_name' => 'field_scholar_software_logo',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-9',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '5' => array(
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
    'list_field' => '',
    'list_default' => '',
    'description_field' => '',
    'widget' => array(
      'file_extensions' => NULL,
      'file_path' => NULL,
      'progress_indicator' => NULL,
      'max_filesize_per_file' => NULL,
      'max_filesize_per_node' => NULL,
      'max_resolution' => NULL,
      'min_resolution' => NULL,
      'alt' => NULL,
      'custom_alt' => NULL,
      'title' => NULL,
      'custom_title' => NULL,
      'title_type' => NULL,
      'default_image' => NULL,
      'use_default_image' => NULL,
      'label' => 'Logo',
      'weight' => '-9',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_scholar_software_method
  $fields[] = array(
    'field_name' => 'field_scholar_software_method',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-12',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options("method");',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Packaging method',
      'weight' => '-12',
      'description' => 'Choose the packaging method used for this project.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_scholar_software_name
  $fields[] = array(
    'field_name' => 'field_scholar_software_name',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-10',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '30',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_scholar_software_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Software key',
      'weight' => '-10',
      'description' => 'The machine-readable name for your project. This name must contain only lowercase letters, numbers, and underscores. <strong>Example:</strong> cooking_recipes.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_scholar_software_repo
  $fields[] = array(
    'field_name' => 'field_scholar_software_repo',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-8',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'hidden',
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
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_scholar_software_repo][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Repository URL',
      'weight' => '-8',
      'description' => 'Example: http://r.harvard.edu/src/PACKAGE.CookingRecipes',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_scholar_software_file
  $fields[] = array(
    'field_name' => 'field_scholar_software_file',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-13',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'tgz tar gz zip',
      'file_path' => 'scholar_software',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Package',
      'weight' => '-13',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_scholar_software_project
  $fields[] = array(
    'field_name' => 'field_scholar_software_project',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-11',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'scholar_software_project' => 'scholar_software_project',
      'announcement' => 0,
      'blog' => 0,
      'book' => 0,
      'class' => 0,
      'class_material' => 0,
      'event' => 0,
      'feed' => 0,
      'gallery' => 0,
      'image' => 0,
      'link' => 0,
      'page' => 0,
      'person' => 0,
      'profile' => 0,
      'biblio' => 0,
      'vsite' => 0,
      'scholar_software_release' => 0,
      'vsite_users_profile' => 0,
      'bio' => 0,
      'cv' => 0,
    ),
    'advanced_view' => 'scholar_software_releaseprojects',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Project',
      'weight' => '-11',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_scholar_software_recommend
  $fields[] = array(
    'field_name' => 'field_scholar_software_recommend',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-6',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'recommended\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Recommended',
      'weight' => '-6',
      'description' => 'The recommended releases will be displayed on the project page. The latest recommended release per major version will be offered for update status.',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_scholar_software_security
  $fields[] = array(
    'field_name' => 'field_scholar_software_security',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-5',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'security\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'Not a security release',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Security release',
      'weight' => '-5',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_versionextra
  $fields[] = array(
    'field_name' => 'field_versionextra',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-7',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '20',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_versionextra][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Extra version',
      'weight' => '-7',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_versionmajor
  $fields[] = array(
    'field_name' => 'field_versionmajor',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-9',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => 0,
    'max' => 50,
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'major\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Major version',
      'weight' => '-9',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_versionpatch
  $fields[] = array(
    'field_name' => 'field_versionpatch',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-8',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => 0,
    'max' => 50,
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'patch\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Patch version',
      'weight' => '-8',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  array(
    t('Extra version'),
    t('Logo'),
    t('Major version'),
    t('Package'),
    t('Packaging method'),
    t('Patch version'),
    t('Project'),
    t('Recommended'),
    t('Repository URL'),
    t('Security release'),
    t('Software key'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_software_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'software',
    'description' => '',
    'node' => array(
      '0' => 'scholar_software_project',
      '1' => 'scholar_software_release',
    ),
    'views' => array(
      '0' => 'scholar_software_projects',
      '1' => 'scholar_software_releases',
      '2' => 'scholar_software_updates',
    ),
    'menu' => 'software',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => -20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar site categories',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 50,
        'region' => 'right',
        'status' => '0',
        'label' => 'AddThis button',
        'type' => 'context_ui',
      ),
      'views_scholar_software_releases-block_3' => array(
        'module' => 'views',
        'delta' => 'scholar_software_releases-block_3',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Software Releases',
        'type' => 'context_ui',
      ),
      'views_scholar_software_releases-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_software_releases-block_1',
        'weight' => 20,
        'region' => FALSE,
        'status' => '0',
        'label' => 'Recommended Software Releases',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_software_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Software',
    'path' => 'scholar_software',
    'weight' => '0',
    'description' => 'My software',
  );
  // Translatables
  array(
    t('My software'),
    t('Software'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_software_user_default_permissions() {
  $permissions = array();

  // Exported permission: create scholar_software_project content
  $permissions[] = array(
    'name' => 'create scholar_software_project content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: create scholar_software_release content
  $permissions[] = array(
    'name' => 'create scholar_software_release content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own scholar_software_project content
  $permissions[] = array(
    'name' => 'edit own scholar_software_project content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own scholar_software_release content
  $permissions[] = array(
    'name' => 'edit own scholar_software_release content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override scholar_software_project authored by option
  $permissions[] = array(
    'name' => 'override scholar_software_project authored by option',
    'roles' => array(),
  );

  // Exported permission: override scholar_software_project authored on option
  $permissions[] = array(
    'name' => 'override scholar_software_project authored on option',
    'roles' => array(),
  );

  // Exported permission: override scholar_software_project promote to front page option
  $permissions[] = array(
    'name' => 'override scholar_software_project promote to front page option',
    'roles' => array(),
  );

  // Exported permission: override scholar_software_project published option
  $permissions[] = array(
    'name' => 'override scholar_software_project published option',
    'roles' => array(),
  );

  // Exported permission: override scholar_software_release promote to front page option
  $permissions[] = array(
    'name' => 'override scholar_software_release promote to front page option',
    'roles' => array(),
  );

  // Exported permission: override scholar_software_release published option
  $permissions[] = array(
    'name' => 'override scholar_software_release published option',
    'roles' => array(),
  );

  // Exported permission: override scholar_software_release revision option
  $permissions[] = array(
    'name' => 'override scholar_software_release revision option',
    'roles' => array(),
  );

  return $permissions;
}
