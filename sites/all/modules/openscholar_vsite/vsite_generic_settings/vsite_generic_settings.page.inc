<?php

function vsite_generic_settings_get_settings($reset = FALSE) {
  static $settings;

  if (!isset($settings) || $reset) {
    foreach (module_implements('vsite_generic_settings') as $module) {
      $settings[$module] = module_invoke($module, 'vsite_generic_settings');
    }
    //$settings = module_invoke_all('vsite_generic_settings');
  }

  return $settings;
}

function vsite_generic_settings_form($form_state) {
  $form = array(
  	'#title' => "Other Settings",
    '#validate' => array(),
    '#submit' => array(),
  );

  $a_settings = vsite_generic_settings_get_settings();
  foreach ($a_settings as $module => $settings) {
    $fieldset = array(
      '#title' => ucwords(str_replace('vsite_', '', $module)),
      '#type' => 'fieldset',
    );
    foreach ($settings as $s_key => $setting) {
      if (!array_key_exists('form', $setting)) continue;
      $fieldset[$s_key] = $setting['form'];
      if (is_array($setting['validate'])) {
        $form['#validate'] = array_merge($form['validate'], $setting['validate']);
      }
      if (is_array($setting['submit'])) {
        $form['#submit'] = array_merge($form['#submit'], $setting['submit']);
      }
      if (is_array($setting['css'])) {
        foreach ($setting['css'] as $file) {
          drupal_add_css($file);
        }
      }
      if (is_array($setting['js'])) {
        foreach ($setting['js'] as $file) {
          drupal_add_js($file);
        }
      }
    }
    $form[$module] = $fieldset;
  }
  return system_settings_form($form);
}

