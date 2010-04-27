<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _vsite_search_apachesolr_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "context" && $api == "context") {
    return array("version" => 2);
  }
  else if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_search_apachesolr_user_default_permissions() {
  $permissions = array();

  // Exported permission: search content
  $permissions[] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: use advanced search
  $permissions[] = array(
    'name' => 'use advanced search',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}

/**
 * hook context_default_contexts
 * @return unknown_type
 */
function _vsite_search_apachesolr_context_default_contexts() {
  $items = array ();
  $items[0] = array(
    'namespace' => 'vsite',
    'attribute' => 'search',
    'value' => 'apachesolr_search',
    'system' => 0,
    'description' => 'Context for searches performed through Apache Solr',
    'path' => array(
      'search/apachesolr_search' => 'search/apachesolr_search',
      'search/apachesolr_search/*' => 'search/apachesolr_search/*',
    ),
    'block' => array(
      // Cast as an object instead of using stdClass::__set_state() - http://drupal.org/node/584672
      'apachesolr_mlt-001' => (object)(array(
         'module' => 'apachesolr',
         'delta' => 'mlt-001',
         'weight' => 20,
         'region' => 'right',
         'status' => '0',
         'label' => 'Apache Solr recommendations: More like this',
         'type' => 'context_ui',
         'bid' => 'apachesolr_mlt-001',
      )),
      'apachesolr_sort' => (object)(array(
         'module' => 'apachesolr',
         'delta' => 'sort',
         'weight' => 21,
         'region' => 'right',
         'status' => '0',
         'label' => 'Apache Solr Core: Sorting',
         'type' => 'context_ui',
         'bid' => 'apachesolr_sort',
      )),
      'apachesolr_search_changed' => (object)(array(
         'module' => 'apachesolr_search',
         'delta' => 'changed',
         'weight' => 22,
         'region' => 'right',
         'status' => '0',
         'label' => 'Apache Solr Search: Filter by updated date',
         'type' => 'context_ui',
         'bid' => 'apachesolr_search_changed',
      )),
      'apachesolr_search_currentsearch' => (object)(array(
         'module' => 'apachesolr_search',
         'delta' => 'currentsearch',
         'weight' => 23,
         'region' => 'right',
         'status' => '0',
         'label' => 'Apache Solr Search: Current search',
         'type' => 'context_ui',
         'bid' => 'apachesolr_search_currentsearch',
      )),
      'apachesolr_search_type' => (object)(array(
         'module' => 'apachesolr_search',
         'delta' => 'type',
         'weight' => 30,
         'region' => 'right',
         'status' => '0',
         'label' => 'Apache Solr Search: Filter by content type',
         'type' => 'context_ui',
         'bid' => 'apachesolr_search_type',
      )),
      'apachesolr_search_uid' => (object)(array(
         'module' => 'apachesolr_search',
         'delta' => 'uid',
         'weight' => 31,
         'region' => 'right',
         'status' => '0',
         'label' => 'Apache Solr Search: Filter by author',
         'type' => 'context_ui',
         'bid' => 'apachesolr_search_uid',
      )),
      'vsite_search_apachesolr_categories' => (object)(array(
        'module' => 'vsite_search_apachesolr',
        'delta' => '0',
        'weight' => 0,
        'region' => 'right',
        'status' => '0',
        'label' => t('Categories'),
        'type' => 'context_ui',
      )),
    ),
    'type' => 2,
    'status' => 1,
  );
  return $items;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _vsite_search_apachesolr_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_cron_limit';
  $strongarm->value = '50';
  $export['apachesolr_cron_limit'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_enabled_facets';
  $strongarm->value = array(
    'apachesolr_search' => array(
      'uid' => 'uid',
      'type' => 'type',
      'created' => 'created',
    ),
  );
  $export['apachesolr_enabled_facets'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_failure';
  $strongarm->value = 'show_error';
  $export['apachesolr_failure'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_og_groupnode';
  $strongarm->value = '0';
  $export['apachesolr_og_groupnode'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_read_only';
  $strongarm->value = '0';
  $export['apachesolr_read_only'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_rows';
  $strongarm->value = '10';
  $export['apachesolr_rows'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_default_previous';
  $strongarm->value = '0';
  $export['apachesolr_search_default_previous'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_make_default';
  $strongarm->value = '1';
  $export['apachesolr_search_make_default'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_spellcheck';
  $strongarm->value = 1;
  $export['apachesolr_search_spellcheck'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_taxonomy_links';
  $strongarm->value = '1';
  $export['apachesolr_search_taxonomy_links'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_taxonomy_previous';
  $strongarm->value = '0';
  $export['apachesolr_search_taxonomy_previous'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_set_nodeapi_messages';
  $strongarm->value = '1';
  $export['apachesolr_set_nodeapi_messages'] = $strongarm;

  return $export;
}