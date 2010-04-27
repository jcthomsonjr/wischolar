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

/**
 * Helper to implementation of hook_strongarm().
 */
function _vsite_search_apachesolr_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:limit';
  $strongarm->value = '0';
  $export['luceneapi_facet:luceneapi_node:limit'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:cache_threshold';
  $strongarm->value = '5000';
  $export['luceneapi_node:cache_threshold'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:caching_enabled';
  $strongarm->value = '1';
  $export['luceneapi_node:caching_enabled'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:default_operator';
  $strongarm->value = '1';
  $export['luceneapi_node:default_operator'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:hide_core_search';
  $strongarm->value = '1';
  $export['luceneapi_node:hide_core_search'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:nodeaccess';
  $strongarm->value = '1';
  $export['luceneapi_node:nodeaccess'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:optimize_on_update';
  $strongarm->value = '1';
  $export['luceneapi_node:optimize_on_update'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:resultset_limit';
  $strongarm->value = '0';
  $export['luceneapi_node:resultset_limit'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:results_per_page';
  $strongarm->value = '20';
  $export['luceneapi_node:results_per_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:update_limit';
  $strongarm->value = '100';
  $export['luceneapi_node:update_limit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi:default_search';
  $strongarm->value = 'luceneapi_node';
  $export['luceneapi:default_search'] = $strongarm;
	
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi:min_word_length';
  $strongarm->value = '0';
  $export['luceneapi:min_word_length'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:fieldset:expand';
  $strongarm->value = '0';
  $export['luceneapi_facet:luceneapi_node:fieldset:expand'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi:permissions_group';
  $strongarm->value = '6';
  $export['luceneapi:permissions_group'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi:permissions_other';
  $strongarm->value = '4';
  $export['luceneapi:permissions_other'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:hard_limit';
  $strongarm->value = '20';
  $export['luceneapi_facet:luceneapi_node:hard_limit'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:block';
  $strongarm->value = array(
    'uid' => 'uid',
    'type' => 'type',
    'category' => 'category',
    'original_keys' => 'original_keys',
  );
  $export['luceneapi_facet:luceneapi_node:block'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:fieldset';
  $strongarm->value = array(
    'uid' => 'uid',
    'type' => 'type',
    'original_keys' => 'original_keys',
  );
  $export['luceneapi_facet:luceneapi_node:fieldset'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:excluded_types';
  $strongarm->value = array(
    'project' => 'project',
    'vsite' => 'vsite',
    'announcement' => 0,
    'support_answer' => 0,
    'blog' => 0,
    'book' => 0,
    'class' => 0,
    'class_material' => 0,
    'event' => 0,
    'feature_request' => 0,
    'feed' => 0,
    'gallery' => 0,
    'image' => 0,
    'page' => 0,
    'person' => 0,
    'profile' => 0,
    'biblio' => 0,
    'support_question' => 0,
    'scholar_sofware_project' => 0,
    'scholar_software_release' => 0,
    'vsite_users_profile' => 0,
  );
  $export['luceneapi_node:excluded_types'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:empty';
  $strongarm->value = array(
    'no_results' => 0,
    'no_search' => 0,
    'counts' => 0,
  );
  $export['luceneapi_facet:luceneapi_node:empty'] = $strongarm;
  return $export;
}