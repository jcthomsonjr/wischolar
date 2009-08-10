<?php 

/**
 * Function to return output on cp content page
 */
function cp_content($type = NULL, $name = NULL){
  //element classes for 'add new' link
  $add_new_classes = 'add-new ' . 'add-new-' . $type;  
   //link to add new content
  $output .=  isset($type) ? '<div class="' . $add_new_classes . '">' . l(t('+ add new '. $name), 'node/add/' . strtolower($type)) . '</div>' : '' ;

  //adding view output
  $output .= views_page($view_name = 'cp_content', $display = 'default', $arg = $type);
  return $output;
}
