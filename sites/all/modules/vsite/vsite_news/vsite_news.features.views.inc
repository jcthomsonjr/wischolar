<?php

/**
 * Helper to implementation of hook_views_default_views().
 */
function _vsite_news_views_default_views() {
  $views = array();

  // Exported view: vsite_activity
  $view = new view;
  $view->name = 'vsite_activity';
  $view->description = 'Display activities ';
  $view->tag = 'vsite';
  $view->view_php = '';
  $view->base_table = 'activity';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'created' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'date_format' => 'time ago',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'created',
      'table' => 'activity',
      'field' => 'created',
      'relationship' => 'none',
    ),
    'message' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
      ),
      'exclude' => 0,
      'id' => 'message',
      'table' => 'activity_messages',
      'field' => 'message',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'activity',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'value_vsite_activity' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'realms' => array(
        'vsite' => 'vsite',
      ),
      'id' => 'value_vsite_activity',
      'table' => 'activity_access',
      'field' => 'value_vsite_activity',
      'relationship' => 'none',
    ),
    'access_uid' => array(
      'id' => 'access_uid',
      'table' => 'activity',
      'field' => 'access_uid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 25);
  $handler->override_option('use_pager', '1');
  $handler->override_option('row_options', array(
    'inline' => array(
      'created' => 'created',
      'message' => 'message',
    ),
    'separator' => ':',
  ));
  $handler = $view->new_display('page', 'Main Followers Page', 'page_1');
  $handler->override_option('filters', array(
    'value_vsite_activity' => array(
      'id' => 'value_vsite_activity',
      'table' => 'activity_access',
      'field' => 'value_vsite_activity',
    ),
  ));
  $handler->override_option('path', 'cp/news/activity');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Activity',
    'description' => '',
    'weight' => '0',
    'name' => 'cp',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('page', 'Tab Followers', 'page_2');
  $handler->override_option('filters', array(
    'value_vsite_activity' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'realms' => array(
        'vsite' => 'vsite',
      ),
      'id' => 'value_vsite_activity',
      'table' => 'activity_access',
      'field' => 'value_vsite_activity',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('path', 'cp/news/activity/followers');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Followers Activity',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => '0',
  ));
  $handler = $view->new_display('page', 'Tab My Activity', 'page_3');
  $handler->override_option('filters', array(
    'access_uid' => array(
      'id' => 'access_uid',
      'table' => 'activity',
      'field' => 'access_uid',
    ),
  ));
  $handler->override_option('path', 'cp/news/activity/me');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'My Activity',
    'description' => '',
    'weight' => '1',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 1,
  ));
  $handler = $view->new_display('page', 'Tab All Activity', 'page_4');
  $handler->override_option('filters', array());
  $handler->override_option('path', 'cp/news/activity/all');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'All Activity',
    'description' => '',
    'weight' => '2',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 2,
  ));

  $views[$view->name] = $view;

  return $views;
}
