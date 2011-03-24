<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_layout_context_default_contexts() {
  $export = array();
  
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scholar-feature-none';
  $context->description = 'Active when a feature context has not matched any contditon.';
  $context->tag = 'feature';
  $context->conditions = array(
	  'context' => array(
	    'values' => array(
	      '~scholar-feature-*' => '~scholar-feature-*',
	    ),
	  ),
	);
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['scholar-feature-none'] = $context;
  
  return $export;
}
