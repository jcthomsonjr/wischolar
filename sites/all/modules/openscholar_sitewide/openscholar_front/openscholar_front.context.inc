<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function openscholar_front_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-section-sitewide';
  $context->description = 'openscholar sitewide, no vsite context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin' => '~admin',
      ),
      'options' => array(),
    ),
    'context' => array(
      'values' => array(
        '~openscholar-section-*' => '~openscholar-section-*',
        '~vsite-section-*' => '~vsite-section-*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openscholar_front-site_info' => array(
          'module' => 'openscholar_front',
          'delta' => 'site_info',
          'weight' => 37,
          'region' => 'header_main',
          'status' => '0',
          'label' => 'OpenScholar: Site info',
          'type' => 'context_ui',
        ),
        'openscholar_front-top_links' => array(
          'module' => 'openscholar_front',
          'delta' => 'top_links',
          'weight' => 37,
          'region' => 'header_right',
          'status' => '0',
          'label' => 'OpenScholar: Top links',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('openscholar sitewide, no vsite context');

  $export['openscholar-section-sitewide'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-section-sitewide_front';
  $context->description = 'openscholar front context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openscholar_front-site_info' => array(
          'module' => 'openscholar_front',
          'delta' => 'site_info',
          'weight' => 36,
          'region' => 'header_main',
          'status' => '0',
          'label' => 'OpenScholar: Site info',
          'type' => 'context_ui',
        ),
        'openscholar_front-top_links' => array(
          'module' => 'openscholar_front',
          'delta' => 'top_links',
          'weight' => 36,
          'region' => 'header_right',
          'status' => '0',
          'label' => 'OpenScholar: Top links',
          'type' => 'context_ui',
        ),
        'openscholar_front-video_info' => array(
          'module' => 'openscholar_front',
          'delta' => 'video_info',
          'weight' => 36,
          'region' => 'content_top',
          'status' => '0',
          'label' => 'OpenScholar: Video info',
          'type' => 'context_ui',
        ),
        'views-openscholar_sites-block_2' => array(
          'module' => 'views',
          'delta' => 'openscholar_sites-block_2',
          'weight' => 36,
          'region' => 'content_bottom',
          'status' => '0',
          'label' => 'Latest Web Sites',
          'type' => 'context_ui',
        ),
        'openscholar_front-site_mission' => array(
          'module' => 'openscholar_front',
          'delta' => 'site_mission',
          'weight' => 37,
          'region' => 'content_top',
          'status' => '0',
          'label' => 'OpenScholar: Mission Statement',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('openscholar front context');

  $export['openscholar-section-sitewide_front'] = $context;
  return $export;
}
