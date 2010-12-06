<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_profiles_context_default_contexts() {
  $items = array();

  $items['scholar-feature-profiles'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'profiles',
    'description' => 'scholar > profiles',
    'node' => array(
      '0' => 'person',
    ),
    'menu_trail' => array(
      'people' => 'people',
    ),
    'views' => array(
      '0' => 'scholar_profiles',
    ),
    'menu' => 'people',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 20,
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
 * Implementation of hook_node_info().
 */
function scholar_profiles_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'module' => 'features',
      'description' => t('Represents a profile / person'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Short bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_profiles_views_api() {
  return array(
    'api' => '2',
  );
}
