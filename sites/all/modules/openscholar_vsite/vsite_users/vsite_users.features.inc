<?php

/**
 * Implementation of hook_node_info().
 */
function vsite_users_node_info() {
  $items = array(
    'vsite_users_profile' => array(
      'name' => t('User Profile'),
      'module' => 'features',
      'description' => t('User Profile Information.'),
      'has_title' => '0',
      'title_label' => '',
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
