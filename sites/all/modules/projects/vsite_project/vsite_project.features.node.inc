<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _vsite_project_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project Web Site'),
      'module' => 'features',
      'description' => t('Represents a Project Web Site'),
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
