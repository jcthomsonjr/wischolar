<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_search_luceneapi_strongarm() {
  $export = array();
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi:min_word_length';
  $strongarm->value = 0;

  $export['luceneapi:min_word_length'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi:permissions_group';
  $strongarm->value = 6;

  $export['luceneapi:permissions_group'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi:permissions_other';
  $strongarm->value = 4;

  $export['luceneapi:permissions_other'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:fieldset:expand';
  $strongarm->value = 0;

  $export['luceneapi_facet:luceneapi_node:fieldset:expand'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:hard_limit';
  $strongarm->value = 20;

  $export['luceneapi_facet:luceneapi_node:hard_limit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:limit';
  $strongarm->value = 0;

  $export['luceneapi_facet:luceneapi_node:limit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:cache_threshold';
  $strongarm->value = 5000;

  $export['luceneapi_node:cache_threshold'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:caching_enabled';
  $strongarm->value = 1;

  $export['luceneapi_node:caching_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:default_operator';
  $strongarm->value = 1;

  $export['luceneapi_node:default_operator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:hide_core_search';
  $strongarm->value = 1;

  $export['luceneapi_node:hide_core_search'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:nodeaccess';
  $strongarm->value = 1;

  $export['luceneapi_node:nodeaccess'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:optimize_on_update';
  $strongarm->value = 1;

  $export['luceneapi_node:optimize_on_update'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:resultset_limit';
  $strongarm->value = 0;

  $export['luceneapi_node:resultset_limit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:results_per_page';
  $strongarm->value = 10;

  $export['luceneapi_node:results_per_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_node:update_limit';
  $strongarm->value = 100;

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
  $strongarm->name = 'luceneapi_facet:luceneapi_node:block';
  $strongarm->value = array(
    'author' => 'author',
    'type' => 'type',
    'category' => 'category',
    'original_keys' => 'original_keys',
    'im_og_gid' => 'im_og_gid',
  );

  $export['luceneapi_facet:luceneapi_node:block'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:fieldset';
  $strongarm->value = array(
    'author' => 'author',
    'type' => 'type',
    'original_keys' => 'original_keys',
  );

  $export['luceneapi_facet:luceneapi_node:fieldset'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'luceneapi_facet:luceneapi_node:block:original_keys:weight';
  $strongarm->value = -50;

  $export['luceneapi_facet:luceneapi_node:block:original_keys:weight'] = $strongarm;
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
