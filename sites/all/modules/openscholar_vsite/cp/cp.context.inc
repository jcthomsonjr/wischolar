<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function cp_context_default_contexts() {
  $export = array();
  
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vsite-section-cp';
  $context->description = 'Active when you are in the CP section of a vsite.';
  $context->tag = 'Section';
  $context->conditions = array(
    'node' => array(
      'values' => array_keys(features_get_component_map('node')),
      'options' => array(
        'node_form' => '2',
      ),
    ),
    'path' => array(
      'values' => array(
        'cp' => 'cp',
        'cp/*' => 'cp/*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cp_0' => array(
          'module' => 'cp',
          'delta' => '0',
          'weight' => 20,
          'region' => 'left',
          'status' => '0',
          'label' => 'CP left menu',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['vsite-section-cp'] = $context;
  
  return $export;
}
