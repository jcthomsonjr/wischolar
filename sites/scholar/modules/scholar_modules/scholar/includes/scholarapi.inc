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


function scholar_get_logo($w=300,$h=false){
  $scholar = scholar_get_scholar();
  if(!$scholar) return false;
  
  if(!$scholar->settings['logo'] && !$scholar->settings['logo']['current_logo']) return false;
  
  $o_image = imageapi_image_open($scholar->settings['logo']['current_logo'],'imageapi_gd');
  
  if($o_image->info['width'] < $w && (!$h || $h < $o_image->info['height'])) return "/".$o_image->source;

  if(!$h){
  	$h = $w * ($o_image->info['height']/$o_image->info['width']);
  }
  
  $s_folder = $scholar->settings['logo']['current_logo'];
  $s_filename = file_check_path($s_folder);
  list($s_file_base,$s_file_ext) = split("\.",$s_filename,2);
  
  $s_resized_file = $s_file_base."_".$w."_".$h.".".$o_image->info['extension'];
  
  if(!file_check_location($s_resized_file,$s_folder)){
  	imageapi_toolkit_invoke('resize',$o_image,array($w,$h));
    imageapi_toolkit_invoke('close',$o_image,array($s_folder."/".$s_resized_file));
  }
  
  return "/".$s_folder."/".$s_resized_file;
}

