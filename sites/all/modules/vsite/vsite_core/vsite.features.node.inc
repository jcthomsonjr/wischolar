<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _vsite_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'module' => 'node',
      'description' => t('An html page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}
