<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_blog_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-blog';
  $context->description = 'Blogs';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'blog' => 'blog',
        'blog/*' => 'blog/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_blog:page_1' => 'scholar_blog:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'blog',
    'block' => array(
      'blocks' => array(
        'vsite_taxonomy-0' => array(
          'module' => 'vsite_taxonomy',
          'delta' => '0',
          'weight' => 37,
          'region' => 'right',
          'status' => '0',
          'label' => 'Categories - Filter categorized content',
          'type' => 'context_ui',
        ),
        'vsite_widgets-2' => array(
          'module' => 'vsite_widgets',
          'delta' => '2',
          'weight' => 38,
          'region' => 'right',
          'status' => '0',
          'label' => 'AddThis Button - Share posts using popular services',
          'type' => 'context_ui',
        ),
        'views-scholar_blog-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_blog-block_1',
          'weight' => 39,
          'region' => 'right',
          'status' => '0',
          'label' => 'scholar_blog: Block',
          'type' => 'context_ui',
        ),
        'views-scholar_blog_comments-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_blog_comments-block_1',
          'weight' => 40,
          'region' => 'right',
          'status' => '0',
          'label' => 'scholar_blog_comments: Recent comments',
          'type' => 'context_ui',
        ),
        'scholar_blog-rss' => array(
          'module' => 'scholar_blog',
          'delta' => 'rss',
          'weight' => 20,
          'region' => 'footer',
          'status' => '0',
          'label' => 'RSS Feed - Link to subscribe to your newest blog entries',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blogs');
  t('Feature');

  $export['openscholar-feature-blog'] = $context;
  return $export;
}
