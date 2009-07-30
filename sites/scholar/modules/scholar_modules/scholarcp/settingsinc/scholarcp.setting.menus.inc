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
    $scholar = scholar_get_scholar();
    
    $form = array();
    $form['#title'] = 'Menus';
    if(!$space) return $form; 
    
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
      

    $a_tree = menu_tree_all_data(variable_get('scholar_primary_menu',false));    
    foreach ($a_tree as $element) {
      if ($element['link']['hidden']) continue;
        
      $mnode = menu_node_get_node($element['link']['mlid']);
      if($mnode){
        $a_groups = og_get_node_groups($mnode);
        if(!array_key_exists($scholar->group->nid,$a_groups)) continue; //is this node in the current group
      }
        
      if(array_key_exists($element['link']['mlid'],$space->settings['menus']['menu_items'])){
        $s_current = $space->settings['menus']['menu_items'][$element['link']['mlid']]['menu'];
        $n_count = $space->settings['menus']['menu_items'][$element['link']['mlid']]['weight'];
      }else{
        $s_current = 'primary';
        $n_count = 100; //put it after the last item
      }
      $form['menu_items'][$element['link']['mlid']]['#weight'] = $n_count;
      $form['menu_items'][$element['link']['mlid']]['menu'] = array(
        '#type' => 'radios',
        '#title' => t($element['link']['title']),
        '#default_value' => $s_current,
        '#options' => $choices,
      );
      $form['menu_items'][$element['link']['mlid']]['weight'] = array(
        '#type' => 'hidden',
        '#default_value' => $n_count,
        '#attributes' => array('class' => 'element-weight'),
      );
    }
      
    $a_tree = menu_tree_all_data(variable_get('scholar_secondary_menu',false));
    foreach ($a_tree as $element) {
      if ($element['link']['hidden']) continue;
        
      $mnode = menu_node_get_node($element['link']['mlid']);
      if($mnode){
        $a_groups = og_get_node_groups($mnode);
        if(!array_key_exists($scholar->group->nid,$a_groups)) continue; //is this node in the current group
      }
        
      if(array_key_exists($element['link']['mlid'],$space->settings['menus']['menu_items'])){
        $s_current = $space->settings['menus']['menu_items'][$element['link']['mlid']]['menu'];
        $n_count = $space->settings['menus']['menu_items'][$element['link']['mlid']]['weight'];
      }else{
        $s_current = 'secondary';
        $n_count = 100; //put it after the last item
      }
      $form['menu_items'][$element['link']['mlid']]['#weight'] = $n_count;
      $form['menu_items'][$element['link']['mlid']]['menu'] = array(
        '#type' => 'radios',
        '#title' => t($element['link']['title']),
        '#default_value' => $s_current,
        '#options' => $choices,
      );
      $form['menu_items'][$element['link']['mlid']]['weight'] = array(
        '#type' => 'hidden',
        '#default_value' => $n_count,
        '#attributes' => array('class' => 'element-weight'),
      );
    }
    
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
    
    $value = self::create_menus($value); 
    
    return $value;
  }
  
  public static function create_menus($value){
    $a_primary = array();
    $a_secondary = array();
    foreach ($value['menu_items'] as $mlid => $menu_info) {
      if($menu_info['menu'] == 'primary') $a_primary[] = $mlid;
      if($menu_info['menu'] == 'secondary') $a_secondary[] = $mlid;
    }
    
    self::$weight_lookup = $value['menu_items'];
    usort($a_primary, array("self", "order_by_weight"));
    usort($a_secondary, array("self", "order_by_weight"));
    
    $value['primary'] = $a_primary;
    $value['secondary'] = $a_secondary;
    return $value;
  }
  
  private static $weight_lookup;
  private static function order_by_weight($a,$b){
        $aw = self::$weight_lookup[$a]['weight'];
        $bw = self::$weight_lookup[$b]['weight'];
        if ($aw == $bw) {
            return 0;
        }
        return ($aw > $bw) ? 1 : -1;
  }
}
  
