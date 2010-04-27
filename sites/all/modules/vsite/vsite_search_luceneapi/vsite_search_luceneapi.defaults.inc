<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_search_luceneapi_user_default_permissions() {
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
function _vsite_search_luceneapi_context_default_contexts() {
  $items = array ();
  $items[] = array(
    'namespace' => 'vsite',
    'attribute' => 'search',
    'value' => 'luceneapi_search',
    'description' => 'Context for searches performed through Search Lucene',
    'path' => array(
      'search/luceneapi_node' => 'search/luceneapi_node',
      'search/luceneapi_node/*' => 'search/luceneapi_node/*',
    ),
    'block' => array(
      'luceneapi_luceneapi_sort' => array(
        'module' => 'luceneapi',
        'delta' => 'luceneapi_sort',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Search Lucene API Sorting',
        'type' => 'context_ui',
      ),
      'luceneapi_facet_luceneapi_node' => array(
        'module' => 'luceneapi_facet',
        'delta' => 'luceneapi_node',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'Search Lucene Facets: Search Lucene',
        'type' => 'context_ui',
      ),
      'vsite_search_luceneapi_0' => array(
        'module' => 'vsite_search_luceneapi',
        'delta' => '0',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}