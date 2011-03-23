<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_context_default_contexts() {
  $export = array();
  
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vsite-section-public';
  $context->description = 'Active when you are in the public section of a vsite.';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~cp/*' => '~cp/*',
      ),
      'options' => array(
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(),
  );
  $context->condition_mode = 0;
  $export['vsite-section-public'] = $context;
  
  return $export;
  
}