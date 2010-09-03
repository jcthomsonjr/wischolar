<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_biocv_node_info() {
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
