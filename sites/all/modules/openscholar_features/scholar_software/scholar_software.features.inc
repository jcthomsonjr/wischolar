<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_software_context_default_contexts() {
  $items = array();

  $items['scholar-feature-software'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'software',
    'description' => '',
    'node' => array(
      '0' => 'scholar_software_project',
      '1' => 'scholar_software_release',
    ),
    'views' => array(
      '0' => 'scholar_software_projects',
      '1' => 'scholar_software_releases',
      '2' => 'scholar_software_updates',
    ),
    'menu' => 'software',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => -20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar site categories',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 50,
        'region' => 'right',
        'status' => '0',
        'label' => 'AddThis button',
        'type' => 'context_ui',
      ),
      'views_scholar_software_releases-block_3' => array(
        'module' => 'views',
        'delta' => 'scholar_software_releases-block_3',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Software Releases',
        'type' => 'context_ui',
      ),
      'views_scholar_software_releases-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_software_releases-block_1',
        'weight' => 20,
        'region' => FALSE,
        'status' => '0',
        'label' => 'Recommended Software Releases',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_software_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_software_node_info() {
  $items = array(
    'scholar_software_project' => array(
      'name' => t('Software Project'),
      'module' => 'features',
      'description' => t('A software project page. Provides a summary of project information and releases for download.'),
      'has_title' => '1',
      'title_label' => t('Project'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'scholar_software_release' => array(
      'name' => t('Software Release'),
      'module' => 'features',
      'description' => t('A single release package for a given project.'),
      'has_title' => '1',
      'title_label' => t('Release'),
      'has_body' => '1',
      'body_label' => t('Notes'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_software_views_api() {
  return array(
    'api' => '2',
  );
}
