<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _vsite_support_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'cp',
    'attribute' => 'section',
    'value' => 'support',
    'description' => '',
    'node' => array(
      '0' => 'feature_request',
      '1' => 'support_question',
    ),
    'views' => array(
      '0' => 'vsite_support_faq',
      '1' => 'vsite_support_feature_reqs',
    ),
    'block' => array(
      'views_2a17815f62da05b62035d31b9de3c969' => array(
        'module' => 'views',
        'delta' => '2a17815f62da05b62035d31b9de3c969',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'Feature Requests: Moste voted',
        'type' => 'context_ui',
      ),
      'views_vsite_support_faq-block_1' => array(
        'module' => 'views',
        'delta' => 'vsite_support_faq-block_1',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'Best questions',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}
