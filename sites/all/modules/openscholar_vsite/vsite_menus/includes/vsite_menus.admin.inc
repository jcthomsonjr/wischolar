<?php
/**
 * Form Controlls
 */

/*
 * The CP form for saving the block values and thier order
 */
function vsite_menus_settings_form($form_state){

  $space = vsite_get_vsite();
  if(!$space) return array();

  // just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-menus">';
  $form['#suffix'] = '</div>';

  $a_site_menus = variable_get('scholar_site_menus',array());
  // a_site_menu = array where key is menu_name and value is the "display name"

  //user_created

  //all that were avalible orig..
  $all_initial = $space->controllers->vsite_menu->get_multiple( array_keys($a_site_menus), 'original' );

  //Get the menu links for a menu (for this site)
  $menu_links = $space->controllers->vsite_menu->get( 'the_menu_key' );

  //$form = vsite_menus_settings_build_form($menu_links);
  $form['#menu'] =  "Primary Menu";

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('vsite_menus_settings_form_reset'),
  );

  return $form;

}

/**
 * Include the css in after_build so that it always appears with the form, even with a cached form
 */
function vsite_menus_settings_form_after_build($form, &$form_state) {
  //CSS To be included with the form
  drupal_add_css(drupal_get_path('module', 'vsite_menus') . '/theme/vsite_menus.css');
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

/**
 * Theme the menu settings form into a table.
 *
 * @ingroup themeable
 */
function theme_vsite_menus_settings_form($form) {
	drupal_add_tabledrag('vsite-menus-settings', 'order', 'sibling', 'menu-weight');

  $header = array(
    t($form['#menu']),
    t('Enabled'),
    t('Weight'),
    array('data' => t('Operations'), 'colspan' => '2'),
  );

  $rows = array();
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['hidden'])) {
      $element = &$form[$key];
      // Build a list of operations.
      $operations = array();
      foreach (element_children($element['operations']) as $op) {
        $operations[] = drupal_render($element['operations'][$op]);
      }
      while (count($operations) < 2) {
        $operations[] = '';
      }

      // Add special classes to be used for tabledrag.js.
      $element['key']['#attributes']['class'] = 'menu-key';
      $element['weight']['#attributes']['class'] = 'menu-weight';

      $row = array();
      $row[] = drupal_render($element['link_title']);
      $row[] = array('data' => drupal_render($element['hidden']), 'class' => 'checkbox');
      $row[] = drupal_render($element['weight']) . drupal_render($element['key']);
      $row = array_merge($row, $operations);

      $row = array_merge(array('data' => $row), $element['#attributes']);
      $row['class'] = !empty($row['class']) ? $row['class'] .' draggable' : 'draggable';
      $rows[] = $row;
    }
  }

  $output = '';
  if ($rows) {
    $output .= theme('table', $header, $rows, array('id' => 'vsite-menus-settings'));
  }
  $output .= drupal_render($form);
  return $output;
}
