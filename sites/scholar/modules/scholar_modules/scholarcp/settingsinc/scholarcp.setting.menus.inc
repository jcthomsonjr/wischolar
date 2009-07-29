<?php 
/**
 * Provides theme selection for each site
 */
class scholarcp_setting_menus implements space_setting {
  
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'menus';
    }
  }

  function form($space, $value = array()) {
    
    $group_node = og_get_group_context();
    
    $form = array();
    $form['#title'] = 'Menus';
    
    // Description
    $form['menu_items'] = array(
      '#type' => 'fieldset',
      '#theme' => 'scholarcp_menu_radios',
    );
    $n_count = 0;
      
    $choices = array(t(variable_get('scholar_primary_menu_name',"Top Menu")), t(variable_get('scholar_secondary_menu_name',"Side Menu")), t('None'));
      
    if(variable_get('scholar_primary_menu',false)){
      $a_tree = menu_tree_page_data(variable_get('scholar_primary_menu',false));
      foreach ($a_tree as $element) {
        if ($element['link']['hidden']) continue;
        
        $mnode = menu_node_get_node($element['link']['mlid']);
        if($mnode){
          $a_groups = og_get_node_groups($mnode);
          if(!array_key_exists($group_node->nid,$a_groups)) continue; //is this node in the current group
        }
        
        $form['menu_items'][$element['link']['mlid']]['menu'] = array(
          '#type' => 'radios',
          '#title' => t($element['link']['title']),
          '#default_value' => 0,
          '#options' => $choices,
          '#weight' => $n_count--,
        );
        $form['menu_items'][$element['link']['mlid']]['weight'] = array(
          '#type' => 'hidden',
          '#default_value' => $n_count,
          '#attributes' => array('class' => 'element-weight'),
          '#weight' => $n_count,
        );
      }
    }
      
    if(variable_get('scholar_secondary_menu',false)){
      $a_tree = menu_tree_page_data(variable_get('scholar_secondary_menu',false));
      foreach ($a_tree as $element) {
        if ($element['link']['hidden']) continue;
        
        $mnode = menu_node_get_node($element['link']['mlid']);
        if($mnode){
          $a_groups = og_get_node_groups($mnode);
          if(!array_key_exists($group_node->nid,$a_groups)) continue; //is this node in the current group
        }
        
        $form['menu_items'][$element['link']['mlid']]['menu'] = array(
          '#type' => 'radios',
          '#title' => t($element['link']['title']),
          '#default_value' => 1,
          '#options' => $choices,
          '#weight' => $n_count--,
        );
        $form['menu_items'][$element['link']['mlid']]['weight'] = array(
          '#type' => 'hidden',
          '#default_value' => $n_count,
          '#attributes' => array('class' => 'element-weight'),
          '#weight' => $n_count,
        );
      }
    }
    
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
    //$value['nid'] = _scholar_node_autocomplete_title_to_nid($value['nid']);
    return $value;
  }
}
  
