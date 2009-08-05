<?php 

/**
 * Function to return output on scholarcp content page
 */
function scholarcp_content($type = NULL, $name = NULL){
  $plural = ($type == 'all') ? 'All Content' : 's';
  $filter_form_classes = 'filter-form ' . 'filter-form-' . $type;
  $add_new_classes = 'add-new ' . 'add-new-' . $type;  
  
  //adding clickable link - possible to use for Jquery actions later
  $output = '<div class="' . $filter_form_classes. '">' . l(t('Filter '. $name . $plural), 'scholarcp/content/'. $type) . '</div>'; 
  
  //link to add new content
  $output .= ($type == 'all') ? '' :  '<div class="' . $add_new_classes . '">' . l(t('+ add new '. $name), 'node/add/' . strtolower($type)) . '</div>';
  
  //adding view output
  $output .= views_page($view_name = 'scholarcp_content', $display = 'page', $arg = $type);
  return $output;
}
