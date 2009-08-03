<?php 

/**
 * Function to return output on cp content page
 */
function scholarcp_content($type = 'all', $name = NULL, $tax=NULL, $pubstatus = NULL){
  $plural = ($type == 'all') ? 'All Content' : 's';
  
  $filter_form_classes = 'filter-form ' . 'filter-form-' . $type;
  $add_new_classes = 'add-new ' . 'add-new-' . $type;  
  $output = '<div class="' . $filter_form_classes. '">' . l(t('Filter '. $name . $plural), 'content') . '</div>'; 
   $output .= drupal_get_form('scholarcp_content_filter_form', $type, $name, $tax, $pubstatus);
   $output .= ($type == 'all') ? '' :  '<div class="' . $add_new_classes . '">' . l(t('+ add new '. $name), 'node/add/' . strtolower($type)) . '</div>';

  //initialize view to generate sessions output when viewing a conference
  $display_id = 'default';
  $view = views_get_view('scholarcp_content');
  $view->init();
  $view->set_display('default');
  $view -> set_items_per_page(15);
  
  //if $filter array is passed then load those arguments into the view result, otherwise just filter by type
  //$args = count($filter) ? $view->set_arguments(array($type, $filter['pubstatus'], $filter['taxonomy'])): $view->set_arguments(array($type));
  $view->set_arguments(array($type, $tax, _scholarcp_translate_pubstatus($pubstatus))); 
  $view -> execute();
  $output .= $view -> render();
  
  return $output;
}

function  _scholarcp_translate_pubstatus($pubstatus){
  
  $map = array(
 'any' => '0+1',
 'published' => '1',
 'unpublished' => '0',
  ); 
  return $map[$pubstatus];
 }


function scholarcp_content_filter_form($form_state, $type, $name, $tax = NULL, $pubstatus = NULL){

 
  $pub_options =  array(
  'any' => 'Any',
  'published' => 'Yes',
  'unpublished' => 'No',
  );

  $form['scholarfilter'] = array(
  '#type' => 'fieldset',
  '#collapsible' => FALSE,
  '#collapsed' => FALSE,
  '#weight' => 0,
  );

  $form['scholarfilter']['pubstatus'] = array(
  '#title' => t('Published'),
  '#type' => 'radios',
  '#options' => $pub_options,
  '#default_value'  => $pubstatus ,
  '#weight' => 1,
  // '#required' => TRUE,
  '#prefix' => '<div id="pubstatus">',
  '#suffix' => '</div>',
  );

  //if no taxonomy is set then do not show this as a filtering option
  if (_scholarcp_taxonomy_fillter_options($type)){
  
  $form['scholarfilter']['taxonomy'] = array(
  '#title' => t('Category'),
  '#type' => 'radios',
  '#options' => _scholarcp_taxonomy_fillter_options($type),
  '#default_value'  => $tax,
  '#weight' => 2,
  '#prefix' => '<div id="category">',
  '#suffix' => '</div>',
  );
  }
  
  $form['scholarfilter']['type'] = array(
  '#type' => 'hidden',
  '#value' => $type,
   );
   
  $form['scholarfilter']['name'] = array(
  '#type' => 'hidden',
  '#value' => $name,
   );

  $form['scholarfilter']['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Submit'),
  '#weight' => 3,
  );

  return $form;
}

/**
 * scholarcp_content_filter_form_submit()
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function scholarcp_content_filter_form_submit($form, &$form_state){

 $filter_str =  'scholarcp/content/' . $form_state['values']['type'] . '/';
 $filter_str .= empty($form_state['values']['taxonomy']) ? 'all' : $form_state['values']['taxonomy'];
 if(!empty($form_state['values']['pubstatus'])){
   $filter_str .= '/' .  $form_state['values']['pubstatus'];
 }
 drupal_goto($filter_str);
 //return scholarcp_content($form_state['values']['type'], $form_state['values']['name'], $filter);
 }

function _scholarcp_taxonomy_fillter_options($type){

  //For testing purposes only - remove this after testing
 /* $options = array(
  'category1' => 'category1',
  'category2' => 'category2',
  'category3' => 'category3',
  );
   return $options;*/

  // TODO: are we using more than one Vocabulary per content type????
  $c = db_query(db_rewrite_sql("SELECT v.vid FROM {vocabulary} v
  INNER JOIN {vocabulary_node_types} n ON v.vid = n.vid WHERE n.type = '%s' 
  ORDER BY v.weight, v.name", 'v', 'vid'), $type);
  while ($data= db_fetch_object($c)) {
    $term_tree =taxonomy_get_tree($data->vid);
  }

  if (count($term_tree)){
  foreach($term_tree as $term){
    $options[$term->name] = $term->name;
  }
  
  return $options;
  } 
  
  else{
    return false;
  }
  
}