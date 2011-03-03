<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_front_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scholar-feature-front';
  $context->description = 'The front page context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home' => 'home',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-scholar_events_upcoming-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_events_upcoming-block_1',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Upcoming events',
          'type' => 'context_ui',
        ),
        'views-scholar_announcements-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_announcements-block_1',
          'weight' => 21,
          'region' => 'right',
          'status' => '0',
          'label' => 'Latest Announcements',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The front page context');

  $export['scholar-feature-front'] = $context;
  return $export;
}
