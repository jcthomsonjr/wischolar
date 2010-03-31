<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_events_content_default_fields() {
  $fields = array();

  // Exported field: field_date
  $fields[] = array(
    'field_name' => 'field_date',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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

  // Translatables
  array(
    t('Date'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_events_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'events',
    'description' => '',
    'node' => array(
      '0' => 'event',
    ),
    'views' => array(
      '0' => 'scholar_events',
      '1' => 'scholar_events_upcoming',
    ),
    'menu' => 'calendar',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories - A widget used to quickly filter categorized content',
        'type' => 'context_ui',
      ),
      'vsite_widgets_2' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'ShareThis Button - Allows you to share posts using popular online services',
        'type' => 'context_ui',
      ),
      'scholar_events_mini' => array(
        'module' => 'scholar_events',
        'delta' => 'mini',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'Mini Calendar - A small calendar used to display your sites upcoming events',
        'type' => 'context_ui',
      ),
      'views_scholar_events_upcoming-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_events_upcoming-block_1',
        'weight' => 23,
        'region' => 'right',
        'status' => '0',
        'label' => 'Upcoming events',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_events_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Calendar',
    'path' => 'calendar',
    'weight' => '0',
    'description' => 'The calendar lets you share events and meetings with your team.',
  );
  // Translatables
  array(
    t('Calendar'),
    t('The calendar lets you share events and meetings with your team.'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: create event content
  $permissions[] = array(
    'name' => 'create event content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own event content
  $permissions[] = array(
    'name' => 'delete own event content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own event content
  $permissions[] = array(
    'name' => 'edit own event content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override event promote to front page option
  $permissions[] = array(
    'name' => 'override event promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override event published option
  $permissions[] = array(
    'name' => 'override event published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override event revision option
  $permissions[] = array(
    'name' => 'override event revision option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override event sticky option
  $permissions[] = array(
    'name' => 'override event sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}
