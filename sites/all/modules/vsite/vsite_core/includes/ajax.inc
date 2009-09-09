<?php


/**
 * construct a link with confirmation message (yes/no)
 * @param $text text to display (i.e. "delete")
 * @param $dest the destination url if user click "yes" ( a ctools ajax link)
 * @param $alt
 * 
 * usage example : vsite_ajax_text_button_confirm('delete' , 'vsite_try_js', 'deltet this');
 */
function vsite_ajax_text_button_confirm($text, $dest, $alt){
  drupal_add_js(drupal_get_path('module', 'vsite') . '/theme/vsite_ajax_confirm.js');
  drupal_add_css(drupal_get_path('module', 'vsite') . '/theme/vsite_ajax_confirm.css');
  
  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  
  $res = '<span>';
  $res .= '<span class="vsite-confirm-wrapper">';
  $res .= l($text, '#', array(
    'attributes' => array(
      'class' => 'vsite-pls-confirm' 
    ) 
  ));
  $res .= '<span class = "vsite-confirm-message">';
  $yes = ctools_ajax_text_button('yes', $dest, $alt, $class = '', $type = 'ctools-use-ajax');
  $no = l('no', '#');
  $res .= 'Are you sure? ' . $yes . '/' . $no;
  $res .= '</span>';
  $res .= '</span>';
  $res .= '</span>';
  return l($res, '', array(
    'html' => TRUE, 
    'attributes' => array(
      'title' => $alt 
    ) 
  ));

}