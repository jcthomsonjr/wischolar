<?php

/**
 * Theme the radio elements for the control panel
 *
 * @param fieldset $element
 * @return string html
 */
function theme_scholarmenu_radios($element) {
  
  $content = "";
  foreach ($element as $key => $item) {
    if(substr($key,0,1) == '#') continue;
    if(!strlen($content)){
      $content .= "<table id='menu_sort_table'>";
      $content .= "<tr><th>Menu Item</th><th></th>";
      foreach ($item['menu'] as $key2 => $rad) {
        if(substr($key2,0,1) == '#') continue;
        $content .= "<th>{$rad['#title']}</th>";
      }
      $content .= "</tr>";
    }
    
    $content .= "<tr class='draggable'><td>{$item['menu']['#title']}</td>";
    
    $content .= "<td>".drupal_render($item['weight'])."</td>";
    foreach ($item['menu'] as $key2 => $rad) {
      if(substr($key2,0,1) == '#') continue;  
      unset($rad['#title']);
      $content .= "<td>".drupal_render($rad)."</td>";
    }
    $content .= "</tr>";
  }
  $content .= "</table>";
  
  drupal_add_tabledrag('menu_sort_table', 'order', 'sibling', 'element-weight');
  
  return $content;
}