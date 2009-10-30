<?php

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_dvn_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Data',
    'path' => 'data',
    'weight' => '0',
  );
  // Translatables
  array(
    t('Data'),
  );


  return $items;
}
