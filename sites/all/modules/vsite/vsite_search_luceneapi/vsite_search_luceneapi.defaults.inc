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

function _vsite_search_luceneapi_luceneapi_biblio_default_fields() {
  $fields = array();
  // Exported field: "biblio_refereed".
  $fields[] = array (
    'fid' => '53',
    'name' => 'biblio_refereed',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_access_date".
  $fields[] = array (
    'fid' => '52',
    'name' => 'biblio_access_date',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_auth_address".
  $fields[] = array (
    'fid' => '48',
    'name' => 'biblio_auth_address',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_label".
  $fields[] = array (
    'fid' => '51',
    'name' => 'biblio_label',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_remote_db_provider".
  $fields[] = array (
    'fid' => '50',
    'name' => 'biblio_remote_db_provider',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_remote_db_name".
  $fields[] = array (
    'fid' => '49',
    'name' => 'biblio_remote_db_name',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_coins".
  $fields[] = array (
    'fid' => '45',
    'name' => 'biblio_coins',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_citekey".
  $fields[] = array (
    'fid' => '44',
    'name' => 'biblio_citekey',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_reprint_edition".
  $fields[] = array (
    'fid' => '42',
    'name' => 'biblio_reprint_edition',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_original_publication".
  $fields[] = array (
    'fid' => '41',
    'name' => 'biblio_original_publication',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_translated_title".
  $fields[] = array (
    'fid' => '40',
    'name' => 'biblio_translated_title',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_alternate_title".
  $fields[] = array (
    'fid' => '39',
    'name' => 'biblio_alternate_title',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_short_title".
  $fields[] = array (
    'fid' => '38',
    'name' => 'biblio_short_title',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom7".
  $fields[] = array (
    'fid' => '36',
    'name' => 'biblio_custom7',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom6".
  $fields[] = array (
    'fid' => '35',
    'name' => 'biblio_custom6',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom5".
  $fields[] = array (
    'fid' => '34',
    'name' => 'biblio_custom5',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom4".
  $fields[] = array (
    'fid' => '33',
    'name' => 'biblio_custom4',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom3".
  $fields[] = array (
    'fid' => '32',
    'name' => 'biblio_custom3',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom2".
  $fields[] = array (
    'fid' => '31',
    'name' => 'biblio_custom2',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom1".
  $fields[] = array (
    'fid' => '30',
    'name' => 'biblio_custom1',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_research_notes".
  $fields[] = array (
    'fid' => '29',
    'name' => 'biblio_research_notes',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_doi".
  $fields[] = array (
    'fid' => '47',
    'name' => 'biblio_doi',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_url".
  $fields[] = array (
    'fid' => '26',
    'name' => 'biblio_url',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_notes".
  $fields[] = array (
    'fid' => '27',
    'name' => 'biblio_notes',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_abst_f".
  $fields[] = array (
    'fid' => '23',
    'name' => 'biblio_abst_f',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_keywords".
  $fields[] = array (
    'fid' => '24',
    'name' => 'biblio_keywords',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_other_number".
  $fields[] = array (
    'fid' => '11',
    'name' => 'biblio_other_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_call_number".
  $fields[] = array (
    'fid' => '10',
    'name' => 'biblio_call_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_accession_number".
  $fields[] = array (
    'fid' => '8',
    'name' => 'biblio_accession_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_issn".
  $fields[] = array (
    'fid' => '46',
    'name' => 'biblio_issn',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_isbn".
  $fields[] = array (
    'fid' => '9',
    'name' => 'biblio_isbn',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_lang".
  $fields[] = array (
    'fid' => '21',
    'name' => 'biblio_lang',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_type_of_work".
  $fields[] = array (
    'fid' => '25',
    'name' => 'biblio_type_of_work',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_place_published".
  $fields[] = array (
    'fid' => '14',
    'name' => 'biblio_place_published',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_publisher".
  $fields[] = array (
    'fid' => '13',
    'name' => 'biblio_publisher',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_date".
  $fields[] = array (
    'fid' => '20',
    'name' => 'biblio_date',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_pages".
  $fields[] = array (
    'fid' => '19',
    'name' => 'biblio_pages',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_number".
  $fields[] = array (
    'fid' => '18',
    'name' => 'biblio_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_issue".
  $fields[] = array (
    'fid' => '28',
    'name' => 'biblio_issue',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_number_of_volumes".
  $fields[] = array (
    'fid' => '37',
    'name' => 'biblio_number_of_volumes',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_section".
  $fields[] = array (
    'fid' => '43',
    'name' => 'biblio_section',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_edition".
  $fields[] = array (
    'fid' => '16',
    'name' => 'biblio_edition',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_volume".
  $fields[] = array (
    'fid' => '17',
    'name' => 'biblio_volume',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_tertiary_title".
  $fields[] = array (
    'fid' => '7',
    'name' => 'biblio_tertiary_title',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_secondary_title".
  $fields[] = array (
    'fid' => '6',
    'name' => 'biblio_secondary_title',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_abst_e".
  $fields[] = array (
    'fid' => '22',
    'name' => 'biblio_abst_e',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_year".
  $fields[] = array (
    'fid' => '15',
    'name' => 'biblio_year',
    'index_type' => 'string',
    'indexed' => '1',
  );
  return $fields;
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