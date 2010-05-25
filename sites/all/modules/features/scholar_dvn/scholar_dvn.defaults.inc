<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_dvn_context_default_contexts() {
  $items = array();

  $items[] = array(
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

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_dvn_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Dataverse',
    'path' => 'data',
    'weight' => '0',
  );
  // Translatables
  array(
    t('Dataverse'),
  );


  return $items;
}
