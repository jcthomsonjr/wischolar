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

function theme_scholar_logo($preset = false, $alt = '' , $title = '', $attributes = ''){
  $scholar = scholar_get_scholar();
  if(!$scholar || !$scholar->settings['logo'] && !$scholar->settings['logo']['current_logo']){
  	//@todo DO DEFAULT IMAGE
  	return false;
  }	
	
  if($preset){
    return theme('imagecache', $preset, $scholar->settings['logo']['current_logo'], $alt, $title,  $attributes);
  }else{
  	$attributes = drupal_attributes($attributes);
    $url = imagecache_create_url($presetname, $path);
    return '<img src="/'.$scholar->settings['logo']['current_logo'] .'" alt="'. check_plain($alt) .'" title="'. check_plain($title) .'" '. $attributes .' />';
  } //use imagecache? or orig?
  
}

