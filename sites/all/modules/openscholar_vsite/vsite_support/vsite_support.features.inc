<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_support_context_default_contexts() {
  $items = array();

  $items['cp-section-support'] = array(
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
