<?php

/**
 * Provides theme selection for each site
 */
class vsite_menus_menus implements vsite_setting {
  
  var $id;
  var $weight = -2;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'menus';
    }
  }

  function form($space, $value = array()) {
    vsite_include('vsiteapi');
    $scholar = vsite_get_vsite();
    
    $form = array();
    $form['#title'] = 'Menus';
    if (!$space) return $form;
    
    // Description
    $form['menu_items'] = array(
      '#type' => 'fieldset',
      '#theme' => 'vsite_menus_radios',
    );
    $n_count = 0;
    $s_current = '';
    
    if (!variable_get('scholar_primary_menu', FALSE) || !variable_get('scholar_secondary_menu', FALSE)) {
      return $form;
    }
    
    $a_primary = menu_load(variable_get('scholar_primary_menu', FALSE));
    $a_secondary = menu_load(variable_get('scholar_secondary_menu', FALSE));
    
    $choices = array('primary' => t($a_primary['title']), 'secondary' => t($a_secondary['title']), '' => t('None'));

    $disabled_choices = self::get_disabled_menus();
    
    foreach ($disabled_choices as $disabled) $choices[$disabled] .= " (disabled)";
    
    $a_disabled_features = array_intersect_key(features_get_component_map('menu'), vsite_content_types(FEATURE_DISABLED));
    $a_disabled_links = array_keys(array_intersect(features_get_component_map('menu'), $a_disabled_features));
    
    $a_feature_links = features_get_component_map('menu');
//    $customizers = spaces_customizers();
//    $menu_customizer = $customizers['menu']; //menu customizer
    
    foreach ($choices as $s_menu => $s_menu_name) {
      vsite::$override_allow_feature_access = TRUE;
      $a_tree = menu_tree_all_data(variable_get("scholar_{$s_menu}_menu", FALSE));
      vsite::$override_allow_feature_access = FALSE;
      
      foreach ($a_tree as $element) {
        if ($element['link']['hidden']) continue;
        
        $mnode = menu_node_get_node($element['link']['mlid']);
        if ($mnode) {
          $a_groups = og_get_node_groups($mnode);
          if (!array_key_exists($scholar->group->nid, $a_groups)) continue; //is this node in the current group
        }elseif (is_array($element['link']['options']) && is_array($element['link']['options']['attributes']) && array_key_exists('site', $element['link']['options']['attributes'])) {
          //This is a custom link for another site
          if($scholar->group->nid != $element['link']['options']['attributes']['site']) continue;
        }
        
        $a_menus_settings = $space->controllers->variable->get('vsite_setting_menus');
        if (is_array($a_menus_settings['menu_items']) &&
           array_key_exists($element['link']['mlid'], $a_menus_settings['menu_items'])) {
          $s_current = $a_menus_settings['menu_items'][$element['link']['mlid']]['menu'];
          $n_count = $a_menus_settings['menu_items'][$element['link']['mlid']]['weight'];
        }
        else {
          $s_current = $s_menu;
          $n_count = 100; //put it after the last item
        }
        
        $form['menu_items'][$element['link']['mlid']]['#weight'] = $n_count;
        $form['menu_items'][$element['link']['mlid']]['menu'] = array(
          '#type' => 'select',
          '#title' => t($element['link']['title']),
          '#default_value' => $s_current,
          '#options' => $choices,
          '#disabled_options' => $disabled_choices,
        );
        
        _menu_check_access($element['link'], explode('/', $element['link']['link_path']));
        if (in_array($element['link']['link_path'], $a_disabled_links) || !$element['link']['access']) {
          $form['menu_items'][$element['link']['mlid']]['menu']['#disabled'] = TRUE;//Disable private features
        }
        
        $form['menu_items'][$element['link']['mlid']]['weight'] = array(
          '#type' => 'hidden',
          '#default_value' => $n_count,
          '#attributes' => array('class' => 'element-weight'),
        );
        $form['menu_items'][$element['link']['mlid']]['delete'] = array(
          '#type' => (isset($element['link']['options']['attributes']['site']))?'checkbox':'hidden',
          '#default_value' => 0,
        );
      }//Each Menu Item
    }//Each Menu
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
    
    $value = self::create_menus($value);
    
    $a_disabled_menus = self::get_disabled_menus();
    if (count($value['primary']) && in_array('primary', $a_disabled_menus)) {
      $a_primary = menu_load(variable_get('scholar_primary_menu', FALSE));
      drupal_set_message("The [" . t($a_primary['title']) . "] menu has [" . count($value['primary']) . "] entries but is not in the site layout.  You can move it into the page layout on the " . l('layout appearance', 'cp/appearance/layout') . " page.", 'warning');
    }
    elseif (count($value['secondary']) && in_array('secondary', $a_disabled_menus)) {
      $a_secondary = menu_load(variable_get('scholar_secondary_menu', FALSE));
      drupal_set_message("The [" . t($a_secondary['title']) . "] menu has [" . count($value['secondary']) . "] entries but is not in the site layout.  You can move it into the page layout on the " . l('layout appearance', 'cp/appearance/layout') . " page.", 'warning');
    }
    
    return $value;
  }
  
