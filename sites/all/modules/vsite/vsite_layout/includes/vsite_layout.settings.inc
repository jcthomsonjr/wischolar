<?php

/**
 * Provides page settings for each site
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

	  $s_page_type = 	(isset($_GET['page_type']))? $_GET['page_type']:'all';
  	
  	$form = array('#title' => 'Site Layout');

	  $regions = array_keys(system_region_list('scholar_base'));

	  foreach($regions as $region){
	    $r = str_replace('_','-', $region);
	    $wgts_id = 'scholarlayout-' . $r;
	    $form[$wgts_id] = array('#type' => 'hidden' );
	    if(is_array($value[$s_page_type]) && in_array($region,$value[$s_page_type])){
	    	$s_def = "";
	    	foreach($value[$s_page_type] as $s_wgt => $s_region) if($s_region == $region) $s_def .= $s_wgt."|";
	    	$form[$wgts_id]['#default_value'] = rtrim($s_def,"\|");
	    }
	  }

	  $a_page_types = vsite_layout_get_pagetypes($space);

	  $form['page_type'] = array(
	    '#type' => 'select',
	    '#title' => t('Pages in your site'),
	    '#default_value' => $s_page_type,
	    '#options' => $a_page_types,
	    '#description' => t('Select the widgets to display everywhere in your site (Default settings) the front page or a specific section (feature) of your site'),
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
	    '#value' => $s_page_type,
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
	    	//See what alterations you need to carry through
	    	
	      $a_prev_settings = array();
	      if(is_array($space->settings['layout']) && array_key_exists('all',$space->settings['layout'])){
	        $a_prev_settings = $space->settings['layout'][$s_page_type];
	      }else{
	        $a_prev_settings = _vsite_layout_generate_default_settings_ary('all',false);
	      }//Use saved settings or default settings
	      $a_new_all_wgts = array_diff(array_keys($setting),array_keys($a_prev_settings));
	      $a_rem_all_wgts = array_diff(array_keys($a_prev_settings),array_keys($setting));

	      foreach(array_keys(vsite_layout_get_pagetypes($space)) as $s_page_nm){
	        if($s_page_nm == 'all') continue;
	        $a_new_settings = (is_array($space->settings['layout'][$s_page_nm]))?$space->settings['layout'][$s_page_nm]:_vsite_layout_generate_default_settings_ary($s_page_nm);

	        //Handle widgets added
	        foreach ($a_new_all_wgts as $s_widget_name) {
	          if(!array_key_exists($s_widget_name,$a_new_settings) || $a_new_settings[$s_widget_name] === false){
	            $a_new_settings[$s_widget_name] = $setting[$s_widget_name];
	          }//Already on this page?
	        }//Add new widgets

          //Handle widgets removed
	        foreach ($a_rem_all_wgts as $s_widget_name) {
	          if(array_key_exists($s_widget_name,$a_new_settings) && $a_new_settings[$s_widget_name] == $a_prev_settings[$s_widget_name]){
	            unset($a_new_settings[$s_widget_name]);
	          }//Already on this page?
	        }//Remove widgets
	        
	        //Widgets that have changed positions
	        foreach ($setting as $s_widget_name => $s_region){
	        	if(array_key_exists($s_widget_name,$a_new_settings) &&  //The Widget is in the subpage
	        	   (($a_prev_settings[$s_widget_name] == $a_new_settings[$s_widget_name])  //The Widget had the same prev region
	        	   || (in_array($s_widget_name,$a_new_all_wgts) && $s_region == $a_new_settings[$s_widget_name]))){  //OR The widget was just added from the bucket
	        	  //Put it into the new location if it has moved
	        		$a_new_settings[$s_widget_name] = $s_region;
	        		
	        		//Get the Offset of the widget within the region on the homepage
	        	  $n_pos = array_search($s_widget_name,array_keys(array_intersect($setting, array($s_region))));
	        	  
	        	  if($n_pos != self::getSubpageRelitiveOffset($s_widget_name,$s_region,$a_new_settings,$setting)){
	        	  	
	        	  	//Move this setting to the end of the stack
	        	  	unset($a_new_settings[$s_widget_name]);
	        	  	$a_new_settings[$s_widget_name] = $s_region;
	        	  	
		        	  $offset = -1;
		        		while(self::getSubpageRelitiveOffset($s_widget_name,$s_region,$a_new_settings,$setting) > $n_pos){
		        			unset($a_new_settings[$s_widget_name]);
		        			$a_keys = array_keys($a_new_settings);
		        			array_splice($a_keys,$offset,0,$s_widget_name); //Insert Key in correct place
		        			array_splice($a_new_settings,$offset,0,$s_region); //Insert Value in correct place
		        			
		        			$a_new_settings = array_combine($a_keys,$a_new_settings); //Preserve Keys
		        			$offset--;
		        		}//move the element up till it is in the correct location

	        	  }//If the Widget's offset does not match that of the one on the homepage
	        		
	        	}//The widget is on the subpage, and it was in the prev location or it has just been added to the page
	        }
	        
	        $space->settings['layout'][$s_page_nm] = $a_new_settings;
	      }//Check Each Page Type
	    }//Add new all widgets to all templates

	    //Save the new version if we made changes
	    $space->settings['layout'][$s_page_type] = $setting;
	  }

	  return $space->settings['layout'];
  }
  
  function modifyRedirect($form_values){
  	if (!empty($form_values)) {
      $s_page_type = $form_values['page_type'];
      if($s_page_type && $s_page_type != 'all'){
      	return array($_GET['q'], "page_type=".$s_page_type); //$_GET['q']."?page_type=".$s_page_type;
      }else{
      	return $_GET['q'];
      }
  	}
    return $_GET['q'];
  }
  
  /**
   * Filter return the 0-indexed offset of a widget within a region
   * @param $s_name string The Widget ID
   * @param $region string The Region ID
   * @param $a_subpage array The subpage settings
   * @param $a_home array The homepage Settings
   * @return number
   */
  private static function getSubpageRelitiveOffset($s_name,$s_region,$a_subpage,$a_home){
  	
  	return array_search( $s_name, //Offset of this widget
  	         array_keys(          //Return the keys as a 0 indexed array
  	           array_intersect(   //Remove the items that are in other regions
  	             array_intersect_key($a_subpage,$a_home) //Remove those items that don't exist in the home array
  	             ,array($s_region))));
  }  
}

