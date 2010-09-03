<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _vsite_node_info() {
  $items = array(
    'vsite' => array(
      'name' => t('Scholar site'),
      'module' => 'features',
      'description' => t('Represent a Virtual Web Site'),
      'has_title' => '1',
      'title_label' => t('Site title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
