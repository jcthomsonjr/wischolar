<?php

/**
 * Implementation of hook_filter_default_formats().
 */
function os_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML
  $formats['Filtered HTML'] = array(
    'name' => 'Filtered HTML',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'oembed',
        'delta' => '0',
        'weight' => '-8',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-7',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-6',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '10',
      ),
    ),
  );

  return $formats;
}
