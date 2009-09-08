<?php 

/**
 * Content node submission form.
 */
function vsite_users_content_profile_node_form($form) {
  $output = "\n<div class=\"node-form\">\n";

  $buttons = drupal_render($form['buttons']);
  drupal_add_css('<style type="text/css"> .vertical-tabs { display: none; } </style>');
  
  $vert_tabs = drupal_render($form['vertical_tabs']);
  
  // Everything else gets rendered here
  // field and the submit buttons.
  
  $output .= "  <div class=\"standard\">\n";
  $output .= drupal_render($form);
  $output .= "  </div>\n";

  $output .= $buttons;
  $output .= "</div>\n";

  return $output;
}

/**
 * vsite_suers_profile should use the cp layout
 * 
 * @param $form
 * @return string
 */
function theme_vsite_users_profile_node_form($form){
  return vsite_users_content_profile_node_form($form);
}