<?php

define('FEATURE_PUBLIC', 2);
define('FEATURE_PRIVATE', 1);
define('FEATURE_DISABLED', 0);

/**
 * Return the content type of a vsite based on the privacy
 * @param $privacy and array (or single value) (0 -> disabled, 1 -> private, 2 -> public)
 * @param $vsite optional / the active vsite if nothing provided
 * @return unknown_type
 */
function vsite_content_types($privacy = array(2), $vsite = NULL){
  if (! is_array($privacy)) {
    $privacy = array(
        $privacy 
    );
  }
  
  if (! $vsite) {
    $vsite = vsite_get_vsite();
  }
  
  $result = array();
  if ($vsite) {
    $all_types = node_get_types('names');
    
    $features_types = spaces_features_map('node');
    
    foreach ( $features_types as $type => $feature ) {
      if (in_array(( int ) $vsite->features[$feature], $privacy)) {
        $result[$type] = $all_types[$type];
      }
    }
  }
  return $result;
}


function vsite_create_links($addition = ''){
  $types = vsite_content_types(array(2, 1));
  drupal_alter('vsite_content_types', $types);
  foreach ( $types as $type => $name ) {
  	$type_url_str = str_replace('_', '-', $type);
    $links[] = array(
        'title' => t('!type', array(
            '!type' => $type 
        )), 
        'href' => "node/add/$type_url_str" . $addition
    );
  }
  return isset($links) ? $links : array();
}

/**
 * Theme that returns the html for a scholar logo
 * 
 * @param viste $scholar
 * @param string $preset
 * @param string $alt
 * @param string $title
 * @param array $attributes
 * @param boolean $bypass_browser_cache
 * @param boolean $b_as_link
 * @return string
 */
function theme_vsite_design_logo($scholar = false, $preset = false, $alt = '' , $title = '', $attributes = array(), $bypass_browser_cache =false, $b_as_link = false){
  $s_image_path;
  $s_out;
  if(!$scholar) $scholar = vsite_get_vsite();
  
  if(!$scholar || !($a_files = filefield_get_node_files($scholar->group,'field_vsite_logo')) || !count($a_files)){
  	$s_image_path = drupal_get_path('module','vsite_design')."/theme/images/default_logo.jpg";
  }else{
  	$a_image = current($a_files);
  	$s_image_path = $a_image['filepath'];
  }//Default image?
	
  $s_url_extra = "";
  if($bypass_browser_cache) $s_url_extra .= "?version=".time();
  
  if($preset){
    $s_image_path = imagecache_create_url($preset, $s_image_path);
  }else{
  	$s_image_path = "/".$s_image_path;
  }//Cached or orig
  
  $attributes = drupal_attributes($attributes);
  $s_out = '<img src="'.$s_image_path . $s_url_extra .'" alt="'. check_plain($alt) .'" title="'. check_plain($title) .'" '. $attributes .' />';
  
  
  if($b_as_link) $s_out = l($s_out,'node/'.$scholar->sid,array('html'=>true));
  
  return $s_out;
}

/**
 * Create a scholar web site
 * 
 * NOTE: this function does not do any validation check.
 *       It's the caller responsibility
 * 
 * @param $name the username (site owner)
 * @param $mail the e-mail address of the user creating the site
 * @param $domain the domain name of the site
 * @return the node object if successful
 */
function vsite_vsite_create($name, $domain, $preset){
  install_include(array(
      'node' 
  ));
  $properties = array(
      'name' => $name, 
      'type' => variable_get('scholar_content_type', 'vsite'), 
      'promote' => '0', 
      'purl' => array(
          'value' => $domain, 
          'provider' => 'spaces_og', 
          'id' => NULL 
      ), 
      'preset' => $preset, 
      'og_description' => "$domain's web site", 
      'theme' => variable_get('scholar_default_theme', 'scholar_theme_01'), 
  );
  $node = install_create_node($title = $domain, $body = NULL, $properties = $properties);
  
  $vsite = spaces_load("og", $sid = $node -> nid, $is_active = FALSE);
  
  return $vsite;
}


/**
 * returns an array of available themes for faculty to chose
 * 
 * @see _cp_is_scholar_theme
 * @todo private themes ?!
 */
function vsite_vsite_themes(){
  $allthemes = list_themes();
  return (array_filter($allthemes,"_vsite_is_vsite_theme"));
}


/**
 * a callback function for array_filter() in iq_og_fac_themes
 *
 * @param unknown_type $atheme - the theme to be tested
 * @return TRUE if it should be listed as faculty theme, false otherwise
 */
function _vsite_is_vsite_theme($atheme){
  return ('vsite' == $atheme->info['og_theme_type']);
}
