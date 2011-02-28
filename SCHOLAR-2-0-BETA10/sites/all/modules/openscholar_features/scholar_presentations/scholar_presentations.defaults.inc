<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_presentations_content_default_fields() {
  $fields = array();

  // Exported field: field_presentation_date
  $fields[] = array(
    'field_name' => 'field_presentation_date',
    'type_name' => 'presentation',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'short',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'blank',
      'default_value_code2' => '',
      'input_format' => 'j M Y',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-10:+1',
      'label_position' => 'above',
      'label' => 'Presentation Date',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_presentation_file
  $fields[] = array(
    'field_name' => 'field_presentation_file',
    'type_name' => 'presentation',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => 'pdf doc docx odt xls ppt key txt',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Presentation Files',
      'weight' => 0,
      'description' => 'Upload the file(s) for this presentation.',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_presentation_location
  $fields[] = array(
    'field_name' => 'field_presentation_location',
    'type_name' => 'presentation',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
          '_error_element' => 'default_value_widget][field_presentation_location][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Location',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  array(
    t('Location'),
    t('Presentation Date'),
    t('Presentation Files'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_presentations_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'presentations',
    'description' => 'Presentations feature context',
    'node' => array(
      '0' => 'presentation',
    ),
    'views' => array(
      '0' => 'scholar_presentations',
    ),
    'menu' => 'presentations',
    'block' => array(
      'views_scholar_presentations-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_presentations-block_1',
        'weight' => 38,
        'region' => 'right',
        'status' => '0',
        'label' => 'Recent Presentations',
        'type' => 'context_ui',
      ),
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 39,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories - Filter categorized content',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 40,
        'region' => 'right',
        'status' => '0',
        'label' => 'ShareThis Button - Allows you to share posts using popular online services',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_presentations_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Presentations',
    'path' => 'presentations',
    'weight' => '0',
    'description' => 'List of presentations on my site',
  );
  // Translatables
  array(
    t('List of presentations on my site'),
    t('Presentations'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_presentations_user_default_permissions() {
  $permissions = array();

  // Exported permission: create presentation content
  $permissions[] = array(
    'name' => 'create presentation content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own presentation content
  $permissions[] = array(
    'name' => 'delete own presentation content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own presentation content
  $permissions[] = array(
    'name' => 'edit own presentation content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override presentation promote to front page option
  $permissions[] = array(
    'name' => 'override presentation promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override presentation published option
  $permissions[] = array(
    'name' => 'override presentation published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override presentation revision option
  $permissions[] = array(
    'name' => 'override presentation revision option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override presentation sticky option
  $permissions[] = array(
    'name' => 'override presentation sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}
