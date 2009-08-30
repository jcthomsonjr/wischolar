<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_classes_node_info() {
  $items = array(
    'scholar_class' => array(
      'name' => t('Class'),
      'module' => 'node',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}