//  function submit_modify_space(&$space, $value) {
//    // @todo rewite customizer
//    //self::apply_customizers($space, $value);
//  }
  
  private static function apply_customizers(&$space, $value) {
    
    $a_feature_links = features_get_component_map('menu');
    $customizers = spaces_customizers();
    $menu_customizer = $customizers['menu']; //menu customizer
    
    foreach ($value['menu_items'] as $mlid => $menu_info) {
      if (!$menu_info['customizer']) continue;
      
      if (array_key_exists(key($menu_info['customizer']), $a_feature_links)) {
        $space->customizer['menu'] = $menu_customizer->submit($space, $a_feature_links[key($menu_info['customizer'])], $menu_info['customizer']);
      }
    }
  }
  
  public static function create_menus($value) {
    $a_primary = array();
    $a_secondary = array();
    foreach ($value['menu_items'] as $mlid => $menu_info) {
      $b_delete = (array_key_exists('delete', $menu_info) && $menu_info['delete']);
      if (!$b_delete && $menu_info['menu'] == 'primary') $a_primary[] = $mlid;
      if (!$b_delete && $menu_info['menu'] == 'secondary') $a_secondary[] = $mlid;
      
      if ($b_delete) {
        $nid = menu_node_get_node($mlid, FALSE);
        // Is this a menu_node item?
        if (!empty($nid)) {
          menu_node_delete($nid, $mlid);
        }
        menu_link_delete($mlid);
        unset($value['menu_items'][$mlid]);
        
      }
      elseif (array_key_exists('delete', $menu_info)) {
        unset($value['menu_items'][$mlid]['delete']);//no use saving this
      }
      
    }
    
    self::$weight_lookup = $value['menu_items'];
    usort($a_primary, array("self", "order_by_weight"));
    usort($a_secondary, array("self", "order_by_weight"));
    
    $value['primary'] = $a_primary;
    $value['secondary'] = $a_secondary;
    return $value;
  }
  
  private static $weight_lookup;
  private static function order_by_weight($a, $b) {
        $aw = self::$weight_lookup[$a]['weight'];
        $bw = self::$weight_lookup[$b]['weight'];
        if ($aw == $bw) {
            return 0;
        }
        return ($aw > $bw) ? 1 : -1;
  }
  
  /**
   * Returns an array with any menus that are not used in the layout
   *
   * @return unknown_type
   */
  public static function get_disabled_menus() {
    $disabled_choices = array('vsite_menus_0' => 'primary', 'vsite_menus_1' => 'secondary');//If these blocks are not used they will be disabled
    foreach (vsite_layout_get_pagetypes($space) as $s_page_type => $s_name) {
      $a_region_wgts = vsite_layout_region_widgets($space, $s_page_type);
      if (!array_key_exists('unused', $a_region_wgts)) {
        $disabled_choices = array(); //nothing is in unused
      }
      else {
        $a_still_disabled = array();
        foreach ($a_region_wgts['unused'] as $wgt) if (array_key_exists($wgt['module'] . "_" . $wgt['delta'], $disabled_choices)) $a_still_disabled[$wgt['module'] . "_" . $wgt['delta']] = $disabled_choices[$wgt['module'] . "_" . $wgt['delta']];
        $disabled_choices = $a_still_disabled;
      }
      
      if (!count($disabled_choices)) break;
    }//Enable menus that are in layouts
    
    return $disabled_choices;
  }
}
  
