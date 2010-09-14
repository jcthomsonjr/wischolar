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
  $items = array();
  $items[] = array(
    'namespace' => 'vsite',
    'attribute' => 'search',
    'value' => 'apachesolr_search',
    'description' => 'Context for searches performed through Apache Solr',
    'path' => array(
      'search/apachesolr_search' => 'search/apachesolr_search',
      'search/apachesolr_search/*' => 'search/apachesolr_search/*',
    ),
    'block' => array(
      'vsite_search_apachesolr_0' => array(
        'module' => 'vsite_search_apachesolr',
        'delta' => '0',
        'weight' => 44,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories',
        'type' => 'context_ui',
      ),
      'apachesolr_mlt-001' => array(
        'module' => 'apachesolr',
        'delta' => 'mlt-001',
        'weight' => 45,
        'region' => 'right',
        'status' => '0',
        'label' => 'Apache Solr recommendations: More like this',
        'type' => 'context_ui',
      ),
      'apachesolr_search_currentsearch' => array(
        'module' => 'apachesolr_search',
        'delta' => 'currentsearch',
        'weight' => 46,
        'region' => 'right',
        'status' => '0',
        'label' => 'Apache Solr Search: Current search',
        'type' => 'context_ui',
      ),
      'apachesolr_sort' => array(
        'module' => 'apachesolr',
        'delta' => 'sort',
        'weight' => 47,
        'region' => 'right',
        'status' => '0',
        'label' => 'Apache Solr Core: Sorting',
        'type' => 'context_ui',
      ),
      'apachesolr_search_type' => array(
        'module' => 'apachesolr_search',
        'delta' => 'type',
        'weight' => 48,
        'region' => 'right',
        'status' => '0',
        'label' => 'Node attribute: Filter by content type',
        'type' => 'context_ui',
      ),
      'apachesolr_og_im_og_gid' => array(
        'module' => 'apachesolr_og',
        'delta' => 'im_og_gid',
        'weight' => 49,
        'region' => 'right',
        'status' => '0',
        'label' => 'Apache Solr OG: Filter by Organic Group',
        'type' => 'context_ui',
      ),
      'apachesolr_biblio_ss_biblio_type_of_work' => array(
        'module' => 'apachesolr_biblio',
        'delta' => 'ss_biblio_type_of_work',
        'weight' => 50,
        'region' => 'right',
        'status' => '0',
        'label' => 'Biblio: Filter by Type of Work',
        'type' => 'context_ui',
      ),
      'apachesolr_search_uid' => array(
        'module' => 'apachesolr_search',
        'delta' => 'uid',
        'weight' => 51,
        'region' => 'right',
        'status' => '0',
        'label' => 'Node attribute: Filter by author',
        'type' => 'context_ui',
      ),
      'apachesolr_biblio_sm_biblio_contributors' => array(
        'module' => 'apachesolr_biblio',
        'delta' => 'sm_biblio_contributors',
        'weight' => 52,
        'region' => 'right',
        'status' => '0',
        'label' => 'Biblio: Filter by Citation Contributor',
        'type' => 'context_ui',
      ),
      'apachesolr_biblio_ss_biblio_publisher' => array(
        'module' => 'apachesolr_biblio',
        'delta' => 'ss_biblio_publisher',
        'weight' => 53,
        'region' => 'right',
        'status' => '0',
        'label' => 'Biblio: Filter by Publisher',
        'type' => 'context_ui',
      ),
      'apachesolr_biblio_ss_biblio_secondary_title' => array(
        'module' => 'apachesolr_biblio',
        'delta' => 'ss_biblio_secondary_title',
        'weight' => 54,
        'region' => 'right',
        'status' => '0',
        'label' => 'Biblio: Filter by Secondary Title',
        'type' => 'context_ui',
      ),
      'apachesolr_biblio_ss_biblio_year' => array(
        'module' => 'apachesolr_biblio',
        'delta' => 'ss_biblio_year',
        'weight' => 55,
        'region' => 'right',
        'status' => '0',
        'label' => 'Biblio: Filter by Year of Publication',
        'type' => 'context_ui',
      ),
    ),
  );
  
  return $items;
}

