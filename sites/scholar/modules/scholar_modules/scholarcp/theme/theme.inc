<?php

/**
 * Preprocessor for theme('admin_toolbar').
 */
function scholarcp_preprocess_scholarcp_toolbar(&$vars) {
  $vars['collapsed'] = TRUE;
  foreach ($vars['tree'] as $depth => $menus) {
    foreach ($menus as $href => $links) {
      $class = ($depth > 0) ? 'collapsed' : '';
      if ($depth > 0 && scholarcp_in_active_trail($href)) {
        $class = '';
        $vars['collapsed'] = FALSE;
      }
      $id = str_replace('/', '-', $href);

      // If we aren't on the top level menu, provide a way to get to the top level page.
      if ($depth > 0 && !empty($links)) {
        $links['view-all'] = array(
          'title' => t('View all'),
          'href' => $href,
        );
      }
      $vars["tree_{$depth}"][$id] = theme('links', $links, array('class' => "links clear-block $class", 'id' => "scholarcp-toolbar-{$id}"));
    }
  }
}

function theme_scholarcp_menu_radios($element) {
  
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