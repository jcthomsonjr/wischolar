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
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'embedfilter',
        'delta' => '0',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'oembed',
        'delta' => '0',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-6',
      ),
    ),
  );

  return $formats;
}
