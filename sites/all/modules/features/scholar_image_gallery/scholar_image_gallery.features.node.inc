<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_image_gallery_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Gallery'),
      'module' => 'node',
      'description' => t('A gallery for a collection of photos.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
    ),
    'image' => array(
      'name' => t('Image'),
      'module' => 'node',
      'description' => t('An individual gallery photograph.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
    ),
  );
  return $items;
}
