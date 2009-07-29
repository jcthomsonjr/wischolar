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
    $s_current = '';
    
    if(!variable_get('scholar_primary_menu',false) || !variable_get('scholar_secondary_menu',false)){
      return $form;
    }
    
    $a_primary = menu_load(variable_get('scholar_primary_menu',false));
    $a_secondary = menu_load(variable_get('scholar_secondary_menu',false));
    
    $choices = array('primary' => t($a_primary['title']),
                     'secondary' => t($a_secondary['title']),
                     '' => t('None'));
      

    $a_tree = menu_tree_page_data(variable_get('scholar_primary_menu',false));    
    foreach ($a_tree as $element) {
      if ($element['link']['hidden']) continue;
        
      $mnode = menu_node_get_node($element['link']['mlid']);
      if($mnode){
        $a_groups = og_get_node_groups($mnode);
        if(!array_key_exists($group_node->nid,$a_groups)) continue; //is this node in the current group
      }
        
      if(array_key_exists($element['link']['mlid'],$space->settings['menus']['menu_items'])){
        $s_current = $space->settings['menus']['menu_items'][$element['link']['mlid']]['menu'];
        $n_count = $space->settings['menus']['menu_items'][$element['link']['mlid']]['weight'];
      }else{
        $s_current = '';
        $n_count++; //put it after the last item
      }
      $form['menu_items'][$element['link']['mlid']]['menu'] = array(
        '#type' => 'radios',
        '#title' => t($element['link']['title']),
        '#default_value' => $s_current,
        '#options' => $choices,
        '#weight' => $n_count,
      );
      $form['menu_items'][$element['link']['mlid']]['weight'] = array(
        '#type' => 'hidden',
        '#default_value' => $n_count,
        '#attributes' => array('class' => 'element-weight'),
        '#weight' => $n_count,
      );
    }
      
    $a_tree = menu_tree_page_data(variable_get('scholar_secondary_menu',false));
    foreach ($a_tree as $element) {
      if ($element['link']['hidden']) continue;
        
      $mnode = menu_node_get_node($element['link']['mlid']);
      if($mnode){
        $a_groups = og_get_node_groups($mnode);
        if(!array_key_exists($group_node->nid,$a_groups)) continue; //is this node in the current group
      }
        
      if(array_key_exists($element['link']['mlid'],$space->settings['menus']['menu_items'])){
        $s_current = $space->settings['menus']['menu_items'][$element['link']['mlid']]['menu'];
        $n_count = $space->settings['menus']['menu_items'][$element['link']['mlid']]['weight'];
      }else{
        $s_current = '';
        $n_count++; //put it after the last item
      }
      $form['menu_items'][$element['link']['mlid']]['menu'] = array(
        '#type' => 'radios',
        '#title' => t($element['link']['title']),
        '#default_value' => $s_current,
        '#options' => $choices,
        '#weight' => $n_count,
      );
      $form['menu_items'][$element['link']['mlid']]['weight'] = array(
        '#type' => 'hidden',
        '#default_value' => $n_count,
        '#attributes' => array('class' => 'element-weight'),
        '#weight' => $n_count,
      );
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
  
