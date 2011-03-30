<?php

/**
 * main entry point for "cp/settings/appearance"
 */
function vsite_layout_layout() {
  jquery_ui_add(array('ui.draggable', 'ui.droppable', 'ui.sortable'));

  drupal_add_js(drupal_get_path('module', 'vsite_layout') . '/theme/vsite_layout.js');
  drupal_add_css(drupal_get_path('module', 'vsite_layout') . '/theme/vsite_layout.css');
  drupal_add_css(drupal_get_path('module', 'vsite_layout') . '/theme/cp-layout-map.css');

  $space = vsite_get_vsite();
  $a_info = drupal_parse_info_file(drupal_get_path('theme', $space->group->og_theme) . "/" . $space->group->og_theme . ".info");
  if (is_array($a_info) && array_key_exists('scholar', $a_info) && array_key_exists('cp_layout_css', $a_info['scholar'])) {
    //cp_layout_css
    drupal_add_css(drupal_get_path('theme', $space->group->og_theme) . "/" . $a_info['scholar']['cp_layout_css']);
  }


  $s_page_type =  (isset($_GET['page_type']))? $_GET['page_type']:'all';

  //top
  $vsite_layout_widgets = vsite_layout_region_widgets($s_page_type);
  $wgts = array_key_exists('unused', $vsite_layout_widgets)?$vsite_layout_widgets['unused']:array();

  //Disable widgets that are part of inactive features
  _check_for_disabled_widgets($wgts);
  
  
  $top = theme('vsite_layout_layout_widgets', $wgts, 'scholarlayout-top-widgets', 'scholarlayout-widgets-list');

  //form
  module_load_include('inc', 'vsite_layout', 'includes/vsite_layout.admin');
  $form = call_user_func_array('drupal_get_form', array('vsite_layout_settings_form'));

  return $top . $form;
}

/**
 * Callback to swap out the regions avalible for different pages
 * @param $s_region
 * @return string
 */
function vsite_layout_region_widgets_callback() {
  $scholar = vsite_get_vsite();
  $s_page_type = $_POST['page_type'];

  $features = spaces_features();
  $a_feature_contexts = array();
  if (!empty($features[$s_page_type]) && !empty($features[$s_page_type]->info['features']['context'])) {
    $a_feature_contexts =  drupal_map_assoc($features[$s_page_type]->info['features']['context']);
  }

  $a_region_wgts = vsite_layout_region_widgets($s_page_type);
  $a_themed_regions = array();

  $regions = system_region_list('scholar_base');
  foreach ($regions as $region => $s_label) {
    $widgets = array_key_exists($region, $a_region_wgts)?$a_region_wgts[$region]:array();
    $wgts_id = 'scholarlayout-' . str_replace('_', '-', $region);
    if ($s_page_type == 'all') _check_for_overrides($widgets, $region, $scholar);
    _check_for_disabled_widgets($widgets, $scholar);
    $a_themed_regions[$region] = theme('vsite_layout_layout_widgets', $widgets, $wgts_id, 'scholarlayout-widgets-list', ucwords($s_label));
  }
  $a_themed_regions['content'] = theme('vsite_layout_layout_widgets', array(), 'scholarlayout-content-main', 'scholarlayout-widgets-list', 'Main Content');

  $output= '<div id="scholarlayout-container">' .
           $a_themed_regions['header_main'] .
           $a_themed_regions['header_left'] .
           $a_themed_regions['header_right'] .
           $a_themed_regions['navbar'] .
           $a_themed_regions['left'] .
           $a_themed_regions['content'] .
           $a_themed_regions['right'] .
           $a_themed_regions['footer'] . "</div>";

  drupal_json(array('status' => TRUE, 'data' => $output));
}

/**
 * Callback to swap out the top widgets avalible for different pages
 * @param $s_region
 * @return string
 */
function vsite_layout_top_widgets_callback() {
  $scholar = vsite_get_vsite();
  $s_page_type = $_POST['page_type'];
  
  $a_region_wgts = vsite_layout_region_widgets($s_page_type);
  //top
  $wgts = array_key_exists('unused', $a_region_wgts)?$a_region_wgts['unused']:array();

  $wgts_id = 'scholarlayout-top-widgets';
  $wgts_class = 'scholarlayout-widgets-list';

  //Disable widgets from disabled features
  _check_for_disabled_widgets($wgts);
  $top = theme('vsite_layout_layout_widgets', $wgts, $wgts_id, $wgts_class);

  drupal_json(array('status' => TRUE, 'data' => $top));
}



/*
 * The form for setting the block values
 */
