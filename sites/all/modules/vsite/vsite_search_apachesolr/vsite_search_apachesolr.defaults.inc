<?php

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