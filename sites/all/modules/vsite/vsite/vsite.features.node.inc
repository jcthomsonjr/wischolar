<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _vsite_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('An html page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
    'vsite' => array(
      'name' => t('Scholar site'),
      'module' => 'features',
      'description' => t('Represent a Virtual Web Site'),
      'has_title' => '1',
      'title_label' => t('Site title'),
      'has_body' => '0',
      'body_label' => t(''),
    ),
  );
  return $items;
}
