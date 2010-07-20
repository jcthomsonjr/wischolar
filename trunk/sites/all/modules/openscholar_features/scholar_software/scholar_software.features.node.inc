<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_software_node_info() {
  $items = array(
    'scholar_software_project' => array(
      'name' => t('Software Project'),
      'module' => 'features',
      'description' => t('A software project page. Provides a summary of project information and releases for download.'),
      'has_title' => '1',
      'title_label' => t('Project'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'scholar_software_release' => array(
      'name' => t('Software Release'),
      'module' => 'features',
      'description' => t('A single release package for a project.'),
      'has_title' => '1',
      'title_label' => t('Release'),
      'has_body' => '1',
      'body_label' => t('Notes'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
