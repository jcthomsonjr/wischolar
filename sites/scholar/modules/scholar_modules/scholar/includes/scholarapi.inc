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

/**
 * Return the menu tree object for a scholar site, adapted for the current page
 *
 * @param string $s_menu  (primary / secondary)
 * @param boolean $b_html (return formated html?)
 * @param boolean $b_check_expanded (allow expanded menus? slightly slower)
 */
function scholar_get_menu_tree($s_menu = 'primary', $b_html = true, $b_check_expanded = false){
  $space = scholar_get_scholar();
  
  switch ($s_menu){
    case 'secondary':
      $a_settings_menu = array_key_exists('menus',$space->settings)?$space->settings['menus']['secondary']:false;
      $s_def_menu = 'scholar_primary_menu';
    break;
    case 'primary':
    default:
      $a_settings_menu = array_key_exists('menus',$space->settings)?$space->settings['menus']['primary']:false;
      $s_def_menu = 'scholar_primary_menu';
  }
  
  if(!$a_settings_menu) return menu_tree( $s_def_menu );
  $n_found = 0;   
  
  if($b_check_expanded){
    $a_full_page_expanded = array_merge( menu_tree_page_data(variable_get('scholar_primary_menu',false)), 
                                           menu_tree_page_data(variable_get('scholar_secondary_menu',false)));
                                        
    //We must unfortunatly loop through the page data once to get the
    //correct expanded trees, the menu module does not provide an easy
    //way of retrieving a individual menu_node's tree (expanded)
    foreach ($a_full_page_expanded as $a_tree) {
    	if(!in_array($a_tree['link']['mlid'],$a_settings_menu)) continue;
    	$n_found++;
    	$a_settings_menu[array_search($a_tree['link']['mlid'],$a_settings_menu)] = $a_tree;
    	if($n_found >= count($a_settings_menu)) break;
    	break;
    }
  }
  
  if($n_found < count($a_settings_menu)){
    foreach ($a_settings_menu as $n_key => $n_mlid) {
    	if(!is_int($n_mlid)) continue;
    	$a_settings_menu[$n_key] = array('link' => menu_link_load($n_mlid), 'below' => false);
    }
  }
  
  
  if(!$b_html) return $a_settings_menu;
  
  return menu_tree_output($a_settings_menu);
}