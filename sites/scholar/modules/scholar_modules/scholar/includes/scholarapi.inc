<?php

/**
 * return "add content type" links
 * TODO: What would be the right condition for excluding 
 * some content types here. For example, if a content type
 * is part of a feature that user has not selected, that 
 * content type should not be part of the list
 */
function scholar_create_links() {
  global $user;
  $site = spaces_get_space();
  
  $post_types = og_get_types('group_post');
  $types = node_get_types();
  foreach ($post_types as $post_type) {
    $type_name = $types[$post_type]->name;
    $type_url_str = str_replace('_', '-', $post_type);
    if (module_invoke($types[$post_type]->module, 'access', 'create', $post_type, $user)) {
      $links[] = array(
        'title' => t('!type', array('!type' => $type_name)),
        'href' => "node/add/$type_url_str",
      );
    }
  }
  return isset($links) ? $links : array();
}

function scholar_content_types(){
  $result = array();
  $post_types = og_get_types('group_post');
  $types = node_get_types();
  foreach ($post_types as $post_type) {
    $type_name = $types[$post_type]->name;
    $result[$post_type] = $type_name;
  }
  return $result;
}

function theme_scholar_logo($preset = false, $alt = '' , $title = '', $attributes = array(), $bypass_browser_cache =false){
  $scholar = scholar_get_scholar();
  if(!$scholar || !$scholar->settings['logo'] && !$scholar->settings['logo']['current_logo']){
  	//@todo DO DEFAULT IMAGE
  	return false;
  }	
	
  $s_url_extra = "";
  if($bypass_browser_cache) $s_url_extra .= "?version=".time();
  
  if($preset){
    return theme('imagecache', $preset, $scholar->settings['logo']['current_logo'], $alt, $title,  $attributes);
  }else{
  	$attributes = drupal_attributes($attributes);
    $url = imagecache_create_url($presetname, $path);
    return '<img src="/'.$scholar->settings['logo']['current_logo'] . $s_url_extra .'" alt="'. check_plain($alt) .'" title="'. check_plain($title) .'" '. $attributes .' />';
  } //use imagecache? or orig?
  
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
function scholar_vsite_create($name, $mail, $domain){
  install_include(array(
      'node' 
  ));
  $properties = array(
      'name' => $name, 
      'type' => variable_get('scholar_content_type', 'scholarsite'), 
      'promote' => '0', 
      'purl' => array(
          'value' => $domain, 
          'provider' => 'spaces_og', 
          'id' => NULL 
      ), 
      'preset' => 'scholarsite', 
      'og_description' => "$domain's web site", 
      'theme' => 'scholar_theme_01', // TODO what is the default theme ? 
  );
  $node = install_create_node($title = $domain, $body = NULL, $properties = $properties);
  
  return $node;
}

