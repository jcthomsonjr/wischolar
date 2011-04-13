<?php
/**
 * Form Controls
 */

function _vsite_menus_get_menus() {
  $menus = variable_get('scholar_site_menus', array(
    'features' => 'Primary Menu',
    'scholar_secondary_menu' => 'Secondary Menu',
  ));

  $menus += array('none' => 'Not in a Menu');

  return $menus;
}

/*
 * The CP form for saving the block values and thier order
 */
function vsite_menus_settings_form($form_state){

  $space = vsite_get_vsite();
  if(!$space) return array();

  // just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-menus">';
  $form['#suffix'] = '</div>';
  $form['conf'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => array('vsite_menus_settings'),
  );

  $a_site_menus = _vsite_menus_get_menus();

  //user_created

  //all that were avalible orig..
  $all_initial = $space->controllers->vsite_menu->get_multiple(array_keys($a_site_menus));

  //Get the menu links for a menu (for this site)
  //$menu_links = $space->controllers->vsite_menu->get( 'the_menu_key' );
  $menus = array();

  //$form = vsite_menus_settings_build_form($menu_links);
  foreach ($all_initial as $key => $link) {
    $path = $link['link_path'];
    $menu = menu_get_item($path);
    if (!$menu['access']) continue;

    $frags = explode(':', $key);
    if (count($frags) == 1) {
      // this link isn't in a menu already
      $link['menu_name'] = 'none';
      $menus[$frags[0]] = $link;
    }
    else {
      // this link is in a menu.
      // if it's in one of the accepted menus, put it there
      // otherwise, put it in none

      if (isset($a_site_menus[$frags[0]])) {
        $link['menu_name'] = $frags[0];
        $menus[$frags[1]] = $link;
      }
      else {
        $link['menu_name'] = 'none';
        $menus[$frags[1]] = $link;
      }
    }
  }

  foreach ($menus as $key => $link) {
    $form['conf'][$link['menu_name']][$key] = array(
      '#tree' => TRUE,
      '#weight' => $link['weight'],
      'name' => array(
        '#type' => 'textfield',
        '#size' => 30,
        '#default_value' => !empty($link['link_title']) ? $link['link_title'] : ucwords(str_replace('_', ' ', $key)),
      ),
      'region' => array(
        '#type' => 'select',
        '#options' => $a_site_menus,
        '#default_value' => $link['menu_name'],
        '#attributes' => array(
          'class' => 'field-region-select field-region-'. $link['menu_name'],
        ),
      ),
      'weight' => array(
        '#type' => 'textfield',
        '#default_value' => $link['weight'],
        '#size' => 3,
        '#attributes' => array(
          'class' => 'field-weight field-weight-'. $link['menu_name'],
        ),
      ),
      'region-old' => array(
        '#type' => 'hidden',
        '#value' => $link['menu_name'],
      ),
    );

    if ($link['user_created']) {
      $form['conf'][$link['menu_name']][$key]['delete'] = array(
        '#type' => 'checkbox',
        '#default_value' => 0,
      );
    }
    else {
      $form['conf'][$link['menu_name']][$key]['delete'] = array(
        '#type' => 'markup',
        '#value' => t('Can not delete'),
      );
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('vsite_menus_settings_form_reset'),
  );

  $form['#after_build'][] = 'vsite_menus_settings_form_after_build';

  return $form;

}

/**
 * Include the css in after_build so that it always appears with the form, even with a cached form
 */
function vsite_menus_settings_form_after_build($form, &$form_state) {
  //CSS To be included with the form
  drupal_add_js('misc/tableheader.js');
  drupal_add_js(drupal_get_path('module', 'nodeformcols') . '/js/nodeformcols.js');
  drupal_add_css(drupal_get_path('module', 'vsite_menus') . '/theme/vsite_menus.css');

  $regions = _vsite_menus_get_menus();    // this line is why I needed to copy it
  foreach ($regions as $region => $title) {
    if (is_array($form['conf'][$region])) {
      uasort($form['conf'][$region], "element_sort");
    }
    drupal_add_tabledrag('fields', 'match', 'sibling', 'field-region-select', 'field-region-'. $region, NULL, FALSE);
    drupal_add_tabledrag('fields', 'order', 'sibling', 'field-weight', 'field-weight-'. $region);
  }
  return $form;
}

/**
 * Reset function for the CP blocks form to return the settings for the current theme to defaults
 */
function vsite_menus_settings_form_reset($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;

//  foreach (array_keys(vsite_layout_get_pagetypes($space)) as $s_page_type) {
//    $space->controllers->context->del('openscholar-feature-'.$s_page_type.":reaction:block:".$space->group->og_theme);
//  }
}

/**
 * Save Handler for the CP Menus Form
 */
function vsite_menus_settings_form_submit($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;

  $menus = $space->controllers->vsite_menu->get();

  foreach ($form_state['values'] as $key => $data) {
    if (!is_array($data)) continue;

    $link = &$menus[$data['region-old']][$data['region-old'].':'.$key];
    if ($data['region-old'] != $data['region']) {
      $menus[$data['region']][$data['region'].':'.$key] = &$link;
      unset($menus[$data['region-old']][$data['region-old'].':'.$key]);
    }

    $link['link_title'] = $data['name'];
    $link['menu_name'] = $data['region'];
    $link['weight'] = $data['weight'];

    if ($data['delete']) {
      unset($menus[$data['region']][$data['region'].':'.$key]);
    }

  }

  foreach ($menus as $key => $data) {
    $space->controllers->vsite_menu->set($key, $data);
  }
}


/**
 * Helper function for menu_overview_form().
 */
function vsite_menus_settings_build_form($tree) {
  $form = array('#tree' => TRUE);

  foreach ($tree as $s_key => $item) {
    $title = '';

    $form[$s_key]['#item'] = $item;

    $form[$s_key]['#attributes'] = $item['hidden'] ? array('class' => 'menu-disabled') : array('class' => 'menu-enabled');
    $form[$s_key]['link_title']['#value'] = l($item['link_title'], $item['link_path']) . ($item['hidden'] ? ' ('. t('disabled') .')' : '');
    $form[$s_key]['hidden'] = array(
      '#type' => 'checkbox',
      '#default_value' => !$item['hidden'],
    );

    $form[$s_key]['weight'] = array(
      '#type' => 'weight',
      '#delta' => 50,
      '#default_value' => isset($form_state[$s_key]['weight']) ? $form_state[$s_key]['weight'] : $item['weight'],
    );
    $form[$s_key]['key'] = array(
      '#type' => 'hidden',
      '#value' => $s_key,
    );

    // Build a list of operations.
    $operations = array();

    // Only items created by the user can be deleted.
    if ($item['user_created'] == 1) {
      $operations['delete'] = l(t('delete'), 'admin/build/menu/item/'. $item['mlid'] .'/delete');
    }
    // Set the reset column.
    elseif ($item['customized']) {
      $operations['reset'] = l(t('reset'), 'admin/build/menu/item/'. $item['mlid'] .'/reset');
    }

    $form[$s_key]['operations'] = array();
    foreach ($operations as $op => $value) {
      $form[$s_key]['operations'][$op] = array('#value' => $value);
    }

  }
  return $form;
}

