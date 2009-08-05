<?php 

/**
 * Function to return output on scholarcp content page
 */
function scholarcp_content($type = NULL, $name = NULL){
  //element classes for 'add new' link
  $add_new_classes = 'add-new ' . 'add-new-' . $type;  
   //link to add new content
  $output .=  isset($type) ? '<div class="' . $add_new_classes . '">' . l(t('+ add new '. $name), 'node/add/' . strtolower($type)) . '</div>' : '' ;

  //adding view output
  $output .= views_page($view_name = 'scholarcp_content', $display = 'page', $arg = $type);
  return $output;
}
