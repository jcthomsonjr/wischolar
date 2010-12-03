<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_biocv_context_default_contexts() {
  $items = array();

  $items['scholar-feature-biocv'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'biocv',
    'description' => 'scholar > biocv',
    'path' => array(
      'biocv' => 'biocv',
    ),
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => -20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar site categories',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function scholar_biocv_node_info() {
  $items = array(
    'bio' => array(
      'name' => t('bio'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'cv' => array(
      'name' => t('cv'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('cv'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
