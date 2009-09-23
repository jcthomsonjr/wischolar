<?php

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _iqss_project_imagecache_default_presets() {
  $items = array(
    'iqss_project_front_logo' => array(
      'presetname' => 'iqss_project_front_logo',
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
