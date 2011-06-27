<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_image_gallery_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-image_gallery';
  $context->description = 'Image Galleries';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'gallery' => 'gallery',
        'image' => 'image',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'images' => 'images',
        'images/*' => 'images/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_image_gallery:page_1' => 'scholar_image_gallery:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'photos',
    'block' => array(
      'blocks' => array(
        'views-scholar_image_gallery-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_image_gallery-block_1',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Recent images',
          'type' => 'context_ui',
        ),
        'vsite_taxonomy-0' => array(
          'module' => 'vsite_taxonomy',
          'delta' => '0',
          'weight' => -20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Scholar site categories',
          'type' => 'context_ui',
        ),
        'vsite_widgets-2' => array(
          'module' => 'vsite_widgets',
          'delta' => '2',
          'weight' => 50,
          'region' => 'right',
          'status' => '0',
          'label' => 'AddThis Button - Share posts using popular services',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Image Galleries');

  $export['openscholar-feature-image_gallery'] = $context;
  return $export;
}
