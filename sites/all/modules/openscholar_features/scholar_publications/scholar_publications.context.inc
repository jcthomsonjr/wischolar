<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_publications_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-publications';
  $context->description = 'Publications';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'biblio' => 'biblio',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'publications' => 'publications',
        'publications/*' => 'publications/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'publication_types:page_1' => 'publication_types:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'publications',
    'block' => array(
      'blocks' => array(
        'vsite_taxonomy-0' => array(
          'module' => 'vsite_taxonomy',
          'delta' => '0',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Categories - A widget used to quickly filter categorized content',
          'type' => 'context_ui',
        ),
        'views-scholar_publications-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_publications-block_1',
          'weight' => 21,
          'region' => 'right',
          'status' => '0',
          'label' => 'Recent publications',
          'type' => 'context_ui',
        ),
        'vsite_widgets-2' => array(
          'module' => 'vsite_widgets',
          'delta' => '2',
          'weight' => 22,
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
  t('Feature');
  t('Publications');

  $export['openscholar-feature-publications'] = $context;
  return $export;
}
