<?php

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
