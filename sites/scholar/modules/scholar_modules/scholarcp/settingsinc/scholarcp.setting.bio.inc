<?php 
/**
 * Provides theme selection for each site
 */
class scholarcp_setting_bio implements space_setting {
  
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'bio';
    }
  }

  function form($space, $value = array()) {
    $form = array();
  
    scholar_include('nodeautocomplete');
    $form['nid'] = scholar_node_autocomplete_element();
    $form['nid']['#default_value'] = $value['nid'] ? _scholar_node_autocomplete_nid_to_title($value['nid']) : '';
    $form['#title'] = 'bio';
  
    $form['include_title'] = array(
       '#type' => 'checkbox',
       '#title' => t('Include title'),
       '#default_value' => $value['include_title'] ? $value['include_title'] : 0,
    );
  
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
    $value['nid'] = _scholar_node_autocomplete_title_to_nid($value['nid']);
    return $value;
  }
}