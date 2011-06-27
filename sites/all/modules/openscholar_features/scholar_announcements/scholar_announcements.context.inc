<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_announcements_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-announcements';
  $context->description = 'Announcements';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'announcement' => 'announcement',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'scholar_announcements:page_1' => 'scholar_announcements:page_1',
      ),
      'options' => array(),
    ),
    'path' => array(
      'values' => array(
        'announcements' => 'announcements',
        'announcements/*' => 'announcements/*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'announcements',
    'block' => array(
      'blocks' => array(
        'views-scholar_announcements-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_announcements-block_1',
          'weight' => -21,
          'region' => 'right',
          'status' => '0',
          'label' => 'Latest Announcements',
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
  t('Announcements');
  t('Feature');

  $export['openscholar-feature-announcements'] = $context;
  return $export;
}
