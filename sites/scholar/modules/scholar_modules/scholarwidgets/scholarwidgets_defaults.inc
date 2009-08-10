<?php

function _scholarwidgets_default_contexts(){
	$items = array();
  $items[] = array(
  'namespace' => 'cp',
  'attribute' => 'section',
  'value' => 'layout',
  'spaces_type' => array(
    '0' => 'og',
  ),
  'block' => array(
    'scholarwidgets_0' => array(
      'module' => 'scholarwidgets',
      'delta' => '0',
      'weight' => 20,
      'region' => 'header_left',
      'status' => '0',
      'label' => 'Scholar site logo',
      'type' => 'context_ui',
    ),
    'scholarwidgets_1' => array(
      'module' => 'scholarwidgets',
      'delta' => '1',
      'weight' => 20,
      'region' => 'header_main',
      'status' => '0',
      'label' => 'Scholar site info',
      'type' => 'context_ui',
    ),
    'scholarwidgets_2' => array(
      'module' => 'scholarwidgets',
      'delta' => '2',
      'weight' => 20,
      'region' => 'header_right',
      'status' => '0',
      'label' => 'Scholar site shield',
      'type' => 'context_ui',
    ),
    /*
    'menu_features' => array(
      'module' => 'menu',
      'delta' => 'features',
      'weight' => 20,
      'region' => 'navbar',
      'status' => '0',
      'label' => 'Features',
      'type' => 'context_ui',
    ),
    */
    

    'scholarmenu_0' => array(
      'module' => 'scholarmenu',
      'delta' => '0',
      'weight' => 20,
      'region' => 'navbar',
      'status' => '0',
      'label' => 'Scholar primary menu',
      'type' => 'context_ui',
    ),
    'scholarmenu_1' => array(
      'module' => 'scholarmenu',
      'delta' => '1',
      'weight' => 20,
      'region' => 'left',
      'status' => '0',
      'label' => 'Scholar secondary menu',
      'type' => 'context_ui',
    ),
    
    // search site widget
    'og_views_0' => array(
      'module' => 'og_views',
      'delta' => '0',
      'weight' => 0,
      'region' => 'right',
      'status' => '0',
      'label' => 'Search',
      'type' => 'context_ui',
    ),
  ),
);
	return $items;
}