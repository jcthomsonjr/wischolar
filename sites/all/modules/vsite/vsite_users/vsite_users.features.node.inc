<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _vsite_users_node_info() {
  $items = array(
    'vsite_users_profile' => array(
      'name' => t('User Profile'),
      'module' => 'node',
      'description' => t('User Profile Information.'),
      'has_title' => '0',
      'title_label' => t(''),
      'has_body' => '0',
      'body_label' => t(''),
    ),
  );
  return $items;
}