function _vsite_search_apachesolr_default_biblio_fields() {
  $fields = array();
  // Exported field: "biblio_refereed".
  $fields[] = array(
    'fid' => '53',
    'name' => 'biblio_refereed',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_access_date".
  $fields[] = array(
    'fid' => '52',
    'name' => 'biblio_access_date',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_auth_address".
  $fields[] = array(
    'fid' => '48',
    'name' => 'biblio_auth_address',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_label".
  $fields[] = array(
    'fid' => '51',
    'name' => 'biblio_label',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_remote_db_provider".
  $fields[] = array(
    'fid' => '50',
    'name' => 'biblio_remote_db_provider',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_remote_db_name".
  $fields[] = array(
    'fid' => '49',
    'name' => 'biblio_remote_db_name',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_coins".
  $fields[] = array(
    'fid' => '45',
    'name' => 'biblio_coins',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_citekey".
  $fields[] = array(
    'fid' => '44',
    'name' => 'biblio_citekey',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_reprint_edition".
  $fields[] = array(
    'fid' => '42',
    'name' => 'biblio_reprint_edition',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_original_publication".
  $fields[] = array(
    'fid' => '41',
    'name' => 'biblio_original_publication',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_translated_title".
  $fields[] = array(
    'fid' => '40',
    'name' => 'biblio_translated_title',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_alternate_title".
  $fields[] = array(
    'fid' => '39',
    'name' => 'biblio_alternate_title',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_short_title".
  $fields[] = array(
    'fid' => '38',
    'name' => 'biblio_short_title',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom7".
  $fields[] = array(
    'fid' => '36',
    'name' => 'biblio_custom7',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom6".
  $fields[] = array(
    'fid' => '35',
    'name' => 'biblio_custom6',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom5".
  $fields[] = array(
    'fid' => '34',
    'name' => 'biblio_custom5',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom4".
  $fields[] = array(
    'fid' => '33',
    'name' => 'biblio_custom4',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom3".
  $fields[] = array(
    'fid' => '32',
    'name' => 'biblio_custom3',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom2".
  $fields[] = array(
    'fid' => '31',
    'name' => 'biblio_custom2',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_custom1".
  $fields[] = array(
    'fid' => '30',
    'name' => 'biblio_custom1',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_research_notes".
  $fields[] = array(
    'fid' => '29',
    'name' => 'biblio_research_notes',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_doi".
  $fields[] = array(
    'fid' => '47',
    'name' => 'biblio_doi',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_url".
  $fields[] = array(
    'fid' => '26',
    'name' => 'biblio_url',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_notes".
  $fields[] = array(
    'fid' => '27',
    'name' => 'biblio_notes',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_abst_f".
  $fields[] = array(
    'fid' => '23',
    'name' => 'biblio_abst_f',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_keywords".
  $fields[] = array(
    'fid' => '24',
    'name' => 'biblio_keywords',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_other_number".
  $fields[] = array(
    'fid' => '11',
    'name' => 'biblio_other_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_call_number".
  $fields[] = array(
    'fid' => '10',
    'name' => 'biblio_call_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_accession_number".
  $fields[] = array(
    'fid' => '8',
    'name' => 'biblio_accession_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_issn".
  $fields[] = array(
    'fid' => '46',
    'name' => 'biblio_issn',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_isbn".
  $fields[] = array(
    'fid' => '9',
    'name' => 'biblio_isbn',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_lang".
  $fields[] = array(
    'fid' => '21',
    'name' => 'biblio_lang',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_type_of_work".
  $fields[] = array(
    'fid' => '25',
    'name' => 'biblio_type_of_work',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_place_published".
  $fields[] = array(
    'fid' => '14',
    'name' => 'biblio_place_published',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_publisher".
  $fields[] = array(
    'fid' => '13',
    'name' => 'biblio_publisher',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_date".
  $fields[] = array(
    'fid' => '20',
    'name' => 'biblio_date',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_pages".
  $fields[] = array(
    'fid' => '19',
    'name' => 'biblio_pages',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_number".
  $fields[] = array(
    'fid' => '18',
    'name' => 'biblio_number',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_issue".
  $fields[] = array(
    'fid' => '28',
    'name' => 'biblio_issue',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_number_of_volumes".
  $fields[] = array(
    'fid' => '37',
    'name' => 'biblio_number_of_volumes',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_section".
  $fields[] = array(
    'fid' => '43',
    'name' => 'biblio_section',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_edition".
  $fields[] = array(
    'fid' => '16',
    'name' => 'biblio_edition',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_volume".
  $fields[] = array(
    'fid' => '17',
    'name' => 'biblio_volume',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_tertiary_title".
  $fields[] = array(
    'fid' => '7',
    'name' => 'biblio_tertiary_title',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_secondary_title".
  $fields[] = array(
    'fid' => '6',
    'name' => 'biblio_secondary_title',
    'index_type' => 'string',
    'indexed' => '1',
  );
  // Exported field: "biblio_abst_e".
  $fields[] = array(
    'fid' => '22',
    'name' => 'biblio_abst_e',
    'index_type' => 'string',
    'indexed' => '0',
  );
  // Exported field: "biblio_year".
  $fields[] = array(
    'fid' => '15',
    'name' => 'biblio_year',
    'index_type' => 'string',
    'indexed' => '1',
  );
  return $fields;
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
