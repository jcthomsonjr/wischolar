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
    if (!$link['external']) {
      $menu = menu_get_item($path);
      if (!$menu['access']) continue;
    }

    $frags = explode(':', $key, 2);
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
    $form['conf'][$link['menu_name']][str_replace('.', '__', $key)] = array(
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
  }
  $form['new_menu_link'] = array(
    '#type' => 'markup',
    '#value' => l("Add New Link", "cp/settings/menus/add/nojs", array('attributes' => array('class' => 'vsite-menus-new-menu ctools-use-modal'))),
  );

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

function vsite_menus_new_link_callback($js) {
  if ($js) {
    ctools_include('ajax');
    ctools_include('modal');

     $form_state = array(
      'title' => t('New Menu Link'),
      'ajax' => TRUE,
     );

     // get the ctools page now
     $output = ctools_modal_form_wrapper('vsite_menus_new_link_form', $form_state);
     if (empty($output)) {
       $output[] = ctools_ajax_command_reload();
     }
     ctools_ajax_render($output);
  }
  else {
    return drupal_get_form('vsite_menus_new_link_form');
  }
}

function vsite_menus_new_link_form(&$form_state) {
  $form = array();

  $a_site_menus = _vsite_menus_get_menus();

  $form['new_menu'] = array(
    '#type' => 'fieldset',
    'new_menu_title' => array(
      '#type' => 'textfield',
      '#title' => t('Menu Title'),
      '#description' => t('What text will appear for the entry.'),
    ),
    'new_menu_url' => array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('Enter the URL for the new menu entry.'),
    ),
    'new_menu_region' => array(
      '#type' => 'select',
      '#title' => t('Default Region'),
      '#description' => t('Which menu should this entry go in?'),
      '#options' => array_diff_key($a_site_menus, array('none' => 0)),
    ),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  $form['#validate'][] = 'vsite_menus_settings_form_validate';
  $form['#submit'][] = 'vsite_menus_settings_form_submit';

  return $form;
}

/**
 * Include the css in after_build so that it always appears with the form, even with a cached form
 */
function vsite_menus_settings_form_after_build($form, &$form_state) {
  //CSS To be included with the form
  drupal_add_js(drupal_get_path('module', 'nodeformcols') . '/js/nodeformcols.js');
  drupal_add_css(drupal_get_path('module', 'vsite_menus') . '/theme/vsite_menus.css');
 /* not using it, but save it for later
  * drupal_add_js('
  	Drupal.behaviors.VsiteMenus = function() {
  		$("#vsite-menus-settings-form fieldset").hide();
  		$("a.vsite-menus-new-menu").click(function() {
  			Drupal.CTools.Modal.show();
  			$("#modal-title").html($("#vsite-menus-settings-form fieldset legend").html());
  			$("#modal-content").html($("#vsite-menus-settings-form fieldset").html());

  			$("#modal-content").append($("#edit-submit").clone().attr("id", "edit-submit-modal").attr("value", "Add New Link"));
  			$("#edit-submit-modal").click(function() {
  				$("#modal-content .form-text").each(function () {
  					$("#vsite-menus-settings-form #"+$(this).attr("id")).val($(this).val());
  				});
  				$("#vsite-menus-settings-form #edit-new-menu-region").val($("#modal-content #edit-new-menu-region").val());
  				$("#vsite-menus-settings-form").submit();
  			});

  			$("#modal-content").append("<input type=\"button\" id=\"edit-cancel\" class=\"form-button\" value=\"Cancel\">");
  			$("#edit-cancel").click(function() {
  				Drupal.CTools.Modal.dismiss();
  			});
  			Drupal.attachBehaviors();
  			return false;
  		});
  	}', 'inline');*/

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

function vsite_menus_settings_form_validate(&$form, &$form_state) {
  if ($form_state['values']['new_menu_title'] XOR $form_state['values']['new_menu_url']) {
    // if one or the other is set
    form_set_error($form_state['values']['new_menu_title']?'new_menu_url':'new_menu_title', t('Missing URL or Title for new link!'));
  }
  elseif ($form_state['values']['new_menu_title'] && $form_state['values']['new_menu_url']) {
    $faux_link = array(
      'link_path' => $form_state['values']['new_menu_url'],
      'link_title' => $form_state['values']['new_menu_title'],
    );
    if (!menu_valid_path($faux_link)) {
      // the link isn't valid.
      form_set_error('new_menu_url', t('The URL is not valid'));
    }
  }
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
    $key = str_replace('__', '.', $key);

    // set some vars for readability
    $region_old = $data['region-old'];
    $menu_old_key = $region_old.':'.$key;
    $region = $data['region'];
    $menu_key = $region.':'.$key;

    // the underlying structure is like this:
    // $menus['features']['features:bio']
    // it requires a bit of mess here

    $link =& $menus[$region_old][$menu_old_key];

    if ($region_old != $region) {
      // the regions are different.
      // move the link into the new region
      $menus[$region][$menu_key] =& $link;
      // and remove it from the old
      unset($menus[$region_old][$menu_old_key]);
    }

    $link['link_title'] = $data['name'];
    $link['menu_name'] = $data['region'];
    $link['weight'] = $data['weight'];

    if ($link['user_created'] && $region == 'none' || !isset($link['link_path'])) {
      // we're deleting the link
      unset($menus[$region][$menu_key]);
    }
    drupal_set_message(t("Menu Settings Saved."), 'status', false);
  }

  if ($form_state['values']['new_menu_title'] && $form_state['values']['new_menu_url']) {
    // add a new menu
    $new_link = array(
      'menu_name' => $form_state['values']['new_menu_region'],
      'link_path' => $form_state['values']['new_menu_url'],
      'router_path' => $form_state['values']['new_menu_url'],
      'link_title' => check_plain($form_state['values']['new_menu_title']),
      'options' => array(),
      'module' => 'system',
      'hidden' => '0',
      'external' => menu_path_is_external($form_state['values']['new_menu_url'])?'1':'0',
      'has_children' => '0',
      'expanded' => '0',
      'weight' => '0',
      'user_created' => TRUE,
    );

    $new_menu_key = $new_link['menu_name'].':'.$new_link['link_path'];
    $menus[$new_link['menu_name']][$new_menu_key] = $new_link;
    drupal_set_message(t("New Link Added."), 'status', false);
  }

  foreach ($menus as $key => $data) {
    $space->controllers->vsite_menu->set($key, $data);
  }
}
