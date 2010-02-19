<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_reader_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'reader',
    'description' => 'scholar > feed reader',
    'node' => array(
      '0' => 'feed',
    ),
    'menu_trail' => array(
      'reader' => 'reader',
    ),
    'views' => array(
      '0' => 'scholar_reader',
    ),
    'menu' => 'reader',
    'block' => array(
      'vsite_widgets_2' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 20,
        'region' => 'left',
        'status' => '0',
        'label' => 'AddThis button',
        'type' => 'context_ui',
      ),
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories',
        'type' => 'context_ui',
      ),
      'views_scholar_reader-block_2' => array(
        'module' => 'views',
        'delta' => 'scholar_reader-block_2',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_reader: Latest feed items',
        'type' => 'context_ui',
      ),
      'views_scholar_reader-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_reader-block_1',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_reader: Feeds subscriptions',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _scholar_reader_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "data" && $api == "data_default") {
    return array("version" => 1);
  }
  else if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_data_default().
 */
function _scholar_reader_data_default() {
  $export = array();
  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'scholar_feed_importer';
  $data_table->name = 'feeds_data_scholar_feed_importer';
  $data_table->table_schema = array(
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'timestamp' => array(
        'description' => 'The Unix timestamp for the data.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
      ),
      'description' => array(
        'type' => 'text',
        'size' => 'normal',
      ),
      'guid' => array(
        'type' => 'text',
        'size' => 'normal',
      ),
      'url' => array(
        'type' => 'text',
        'size' => 'normal',
      ),
    ),
    'indexes' => array(
      'feed_nid' => array(
        '0' => 'feed_nid',
      ),
      'id' => array(
        '0' => 'id',
      ),
      'timestamp' => array(
        '0' => 'timestamp',
      ),
      'guid' => array(
        '0' => array(
          '0' => 'guid',
          '1' => 255,
        ),
      ),
      'url' => array(
        '0' => array(
          '0' => 'url',
          '1' => 255,
        ),
      ),
    ),
    'primary key' => array(
      '0' => 'id',
    ),
  );
  $data_table->meta = array(
    'join' => array(
      'node' => array(
        'left_field' => 'nid',
        'field' => 'feed_nid',
        'inner_join' => '0',
      ),
    ),
    'fields' => array(
      'title' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'description' => array(
        'label' => '',
        'views_field_handler' => 'scholar_reader_handler_field_description',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'guid' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'url' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'feed_nid' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'id' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'timestamp' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort_date',
      ),
    ),
    'data_node' => array(
      'content_type' => 'feed',
      'id' => 'feed_nid',
    ),
  );

  $export['feeds_data_scholar_feed_importer'] = $data_table;
  return $export;
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _scholar_reader_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'scholar_feed_importer';
  $feeds_importer->config = array(
    'name' => 'scholar_feed_importer',
    'description' => 'scholar feed reader importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 0,
        'expire' => '2419200',
        'mappings' => array(
          '0' => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          '1' => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => 0,
          ),
          '2' => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          '3' => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          '4' => array(
            'source' => 'timestamp',
            'target' => 'timestamp',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['scholar_feed_importer'] = $feeds_importer;
  return $export;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_reader_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Feeds',
    'path' => 'reader',
    'weight' => '0',
    'description' => 'Feed reader',
  );
  // Translatables
  array(
    t('Feed reader'),
    t('Feeds'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_reader_user_default_permissions() {
  $permissions = array();

  // Exported permission: create feed content
  $permissions[] = array(
    'name' => 'create feed content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: delete own feed content
  $permissions[] = array(
    'name' => 'delete own feed content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own feed content
  $permissions[] = array(
    'name' => 'edit own feed content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override feed promote to front page option
  $permissions[] = array(
    'name' => 'override feed promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override feed published option
  $permissions[] = array(
    'name' => 'override feed published option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override feed revision option
  $permissions[] = array(
    'name' => 'override feed revision option',
    'roles' => array(),
  );

  // Exported permission: override feed sticky option
  $permissions[] = array(
    'name' => 'override feed sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
