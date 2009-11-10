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


function vsite_create_links(){
  $types = vsite_content_types(array(2, 1));
  drupal_alter('vsite_content_types', $types);
  foreach ( $types as $type => $name ) {
  	$type_url_str = str_replace('_', '-', $type);
    $links[] = array(
        'title' => t('!type', array(
            '!type' => $type 
        )), 
        'href' => "node/add/$type_url_str" 
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
  
  if(!$scholar || !$scholar->settings['logo'] && !$scholar->settings['logo']['current_logo']){
  	$s_image_path = drupal_get_path('module','vsite_design')."/theme/images/default_logo.jpg";
  }else{
  	$s_image_path = $scholar->settings['logo']['current_logo'];
  }//Default image?
	
  $s_url_extra = "";
  if($bypass_browser_cache) $s_url_extra .= "?version=".time();
  
  if($preset){
    $s_image_path = imagecache_create_url($preset, $s_image_path);
  	//$s_out = theme('imagecache', $preset, $s_image_path, $alt, $title,  $attributes);
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
 * @param $name the username
 * @param $mail the e-mail address of the user creating the site
 * @param $domain the domain name of the site
 * @return the node object if successful
 */
function vsite_vsite_create($name, $mail, $domain){
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
      'preset' => 'vsite', 
      'og_description' => "$domain's web site", 
      'theme' => variable_get('scholar_default_theme', 'scholar_theme_01'), 
  );
  $node = install_create_node($title = $domain, $body = NULL, $properties = $properties);
  
  $vsite = spaces_load("og", $sid = $node -> nid, $is_active = FALSE);
  
  return $vsite;
}


/**
 * returns an array of available themes for faculty to chose
 * For now it suppose that the theme name will follow this pattern
 * scholar_theme_01, scholar_theme__02 ... scholar_theme_99
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
  return (ereg("scholar_theme_[0-9][0-9]",$atheme -> name));
}


/**
 * Returns the vocabularies associated with a vsite.
 * If a content type is provided, return vocabs associated 
 * with that content type only.
 * @param $node_type
 * @return unknown_type
 */
function vsite_get_vocabs($vsite = NULL, $node_type = NULL){
  $result = array();
  if (!$vsite) {
    $vsite = vsite_get_vsite();
  }
  
  if ($vsite) {
    $group = $vsite->group;
    if (isset($group->og_vocabularies)) {
      if (! $node_type) {
        return $group->og_vocabularies;
      }
      
      foreach ( $group->og_vocabularies as $v ) {
        if (in_array($node_type, array_keys($v->nodes))) {
          $result[$v->vid] = $v;
        }
      }
      
      return $result;
    }
  }
}


