<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_presentations_content_default_fields() {
  $fields = array();

  // Exported field: field_date
  $fields[] = array(
    'field_name' => 'field_date',
    'type_name' => 'presentation',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'long',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'long',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => 'optional',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'long',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - g:ia',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'default_value_custom' => '',
      'default_value_custom2' => '',
      'label' => 'Date',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_presentation_presenter
  $fields[] = array(
    'field_name' => 'field_presentation_presenter',
    'type_name' => 'presentation',
    'display_settings' => array(
      'weight' => '-3',
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
    'required' => '1',
    'multiple' => '1',
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
          '_error_element' => 'default_value_widget][field_presentation_presenter][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Presenter(s)',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  array(
    t('Date'),
    t('Presenter(s)'),
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
    'roles' => array(),
  );

  // Exported permission: delete own presentation content
  $permissions[] = array(
    'name' => 'delete own presentation content',
    'roles' => array(),
  );

  // Exported permission: edit own presentation content
  $permissions[] = array(
    'name' => 'edit own presentation content',
    'roles' => array(),
  );

  // Exported permission: override presentation promote to front page option
  $permissions[] = array(
    'name' => 'override presentation promote to front page option',
    'roles' => array(),
  );

  // Exported permission: override presentation published option
  $permissions[] = array(
    'name' => 'override presentation published option',
    'roles' => array(),
  );

  // Exported permission: override presentation revision option
  $permissions[] = array(
    'name' => 'override presentation revision option',
    'roles' => array(),
  );

  // Exported permission: override presentation sticky option
  $permissions[] = array(
    'name' => 'override presentation sticky option',
    'roles' => array(),
  );

  return $permissions;
}