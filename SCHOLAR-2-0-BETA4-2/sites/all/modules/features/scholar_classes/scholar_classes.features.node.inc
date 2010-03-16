<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_classes_node_info() {
  $items = array(
    'class' => array(
      'name' => t('Class'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'class_material' => array(
      'name' => t('Class Material'),
      'module' => 'features',
      'description' => t('A post related to a class'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
