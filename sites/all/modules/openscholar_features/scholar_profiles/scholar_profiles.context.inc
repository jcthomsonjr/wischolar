<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_profiles_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-profiles';
  $context->description = 'People Profiles';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        0 => 'person',
      ),
      'options' => array(),
    ),
    'menu' => array(
      'values' => array(
        'people' => 'people',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        0 => 'scholar_profiles',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'people',
    'block' => array(
      'blocks' => array(
        'vsite_taxonomy-0' => array(
          'module' => 'vsite_taxonomy',
          'delta' => '0',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Categories',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('scholar > profiles');

  $export['openscholar-feature-profiles'] = $context;
  return $export;
}
