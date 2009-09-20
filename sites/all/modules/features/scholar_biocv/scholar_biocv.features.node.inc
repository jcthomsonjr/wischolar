<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_biocv_node_info() {
  $items = array(
    'bio' => array(
      'name' => t('bio'),
      'module' => 'features',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Bio'),
    ),
    'cv' => array(
      'name' => t('cv'),
      'module' => 'features',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('cv'),
    ),
  );
  return $items;
}
