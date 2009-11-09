<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_links_node_info() {
  $items = array(
    'link' => array(
      'name' => t('Link'),
      'module' => 'features',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => t(''),
    ),
  );
  return $items;
}
