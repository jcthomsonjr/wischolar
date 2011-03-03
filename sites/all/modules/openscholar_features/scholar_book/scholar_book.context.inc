<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_book_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scholar-feature-book';
  $context->description = 'scholar > book';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        0 => 'book',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        0 => 'scholar_books',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'documents',
    'block' => array(
      'blocks' => array(
        'scholar_book-booktoc' => array(
          'module' => 'scholar_book',
          'delta' => 'booktoc',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Scholar: Book',
          'type' => 'context_ui',
        ),
        'vsite_widgets-2' => array(
          'module' => 'vsite_widgets',
          'delta' => '2',
          'weight' => 21,
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
  t('scholar > book');

  $export['scholar-feature-book'] = $context;
  return $export;
}
