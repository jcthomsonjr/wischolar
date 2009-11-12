<?php


/**
 * Theme function for contextual popups.
 */
function scholar_preprocess_scholar_admin_links(&$vars) {
$vars['links'] = theme('links',$vars['links']);
/*
  if (!empty($vars['links']) && is_array($vars['links'])) {
    $links = '';
    foreach ($vars['links'] as $link) {
      if (isset($link['href'])){
      $links .= l($link['title'], $link['href'], $link);
      } else {
        $links .= $link['title'];
      }
    }
        dpm($vars['links']);
    //$vars['links'] = $links;

    $vars['links'] = theme('links',$vars['links']);
  }
  */
}
