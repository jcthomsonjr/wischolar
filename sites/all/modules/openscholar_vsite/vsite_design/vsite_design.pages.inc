<?php

function vsite_design_theme_picker_form($form_state) {

  // external files
  drupal_add_css(drupal_get_path('module', 'vsite_design') . '/theme/vsite_design_theme_picker.css');
  drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/vsite_design-sliding-container.js');
  drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/vsite_design_theme_picker.js');

  //Showing and hiding the flavors
  ctools_include('dependent');
  ctools_include('form');

  //For changing the screenshot
  ctools_include('ajax');
  ctools_add_js('ajax-responder');


  vsite_include('vsiteapi');
  $enabled = vsite_vsite_themes();
  if (count($enabled) > 0) {
    ksort($enabled);
  }

  $form = array('#title' => 'Theme');

  $options = array(); //Radio Options

  foreach ( $enabled as $theme_obj ) {
    $info = $theme_obj->info;
    $info['theme_name'] = $theme_obj->name;
    $theme_flavors = vsite_design_get_flavors($theme_obj->name);

    //show flavors if there is more than the default theme flavor defined
    if (isset($theme_flavors) && is_array($theme_flavors) && count($theme_flavors)) {
    	$a_options = array('default' => ($info['flavor_name']?$info['flavor_name']:'Default').' (Default)');
    	$default = '';
    	foreach ($theme_flavors as $s_key => $a_info) {
    	  if (isset($a_info['flavor_name'])) {
    	    $a_options[$s_key] = $a_info['flavor_name']." (Default)";
    	    $default = $s_key;
    	  }
    	  else {
    	    $a_options[$s_key] = $a_info['name'];
    	  }
    	}

      $form['vsite_design_'.$info['theme_name'] . '_flavor'] = array(
        '#type' => 'select',
        '#title' => 'Flavor',
        '#options' => $a_options,
        '#default_value' => variable_get('vsite_design_'.$info['theme_name'].'_flavor', $default),
        '#process' => array(
          'ctools_dependent_process'
        ),
        '#dependency' => array(
          'radio:settings[theme][maintheme]' => array(
            $info['theme_name']
          )
        )
      );

      //Screenshot callback
      if($info['screenshot']) {
        ctools_ajax_associate_url_to_element($form, $form['vsite_design_'.$info['theme_name'].'_flavor'], url('cp/settings/theme/swap_screenshot/'.$info['theme_name']),'ctools-use-ajax-onchange');
      }
    }

    $options[$info['theme_name']] = $info['theme_name'];
  }

  $form['vsite_design_maintheme'] = array(
    '#enabled_themes' => $enabled,
    '#type' => 'radios',
    '#options' => $options,
    '#default_value' => variable_get('vsite_design_maintheme', 'scholar_airstream'),
    '#tree' => TRUE
  );

  $form['#prefix'] = theme('vsite_design_theme_subnav', count($enabled));

  $form['#validate'][] = 'vsite_design_theme_picker_form_validate';
  $form['#submit'][] = 'vsite_design_theme_picker_form_submit';

  $form = system_settings_form($form);

  // system_settings_form sets a new theme. replace it with our theme
  $form['#theme'] = 'vsite_design_theme_form';

  return $form;
}

function vsite_design_theme_picker_form_validate(&$form, &$form_state) {
  foreach ($form_state['values'] as $key => $data) {
    if (strpos($key, 'ctools-ajax-url') !== FALSE ) {
      unset($form_state['values'][$key]);
    }
  }
}

function vsite_design_theme_picker_form_submit(&$form, &$form_state) {
  // save the theme selection into og_theme

  $space = spaces_get_space();
  $space->group->og_theme = $form_state['values']['vsite_design_maintheme'];
  og_update_group($space->group);
}