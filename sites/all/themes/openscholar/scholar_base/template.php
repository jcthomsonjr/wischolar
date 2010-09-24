<?php

function scholar_base_theme(&$existing, $type, $theme, $path) {
  return zen_theme($existing, $type, $theme, $path);
}


function scholar_base_preprocess_page($vars){

  $regions = array (   // TODO do this programatically
    'left' => $vars['header_left'],
    'main' => $vars['header_main'],
    'right' => $vars['header_right'],
  );

  $non_empty_regoins = array_filter($regions, "__scholar_base_is_empty");

  $my_body_classes = 'header-' . implode('-', array_keys($non_empty_regoins));

  $vars['body_classes'] .= " " . $my_body_classes;

}

/**
  * Removes 'inline' class from links in nodes
  */
function scholar_base_preprocess_node(&$vars, $hook) {
  $vars['links'] = theme('links', $vars['node']->links, array('class' => 'links'));
  }

function __scholar_base_is_empty($s){
  return $s ? TRUE : FALSE;
}

function phptemplate_node_submitted($node){
  return t('@datetime',
   array(
    //'!username' => theme('username', $node),
     '@datetime' => format_date($node->created),
  ));
}

/**
 * Generates a themed set of links for node types associated with
 * the current active contexts.
 */
function scholar_base_context_links($links) {
  $output = array();
  foreach ($links as $link) {
    $options = $link;
    $options['attributes']['class'] = isset($link['attributes']['class']) ? $link['attributes']['class'] : 'context-button';
    //if(!is_array($options['query'])) $options['query'] = array();
    //$options['query']['destination'] = $_GET['q'];

    if (!empty($link['custom'])) {
      $output[]= l($link['title'], $link['href'], $options);
    }
    else {
      $output[]= l(t('Add !type', array('!type' => $link['title'])), $link['href'], $options);
    }
  }

  if($output){
    $output = theme('item_list', $output,  $title = NULL, $type = 'ul', $attributes = array("class" => "context-links"));
    //$output = '<div class = "context-links">' . $output . '</div>';
  }
  return $output;
}
