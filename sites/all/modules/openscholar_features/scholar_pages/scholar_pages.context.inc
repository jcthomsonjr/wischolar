<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_pages_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scholar-section-pages';
  $context->description = 'Custom Pages';
  $context->tag = 'Section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom Pages');
  t('Section');

  $export['scholar-section-pages'] = $context;
  return $export;
}
