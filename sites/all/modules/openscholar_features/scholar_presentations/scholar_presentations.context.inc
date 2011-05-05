<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_presentations_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-presentations';
  $context->description = 'Presentations';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'presentation' => 'presentation',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'presentations' => 'presentations',
        'presentations/*' => 'presentations/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_presentations:page_1' => 'scholar_presentations:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'presentations',
    'block' => array(
      'blocks' => array(
        'views-scholar_presentations-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_presentations-block_1',
          'weight' => 38,
          'region' => 'right',
          'status' => '0',
          'label' => 'Recent Presentations',
          'type' => 'context_ui',
        ),
        'vsite_taxonomy-0' => array(
          'module' => 'vsite_taxonomy',
          'delta' => '0',
          'weight' => 39,
          'region' => 'right',
          'status' => '0',
          'label' => 'Categories - Filter categorized content',
          'type' => 'context_ui',
        ),
        'vsite_widgets-2' => array(
          'module' => 'vsite_widgets',
          'delta' => '2',
          'weight' => 40,
          'region' => 'right',
          'status' => '0',
          'label' => 'ShareThis Button - Allows you to share posts using popular online services',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Presentations');

  $export['openscholar-feature-presentations'] = $context;
  return $export;
}
