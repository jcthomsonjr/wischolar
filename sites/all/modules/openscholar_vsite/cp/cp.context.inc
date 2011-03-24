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
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array_keys(features_get_component_map('node')),
      'options' => array(
        'node_form' => '2',
      ),
    ),
    'path' => array(
      'values' => array(
        'cp/*' => 'cp/*',
      ),
      'options' => array(
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(),
  );
  $context->condition_mode = 0;
  $export['vsite-section-cp'] = $context;
  
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cp-section-cp';
  $context->description = '(cp-section namespace will be reworked) Active when you are in the CP section of a vsite';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array_keys(features_get_component_map('node')),
      'options' => array(
        'form' => 'form'
      ),
    ),
    'path' => array(
      'values' => array(
        'cp/*' => 'cp/*',
      ),
      'options' => array(
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(),
  );
  $context->condition_mode = 0;
  $export['cp-section-cp'] = $context;
  
  return $export;
}
