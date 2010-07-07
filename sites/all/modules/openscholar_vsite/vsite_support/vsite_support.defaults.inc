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
    'path' => array(
      'cp/support/*' => 'cp/support/*',
    ),
  );
  return $items;
}
