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
 * @param string $s_logo_field
 * @param string $preset
 * @param string $alt
 * @param string $title
 * @param array $attributes
 * @param boolean $bypass_browser_cache
 * @param boolean $b_as_link
 * @return string
 */
function theme_vsite_logo($scholar = false, $s_logo_field = "field_vsite_logo", $preset = false, $alt = '' , $title = '', $attributes = array(), $bypass_browser_cache =false, $b_as_link = false){
  $s_image_path;
  $s_out;
  if(!$scholar) $scholar = vsite_get_vsite();
  
  if(!$scholar || !($a_files = filefield_get_node_files($scholar->group,$s_logo_field)) || !count($a_files)){
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
      //'og_theme' => 'scholar_theme_01',
  );
  $node = install_create_node($title = $domain, $body = NULL, $properties = $properties);
    
  $vsite = spaces_load("og", $sid = $node -> nid, $is_active = FALSE);
  $vsite -> group -> og_theme = _vsite_get_random_theme();
  spaces_save($vsite);
  
  return $vsite;
}

/**
 * returns an array of available themes for faculty to chose
 * 
 * @param $theme_type string
 *    The ID of the site type that you would like to recieve themes for
 * 
 * @see _cp_is_scholar_theme
 * @todo private themes ?!
 */
function vsite_vsite_themes($theme_type = "scholar"){
  $allthemes = list_themes();
  _vsite_get_theme_type($theme_type);
  
  return (array_filter($allthemes,"_vsite_is_vsite_theme"));
}

/**
 * Set the theme_type to filter by
 * 
 * THIS FUNCTION IS PRIVATE
 * as such it should not be called from outside this file
 */
function _vsite_get_theme_type( $s_set_theme_type = false ){
	static $s_theme_type;
	
	if($s_set_theme_type) $s_theme_type = $s_set_theme_type;
	
	return $s_theme_type;
}

/**
 * a callback function for array_filter() in iq_og_fac_themes
 *
 * @param unknown_type $atheme - the theme to be tested
 * @return TRUE if it should be listed as faculty theme, false otherwise
 */
function _vsite_is_vsite_theme($atheme){
  return (array_key_exists('scholar',$atheme->info) 
       && array_key_exists('theme_type',$atheme->info['scholar']) 
       && _vsite_get_theme_type() == $atheme->info['scholar']['theme_type'] 
       && ($atheme->info['scholar']['theme_access'] != "private" || user_access('access private scholar themes'))
       && !empty($atheme->status));
}

/**
 * returns a random theme from a selected list
 */
function _vsite_get_random_theme(){
  $themes = array();
  $selected_themes = array('scholar_theme_01', 'scholar_theme_02', 'scholar_theme_03', 'scholar_theme_06');
  $all_themes = array_keys(list_themes());
  $themes = array_intersect( $selected_themes, $all_themes );
  shuffle($themes);
  if(count($themes)) {
    return $themes[0];
  }
  return  variable_get('scholar_default_theme', 'scholar_theme_01');
}

/**
   * Imports an image as a filefield image of a given node
   * 
   * Usage example:
   * --------------
   * $node = node_load(array('nid' => 61));
   * $image = drupal_get_path('module', 'vsite_design').'/theme/images/default_logo.jpg';
   * simport_node_add_imagefield_image($image, 'field_img', $node);
   * 
   * @param $source  the path to the source image
   * @param $field_name the name of the cck field 
   * @param $node the node object to upload the image to (passed by reference)
   */
function vsite_add_imagefield_image($source, $field_name, &$node){
  
  // get the cck filefield
  $field = content_fields($field_name, $node -> type);
  
  // validators (can add our own validators if we want)
  $validators = array_merge(filefield_widget_upload_validators($field), imagefield_widget_upload_validators($field));
  
  // where to store the file
  $files_path = filefield_widget_file_path($field);
    
  if(og_is_group_type($node->type)){
    $vsite = spaces_load('og',$node->nid);
    $files_path .= $vsite->purl;
    file_check_directory($files_path,FILE_CREATE_DIRECTORY);
    $files_path .= '/files';
    file_check_directory($files_path,FILE_CREATE_DIRECTORY);
  }//If this is the group node lets put it in the group directory
    
  // create the file object
  if(!@filesize($source)){
    error_log("could not get file size for [$source] ");
    return false; 
  }//if the file does not exsit dont try and save
    
  $file = field_file_save_file($source, $validators, $files_path);
  
  // attach it to the filefield field
  $node->$field_name = array(
  0 => array(
  'fid' => $file['fid'],
  'uid' => $node -> uid,
  'list' => 1,
    )
  ); 
    
  // save the node
  node_save($node);
    
  return $file['destination'];
}

/**
 * Get an array of referrer nids, by node.type & field.type
 * @param nid
 *     the nid we want to find referres for
 * @param fieldnames
 *     array of fieldnames to be checked for referrers
 * @param nodetypes
 *     array of node types to be checked for referrers
 */

function vsite_get_referrers($nid,  $fieldnames = array(), $nodetypes = array()) {
  
	if ($nodetypes) {
    $filter_nodetypes = "AND n.type IN (" .  rtrim(str_repeat(" '%s' ,", count($nodetypes)),',') . ")";
  }
  else {
    $filter_nodetypes = '';
  }
  
  $fields = content_fields();
  // Set default values of fieldnames.
  if (!count($fieldnames)) {
    $fieldnames = array_keys($fields);
  }

  $values = array();
  foreach ($fieldnames as $fieldname) {
    if ($fields[$fieldname]['type'] == 'nodereference') {
      $db_info = content_database_info($fields[$fieldname]);

  
        $query = "SELECT       n.nid, n.vid, n.title
                  FROM         {" . $db_info['table'] . "} nr
                  INNER JOIN   {node} n ON n.vid = nr.vid AND n.status = 1 " . $filter_nodetypes . "
                  WHERE        nr." . $db_info['columns']['nid']['column'] . " = %d
                  ORDER BY     n.created DESC";
      
        

      $query = db_rewrite_sql($query);
      $result = db_query($query, array_merge($nodetypes,array($nid)));

      while ($value = db_fetch_array($result)) {
        // avoid duplicate referrers by using nid as key
        $values[$value['nid']] = $value;
      }
    }
  }
  return $values;
}

