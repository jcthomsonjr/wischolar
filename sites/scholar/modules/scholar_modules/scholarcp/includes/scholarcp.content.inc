<?php 

/**
 * Function to return output on cp content page
 */
function scholarcp_content($type, $name = NULL, $filter=array()){
  $plural = ($type == 'all') ? 'All' : 's';
  
  $filter_form_classes = 'filter-form ' . 'filter-form-' . $type;
  $add_new_classes = 'add-new ' . 'add-new-' . $type;  
  $output = '<div class="' . $filter_form_classes. '">' . l(t('Filter '. $name . $plural), 'content') . '</div>'; 
  // $output .= drupal_get_form('scholarcp_content_filter_form', $type, $name);
   $output .= ($type == 'all') ? '' :  '<div class="' . $add_new_classes . '">' . l(t('+ add new '. $name), 'node/add/' . strtolower($type)) . '</div>';

  //initialize view to generate sessions output when viewing a conference
  $display_id = 'default';
  $view = views_get_view('scholarcp_content');
  $view->init();
  $view->set_display('default');
  $view -> set_items_per_page(15);
  
  //if $filter array is passed then load those arguments into the view result, otherwise just filter by type
  //$args = count($filter) ? $view->set_arguments(array($type, $filter['pubstatus'], $filter['taxonomy'])): $view->set_arguments(array($type));
  $view->set_arguments(array($type)); 
  $view -> execute();
  $output .= $view -> render();
  
  return $output;
}

function scholarcp_content_filter_form($form_state, $type, $name){

  $pub_options =  array(
  '2' => 'Any',
  '1' => 'Yes',
  '0' => 'No',
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
  '#default_value'  => 'test1',
  '#weight' => 1,
  // '#required' => TRUE,
  '#prefix' => '<div id="pubstatus">',
  '#suffix' => '</div>',
  );

  $form['scholarfilter']['taxonomy'] = array(
  '#title' => t('Category'),
  '#type' => 'radios',
  '#options' => _scholarcp_taxonomy_fillter_options($type),
  //  '#default_value'  => 'category3',
  '#weight' => 2,
  // '#required' => TRUE,
  '#prefix' => '<div id="category">',
  '#suffix' => '</div>',
  );
  
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
  
  //TODO: need to return the filter array to the form below
  
  $filter = array(
  'pubstatus' => $form_state['values']['pubstatus'],
  'term' => $form_state['values']['taxonomy'],
 );
 //return scholarcp_content($form_state['values']['type'], $form_state['values']['name'], $filter);
 }

function _scholarcp_taxonomy_fillter_options($type){

  //For testing purposes only - remove this after testing
  $options = array(
  'category1' => 'category1',
  'category2' => 'category2',
  'category3' => 'category3',
  );
   return $options;

  // TODO: are we using more than one Vocabulary per content type????
  $c = db_result(db_query(db_rewrite_sql("SELECT vid FROM {vocabulary} v
  INNER JOIN {vocabulary_node_types} n ON v.vid = n.vid WHERE n.type = '%s' 
  ORDER BY v.weight, v.name", 'v', 'vid'), $type));
  while ($data= db_fetch_object($c)) {
    $term_tree =taxonomy_get_tree($data->vid);
  }

  foreach($term_tree as $term){
    $options[$term->tid] = $term->name;
  }
  
  return $options;
}