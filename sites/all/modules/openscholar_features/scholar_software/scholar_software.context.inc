<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_software_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-software';
  $context->description = 'Software and Software Releases';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        0 => 'scholar_software_project',
        1 => 'scholar_software_release',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        0 => 'scholar_software_projects',
        1 => 'scholar_software_releases',
        2 => 'scholar_software_updates',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'software',
    'block' => array(
      'blocks' => array(
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
          'label' => 'AddThis button',
          'type' => 'context_ui',
        ),
        'views-scholar_software_releases-block_3' => array(
          'module' => 'views',
          'delta' => 'scholar_software_releases-block_3',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Software Releases',
          'type' => 'context_ui',
        ),
        'views-scholar_software_releases-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_software_releases-block_1',
          'weight' => 20,
          'region' => FALSE,
          'status' => '0',
          'label' => 'Recommended Software Releases',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['openscholar-feature-software'] = $context;
  return $export;
}
