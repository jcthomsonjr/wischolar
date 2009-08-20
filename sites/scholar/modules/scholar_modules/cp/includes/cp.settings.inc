<?php

/**
 * Enter description here...
 */
function cp_settings_form($form_id, $setting_id){
  drupal_add_css(drupal_get_path('module', 'cp') .'/theme/cp-theme-picker.css');
  drupal_add_js(drupal_get_path('module', 'cp') . '/theme/cp-theme-picker.js');
  drupal_add_js(drupal_get_path('module', 'cp') . '/theme/cp-sliding-container.js');
  
  // get the space
  $space = spaces_get_space();
  
  // all space settings (classes)
  $settings = spaces_settings($space -> type, TRUE);

  //$form = array('#tree' => TRUE);
  
  $form = array();

  if($setting_id == 'logo') $form['#attributes'] = array('enctype' => "multipart/form-data");
  
  // just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-'. $setting_id . '" class="pad">';
  $form['#suffix'] = '</div>';
  
  // the form definition for this particular setting (we know setting_id)
  // 'settings' is important here (see the submit function)
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#tree' => TRUE,
  );
  $form['settings'][$setting_id] = $settings[$setting_id] -> form($space, $space -> settings[$setting_id]);
  
  // add the $space object to the form (so that we have it on submit);
  $form['space'] = array(
    '#type' => 'value',
    '#value' => $space,
  );
  // pass the settingid too
  $form['setting'] = array(
    '#type' => 'value',
    '#value' => $setting_id,
  );
  
  // add the submit button (not in the form definition yet)
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  return $form;
}

function cp_settings_form_submit($form, &$form_state){
  // get the space and the settings we want to save
  $space = $form_state['values']['space'];
  $setting = $form_state['values']['setting'];
  
  // Set setting values
  $settings = spaces_settings();
  if (!empty($form_state['values']['settings'])) {
    foreach ($form_state['values']['settings'] as $setting => $value) {
      $space->settings[$setting] = $settings[$setting]->submit($space, $value);
    }
  }
  spaces_save($space);
}

/**
 * Validate handler for spaces features form
 */
function cp_settings_form_validate($form, &$form_state) {
  
  $space = $form_state['values']['space'];
  $settings = spaces_settings();

  if (is_array($form_state['values']['settings'])) {
    foreach ($form_state['values']['settings'] as $setting => $value) {
      $settings[$setting]->validate($space, $value);
    }
  }
}

