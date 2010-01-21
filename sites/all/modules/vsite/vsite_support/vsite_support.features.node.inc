<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _vsite_support_node_info() {
  $items = array(
    'feature_request' => array(
      'name' => t('Feature request'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'support_answer' => array(
      'name' => t('Answer'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'support_question' => array(
      'name' => t('Question'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Question'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
