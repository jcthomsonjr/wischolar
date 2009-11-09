<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_announcements_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'module' => 'features',
      'description' => t('Manage announcements in your web site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}
