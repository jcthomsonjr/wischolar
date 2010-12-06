<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_dvn_context_default_contexts() {
  $items = array();

  $items['scholar-feature-dvn'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'dvn',
    'description' => 'Datverse Feature Context',
    'menu_trail' => array(
      'data' => 'data',
    ),
  );
  return $items;
}