function vsite_layout_settings_form($form_state){
  
	$space = vsite_get_vsite();
	if(!$space) return array();
	
	// just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-layout">';
  $form['#suffix'] = '</div>';
  
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
    '#tree' => TRUE,
  );
  
  if (!is_array($value)) $value = array(); //DEFAULT CONTEXT SETTINGS
    
  $s_page_type =  (isset($_GET['page_type']))? $_GET['page_type']:'none';

  $form['settings']['layout'] = array('#title' => 'Site Layout');

  $regions = array_keys(system_region_list('scholar_base'));

  $a_setting = $space->controllers->context->get('openscholar-feature-'.$s_page_type.":reaction:block");
  $a_blocks = (isset($a_setting['blocks']))? $a_setting['blocks']:array();
  
  foreach ($regions as $region) {
    $wgts_id = 'scholarlayout-' . str_replace('_', '-', $region);
    $form[$wgts_id] = array('#type' => 'hidden' );
    
    $s_def = "";
    foreach ($a_blocks as $s_wgt => $block) if ($block['region'] == $region) $s_def .= $s_wgt . "|";
    $form[$wgts_id]['#default_value'] = rtrim($s_def, "\|");
  }

  $a_page_types = vsite_layout_get_pagetypes($space);

  $form['page_type'] = array(
    '#type' => 'select',
    '#title' => t('Widget layout'),
    '#default_value' => $s_page_type,
    '#options' => $a_page_types,
    '#description' => t('Customize layout for your front page or any specific section of your site. "Default settings" cover everything else.'),
    '#ahah' => array(
          'event' => 'go_ahah',
          'path' => 'cp/appearance/layout/region_widgets_js',
          'wrapper' => 'scholarlayout-container',
          'progress' => array('type' => 'throbber', 'message' => t('Loading Page...')),
          'effect' => 'fade',
          'method' => 'replaceWith',
    ),
  );

  $form['secret_hidden_ahah'] = array(
    '#type' => 'hidden',
    '#value' => $s_page_type,
    '#ahah' => array(
          'event' => 'go_ahah',
          'path' => 'cp/appearance/layout/top_widgets_js',
          'wrapper' => 'scholarlayout-top-widgets',
          'effect' => 'fade',
          'progress' => array('type' => 'none'),
          'method' => 'replaceWith',
    ),
  );

  $form['layout_markup'] = array(
    '#value' => theme('vsite_layout_layout'),
  );
  
  // pass the settingid too
  $form['setting'] = array(
    '#type' => 'value',
    '#value' => 'layout',
  );

  // add the submit button (not in the form definition yet)
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('vsite_layout_settings_form_reset'),
  );
  
  return $form;
  
}

/**
 * Reset to defaults
 */
function vsite_layout_settings_form_reset($form, &$form_state) {
	$space = vsite_get_vsite();
  if(!$space) return;
  
  foreach (array_keys(vsite_layout_get_pagetypes($space)) as $s_page_type) {
  	$space->controllers->context->del('openscholar-feature-'.$s_page_type.":reaction:block:".$space->group->og_theme);
  }
}

/**
 * Save Settings
 */
function vsite_layout_settings_form_submit($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;
  
	$s_page_type = $form_state['values']['page_type'];
	$regions = array_keys(system_region_list('scholar_base'));
	
	//Gather the region settings from the form values
	$region_setting = array();
  foreach ($form_state['values'] as $field => $value) {
    $field = str_replace('-', '_', str_replace('scholarlayout-', '', $field));
    if (!in_array($field, $regions)) continue;
    
    $a_values = strlen($value)?split("\|", $value):array();
    foreach ($a_values as $val) $setting[$val] = $field;
  }
  
  //Apply the region settings
  $a_avalible_blocks = $space->controllers->context->get('openscholar-feature-'.$s_page_type.":reaction:block","preset");
  foreach ($a_avalible_blocks['blocks'] as $s_key => $block) {
  	$a_avalible_blocks['blocks'][$s_key]['region'] = isset($setting[$s_key])? $setting[$s_key]:false;
  	$a_avalible_blocks['blocks'][$s_key]['weight'] = array_search($s_key,array_keys($setting));
  }
  
  uasort($a_avalible_blocks['blocks'], 'vsite_layout_sort_block_by_weight'); //Put them in the right order to simplify showing them in the cp
  if($s_page_type == 'none') vsite_layout_apply_changes_to_default($a_avalible_blocks);
  $space->controllers->context->set('openscholar-feature-'.$s_page_type.":reaction:block:".$space->group->og_theme, $a_avalible_blocks);
  
  if ($s_page_type && $s_page_type != 'none') {
    $form_state['redirect'] = array($_GET['q'], "page_type=" . $s_page_type);
  }
}


/**
 * Return a List of the Page Types Avalible
 *
 * @param vsite $space
 */
