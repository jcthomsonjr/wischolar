<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_classes_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scholar-feature-classes';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        0 => 'class',
        1 => 'class_material',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        0 => 'scholar_classes',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'classes',
    'block' => array(
      'blocks' => array(
        'vsite_widgets-2' => array(
          'module' => 'vsite_widgets',
          'delta' => '2',
          'weight' => 37,
          'region' => 'right',
          'status' => '0',
          'label' => 'ShareThis Button - Allows you to share posts using popular online services',
          'type' => 'context_ui',
        ),
        'scholar_book-booktoc' => array(
          'module' => 'scholar_book',
          'delta' => 'booktoc',
          'weight' => 38,
          'region' => 'right',
          'status' => '0',
          'label' => 'Scholar: Book',
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
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['scholar-feature-classes'] = $context;
  return $export;
}