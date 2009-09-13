<?php

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _vsite_imagecache_default_presets(){
  $presets = array();
  $presets['vsite_image_teaser_thumb'] = array(
    'presetname' => 'vsite_image_teaser_thumb', 
    'actions' => array(
      0 => array(
        'weight' => '0', 
        'module' => 'imagecache', 
        'action' => 'imagecache_scale', 
        'data' => array(
          'width' => '', 
          'height' => '150', 
          'upscale' => 0 
        ) 
      ) 
    ) 
  );
  $presets['vsite_image_page_thumb'] = array(
    'presetname' => 'vsite_image_teaser_thumb', 
    'actions' => array(
      0 => array(
        'weight' => '0', 
        'module' => 'imagecache', 
        'action' => 'imagecache_scale', 
        'data' => array(
          'width' => '', 
          'height' => '250', 
          'upscale' => 0 
        ) 
      ) 
    ) 
  );
  return $presets;
}
