<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _openscholar_front_node_info() {
  $items = array(
    'sitewide_page' => array(
      'name' => t('Sitewide Page'),
      'module' => 'features',
      'description' => t('A page which can be shown sitewide on an OpenScholar installation, not specific to a vsite.'),
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
