<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_presentations_node_info() {
  $items = array(
    'presentation' => array(
      'name' => t('Presentation'),
      'module' => 'features',
      'description' => t('A presentation event.'),
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
