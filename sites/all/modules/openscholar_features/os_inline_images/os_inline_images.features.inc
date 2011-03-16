<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function os_inline_images_imagecache_default_presets() {
  $items = array(
    'inline_default' => array(
      'presetname' => 'inline_default',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '190',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'inline_larger' => array(
      'presetname' => 'inline_larger',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '600',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}
