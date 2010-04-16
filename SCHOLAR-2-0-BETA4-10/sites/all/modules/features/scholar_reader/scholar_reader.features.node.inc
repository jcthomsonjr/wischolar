<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_reader_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Feed'),
      'module' => 'features',
      'description' => t('Items from these feeds will be turned into nodes.'),
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
