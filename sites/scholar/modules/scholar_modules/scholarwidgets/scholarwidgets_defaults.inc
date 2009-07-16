<?php

function _scholarwidgets_default_contexts(){
	$items = array();
$items[] = array(
  'namespace' => 'scholar',
  'attribute' => 'section',
  'value' => 'scholarwidgets',
  'spaces_type' => array(
    '0' => 'og',
  ),
  'block' => array(
    'menu_scholarcp' => array(
      'module' => 'menu',
      'delta' => 'scholarcp',
      'weight' => 20,
      'region' => 'header_top',
      'status' => '0',
      'label' => 'Scholar CP',
      'type' => 'context_ui',
    ),
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
    'menu_features' => array(
      'module' => 'menu',
      'delta' => 'features',
      'weight' => 20,
      'region' => 'navbar',
      'status' => '0',
      'label' => 'Features',
      'type' => 'context_ui',
    ),
  ),
);
	return $items;
}