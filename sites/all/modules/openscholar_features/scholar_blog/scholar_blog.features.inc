<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_blog_context_default_contexts() {
  $items = array();

  $items['scholar-feature-blog'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'blog',
    'description' => '',
    'node' => array(
      '0' => 'blog',
    ),
    'views' => array(
      '0' => 'scholar_blog',
    ),
    'menu' => 'blog',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 37,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories - Filter categorized content',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 38,
        'region' => 'right',
        'status' => '0',
        'label' => 'ShareThis Button - Allows you to share posts using popular online services',
        'type' => 'context_ui',
      ),
      'views_scholar_blog-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_blog-block_1',
        'weight' => 39,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_blog: Block',
        'type' => 'context_ui',
      ),
      'views_scholar_blog_comments-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_blog_comments-block_1',
        'weight' => 40,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_blog_comments: Recent comments',
        'type' => 'context_ui',
      ),
      'scholar_blog_rss' => array(
        'module' => 'scholar_blog',
        'delta' => 'rss',
        'weight' => 20,
        'region' => 'footer',
        'status' => '0',
        'label' => 'RSS Feed - Link to subscribe to your newest blog entries',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_blog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog entry'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_blog_views_api() {
  return array(
    'api' => '2',
  );
}
