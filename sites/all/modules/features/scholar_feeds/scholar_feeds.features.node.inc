<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_feeds_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Feed'),
      'module' => 'node',
      'description' => t('Items from these feeds will be turned into nodes.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
    'feed_item' => array(
      'name' => t('Feed item'),
      'module' => 'node',
      'description' => t('An item from the subscribed feed'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}
