<?php

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _scholar_project_imagecache_default_presets() {
  $items = array(
    'scholar_project_front_logo' => array(
      'presetname' => 'scholar_project_front_logo',
      'actions' => array(
        '0' => array(
          'actionid' => '1',
          'presetid' => '1',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
          ),
        ),
      ),
    ),
  );
  return $items;
}
