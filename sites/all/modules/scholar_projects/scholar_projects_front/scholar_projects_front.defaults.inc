<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_projects_front_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar_projects',
    'attribute' => 'feature',
    'value' => 'front',
    'description' => 'Scholar projects front section',
    'path' => array(
      '<front>' => '<front>',
    ),
    'block' => array(
      'scholar_projects_front_0' => array(
        'module' => 'scholar_projects_front',
        'delta' => '0',
        'weight' => 20,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'row 1',
        'type' => 'context_ui',
      ),
      'scholar_projects_front_1' => array(
        'module' => 'scholar_projects_front',
        'delta' => '1',
        'weight' => 21,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'row 2',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}
