<?php

/**
 * Helper to implementation of hook_views_default_views().
 */
function _scholar_classes_views_default_views() {
  $views = array();

  // Exported view: scholar_classes
  $view = new view;
  $view->name = 'scholar_classes';
  $view->description = 'A view of classes for each site';
  $view->tag = 'features';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('sorts', array(
    'sticky' => array(
      'order' => 'ASC',
      'id' => 'sticky',
      'table' => 'node',
      'field' => 'sticky',
      'relationship' => 'none',
    ),
    'changed' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'name' => array(
      'default_action' => 'ignore',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'glossary' => 0,
      'limit' => '0',
      'case' => 'none',
      'path_case' => 'none',
      'transform_dash' => 1,
      'add_table' => 0,
      'require_value' => 0,
      'id' => 'name',
      'table' => 'term_data',
      'field' => 'name',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'announcement' => 0,
        'bio' => 0,
        'cv' => 0,
        'class' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'gallery' => 0,
        'image' => 0,
        'link' => 0,
        'page' => 0,
        'software' => 0,
        'vsite' => 0,
        'feature_request' => 0,
        'support_answer' => 0,
        'support_question' => 0,
        'vsite_users_profile' => 0,
        'biblio' => 0,
        'profile' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '23' => 0,
        '31' => 0,
        '36' => 0,
        '15' => 0,
        '33' => 0,
        '17' => 0,
        '13' => 0,
        '19' => 0,
        '28' => 0,
        '12' => 0,
        '22' => 0,
        '35' => 0,
        '11' => 0,
        '9' => 0,
        '29' => 0,
        '14' => 0,
        '30' => 0,
        '18' => 0,
        '21' => 0,
        '34' => 0,
        '26' => 0,
        '16' => 0,
        '24' => 0,
        '32' => 0,
        '8' => 0,
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '27' => 0,
        '25' => 0,
        '20' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'current' => array(
      'operator' => 'all',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'scholar_class' => 'class',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'type_op',
        'label' => 'Node: Type',
        'use_operator' => FALSE,
        'identifier' => 'type',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
        'reduce' => FALSE,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 15);
  $handler->override_option('use_pager', '1');
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'classes');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Classes',
    'description' => 'My classes',
    'weight' => '0',
    'name' => 'features',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));

  $views[$view->name] = $view;

  return $views;
}
