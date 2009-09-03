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
  );
  return $items;
}