function vsite_layout_get_pagetypes($space) {
  if (!$space && !($space = vsite_get_vsite()))  return array(); //No valid space

  static $a_page_types;

  if ($a_page_types) return $a_page_types;

  $contexts = context_load();
  $space_features = spaces_features('og');
  $a_feature_permissions = $space->controllers->variable->get('spaces_features');

  module_load_include('inc', 'features', 'features.export');
  $feature_context_map = features_get_default_map('context');
  
  $a_first = array('front','none'); //Include First in the List
  $a_page_types = array();
  $a_features = array();
  foreach ($contexts as $s_key => $context) {
    //Is this a site "Section"?
    if(strtolower($context->tag) != 'feature' || !($s_shortname = str_replace("openscholar-feature-","",$s_key))) continue;

    //If this is a spaces feature is the feature Enabled?
    if(isset($space_features[$feature_context_map[$s_key]]) && !$a_feature_permissions[$feature_context_map[$s_key]] ) continue;
    
    $s_nice_name = ($context->description)? ucfirst($context->description): ucfirst($s_shortname);
    
    //Move front to the ... front of the list
    if (in_array($s_shortname,$a_first)) {
      if($s_shortname == 'none'){
        $a_page_types = array_merge(array($s_shortname => $s_nice_name), $a_page_types);
      } else {
        $a_page_types[$s_shortname] = $s_nice_name;
      }
    }else{
      $a_features[$s_shortname] = $s_nice_name;
    }
  }
  asort($a_features,SORT_STRING); //Alpha order
  $a_page_types = array_merge($a_page_types,$a_features);
  
  return $a_page_types;
}

/**
 * For the Layout Display, Show what widgets are overridden in a child page
 *
 * @param array $widgets
 * @param string $s_region
 * @param vsite $space
 */
function _check_for_overrides(&$widgets, $s_region, $space = NULL) {
  if(!count($widgets)) return;
  
  if (!$space) $space = vsite_get_vsite();
   
  $a_layout_settings = ($space)?$space->controllers->variable->get('vsite_setting_layout'):array();

  foreach (vsite_layout_get_pagetypes($space) as $s_page_nm => $s_page_readable) {
    if ($s_page_nm == 'all') continue;
    
    $context = context_load('openscholar-feature-'.$page_type);
    if(!($a_page_widgets = $context->reactions['block']['blocks'])) continue;
    
    foreach ($widgets as $s_wgt_name => $wgt) {
      if (!array_key_exists($s_wgt_name, $a_page_widgets) || $a_page_widgets[$s_wgt_name]['region'] != $s_region) {
        $widgets[$s_wgt_name]['overides'][] = $s_page_readable;
      }
    }
  }
}

/**
 * This function takes a new default setting and finds the diff from the old, and applies those to other page types that are not overridden
 */
function vsite_layout_apply_changes_to_default($a_new_setting){
	$space = vsite_get_vsite();
	$a_prev_setting = $space->controllers->context->get("openscholar-feature-none:reaction:block");
	
	$a_new_wgts = array();
	$a_rem_wgts = array();
	$a_moved_wgts = array();
	$a_weight_wgts = array();
	foreach ($a_new_setting['blocks'] as $key => $block) {
		if($block['region'] != $a_prev_setting['blocks'][$key]['region']){
			if(!$block['region']){
				$a_rem_wgts[] = $key;
			}elseif(!$a_prev_setting['blocks'][$key]['region']){
				$a_new_wgts[] = $key;
			}else{
				$a_moved_wgts[] = $key;
			}
		}//region change
		
		if($block['weight'] != $a_prev_setting['blocks'][$key]['weight']){
			$a_weight_wgts[$key] =  $block['weight'] - $a_prev_setting['blocks'][$key]['weight'];
		}//Weight Change
	}//gather changes

  foreach (array_keys(vsite_layout_get_pagetypes($space)) as $s_page_nm) {
    if ($s_page_nm == 'none') continue;

    $a_new_page = $space->controllers->context->get("openscholar-feature-".$s_page_nm.":reaction:block");

    //Handle widgets added
    foreach ($a_new_wgts as $s_widget_name) {
      if (!$a_new_page['blocks'][$s_widget_name]['region']) {
        $a_new_page['blocks'][$s_widget_name] = $a_new_setting['blocks'][$s_widget_name];
      }//Already on this page?
    }//Add new widgets

    //Handle widgets removed
    foreach ($a_rem_wgts as $s_widget_name) {
      if (array_key_exists($s_widget_name, $a_new_page['blocks']) && $a_new_page['blocks'][$s_widget_name]['region'] == $a_prev_setting['blocks'][$s_widget_name]['region']) {
        $a_new_page['blocks'][$s_widget_name]['region'] = false;
      }//Already on this page?
    }//Remove widgets
    
    //Handle widgets moved
    foreach ($a_moved_wgts as $s_widget_name) {
      if ($a_new_page['blocks'][$s_widget_name]['region'] == $a_prev_setting['blocks'][$s_widget_name]['region']) {
        $a_new_page['blocks'][$s_widget_name]['region'] = $a_new_setting['blocks'][$s_widget_name]['region'];
      }//Already on this page?
    }//Move widgets

    //Handle weight changed
    foreach ($a_weight_wgts as $s_widget_name => $change) {
      if ($a_new_page['blocks'][$s_widget_name]['region'] == $a_prev_setting['blocks'][$s_widget_name]['region']) {
        $a_new_page['blocks'][$s_widget_name]['weight'] += $change;
      }//Already on this page?
    }//Crude Change weight
    
    uasort($a_new_page['blocks'], 'vsite_layout_sort_block_by_weight'); //Put them in the right order to simplify showing them in the cp
    $space->controllers->context->set('openscholar-feature-'.$s_page_nm.":reaction:block:".$space->group->og_theme, $a_new_page);
  }
}