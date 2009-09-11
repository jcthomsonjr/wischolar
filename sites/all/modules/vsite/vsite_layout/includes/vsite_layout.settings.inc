<?php

/**
 * Provides front page settings for each site
 */
class vsite_layout_settings_layout implements space_setting {
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'layout';
    }
  }

  function form($space, $value = array()) {

  	$form = array('#title' => 'Site Layout');

	  $regions = array_keys(system_region_list('scholar_base'));

	  foreach($regions as $region){
	    $r = str_replace('_','-', $region);
	    $wgts_id = 'scholarlayout-' . $r;
	    $form[$wgts_id] = array('#type' => 'hidden' );
	    if(is_array($value['all']) && in_array($region,$value['all'])){
	    	$s_def = "";
	    	foreach($value['all'] as $s_wgt => $s_region) if($s_region == $region) $s_def .= $s_wgt."|";
	    	$form[$wgts_id]['#default_value'] = rtrim($s_def,"\|");
	    }
	  }

	  $a_page_types = vsite_layout_get_pagetypes($space);

	  $form['page_type'] = array(
	    '#type' => 'select',
	    '#title' => t('Page Type'),
	    '#default_value' =>'all',
	    '#options' => $a_page_types,
	    '#description' => t('Each area of your site can be customized.'),
	    '#ahah' => array(
	          'event' => 'go_ahah',
	          'path' => 'cp/settings/layout/region_widgets_js',
	          'wrapper' => 'scholarlayout-container',
	          'progress' => array('type' => 'throbber', 'message' => t('Loading Page...')),
	          'effect' => 'fade',
	          'method' => 'replaceWith',
	    ),
	  );

	  $form['secret_hidden_ahah'] = array(
	    '#type' => 'hidden',
	    '#value' =>'all',
	    '#ahah' => array(
	          'event' => 'go_ahah',
	          'path' => 'cp/settings/layout/top_widgets_js',
	          'wrapper' => 'scholarlayout-top-widgets',
	          'effect' => 'fade',
	          'progress' => array('type' => 'none'),
	          'method' => 'replaceWith',
	    ),
	  );

	  return $form;
  }

  function validate($space, $value) {

  }

  function submit($space, $form_values) {
	  // get the space and the settings we want to save
	  $setting = array();
	  $regions = array_keys(system_region_list('scholar_base'));

	  if (!empty($form_values)) {
	    $s_page_type = $form_values['page_type'];

	    foreach ($form_values as $field => $value) {
	      $field = str_replace('-','_',str_replace('scholarlayout-','',$field));
	      if(!in_array($field,$regions)) continue;
	      $a_values = strlen($value)?split("\|",$value):array();
	      foreach ($a_values as $val) $setting[$val] = $field;
	    }

	    if($s_page_type == 'all'){
	      $a_prev_settings = array();
	      if(is_array($space->settings['layout']) && array_key_exists('all',$space->settings['layout'])){
	        $a_prev_settings = $space->settings['layout'][$s_page_type];
	      }else{
	        $a_prev_settings = _vsite_layout_generate_default_settings_ary();
	        foreach($a_prev_settings as $nm => $rgn) if($rgn == false) unset($a_prev_settings[$nm]);
	      }//Use saved settings or default settings
	      $a_new_all_wgts = array_diff(array_keys($setting),array_keys($a_prev_settings));
	      $a_rem_all_wgts = array_diff(array_keys($a_prev_settings),array_keys($setting));

	      foreach(array_keys(vsite_layout_get_pagetypes($space)) as $s_page_nm){
	        if($s_page_nm == 'all' || (!count($a_new_all_wgts) && !count($a_rem_all_wgts))) continue;
	        $a_new_settings = (is_array($space->settings['layout'][$s_page_nm]))?$space->settings['layout'][$s_page_nm]:_vsite_layout_generate_default_settings_ary($s_page_nm);

	       foreach ($a_new_all_wgts as $s_widget_name) {
	          if(!array_key_exists($s_widget_name,$a_new_settings) || $a_new_settings[$s_widget_name] === false){
	            $a_new_settings[$s_widget_name] = $setting[$s_widget_name];
	          }//Already on this page?
	        }//Add new widgets

	        foreach ($a_rem_all_wgts as $s_widget_name) {
	          if(array_key_exists($s_widget_name,$a_new_settings) && $a_new_settings[$s_widget_name] == $a_prev_settings[$s_widget_name]){
	            unset($a_new_settings[$s_widget_name]);
	          }//Already on this page?
	        }//Remove widgets

	        $space->settings['layout'][$s_page_nm] = $a_new_settings;
	      }//Check Each Page Type
	    }//Add new all widgets to all templates

	    $space->settings['layout'][$s_page_type] = $setting;
	  }

	  return $space->settings['layout'];
  }
}

