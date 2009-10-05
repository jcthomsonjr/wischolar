<?php


/**
 * Find and return the custom Primary Links in the old site
 *
 * @param unknown_type $old
 * @return unknown
 */

function simport_get_menu_links($old, $ltype){
  
  $ltype_map = array(
  'primary' => 'scholar_menu_links',
  'secondary' => 'scholar_menu_links_secondary',
  );
  
  $custom_links = array();
  $pattern = '/(^node)\/([0-9]+)$/';

  if (is_array($old -> $ltype_map[$ltype]) && count($old -> $ltype_map[$ltype])){
    foreach($old -> $ltype_map[$ltype] as $link){           
     
     if(isset($matches)){unset($matches);}
     
      preg_match($pattern,$link['path'], $matches);
      if(!empty($matches)){
        $custom_links[] = array(
        'nid' => $matches[2],
        'title' => $link['title'],
        'path' => $link['path'],
        'primary' => $ltype_map[$ltype] == 'scholar_menu_links' ? 1 : 0,
        );
      }
    }
  }
  return $custom_links;
}

/**
 *  Load menu info and save node
 *
 * @param unknown_type $link
 * @param unknown_type $nid
 * @param unknown_type $primary
 */
function simport_add_custom_menu_links($link, $nid, $primary = 1){
  $node = node_load(array('nid' => $nid));
  
  if(!is_object($node)){
    return;
  }
 
  $node -> menu  = array(
  'mlid' => 0,
  'module' => menu,
  'has_children' => 0,
  'customized' => 0,
  'options' => array(),
  'expanded' => 0,
  'parent_depth_limit' => 8,
  'link_title' => $link['title'],
  'parent' => ($primary = 1) ? 'features:0' : 'scholar_secondary_menu:0',
  'weight' => 0,
  'plid' => 0,
  'menu_name' => ($primary = 1) ? 'features' : 'scholar_secondary_menu',
  );
 
  //save the menu link
  node_save($node);
}




