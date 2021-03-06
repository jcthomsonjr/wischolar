<?php

/**
 * Helper function to create a FAPI system settings form
 * @param string $form_id
 * @param string $setting_id
 * @return mixed FAPI array representing the form
 */
function cp_settings_form($form_id, $setting_id) {
  
  // get the space
  $space = vsite_get_vsite();
  
  // all space settings (classes)
  $settings = cp_get_vsite_settings(TRUE);

  
  $form = array();
  if ($setting_id == 'logo') $form['#attributes'] = array('enctype' => "multipart/form-data");
  
  // just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-site">';
  $form['#suffix'] = '</div>';
  
  //$form['#attributes'] = array('class' => 'pad');
  // the form definition for this particular setting (we know setting_id)
  // 'settings' is important here (see the submit function)
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
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
  
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('cp_settings_form_reset'),
  );
  
  return $form;
}

function cp_settings_form_submit($form, &$form_state) {
  // get the space and the settings we want to save
  $space = $form_state['values']['space'];
  $setting = $form_state['values']['setting'];
  
  // Set setting values
  $settings = cp_get_vsite_settings();
  if (!empty($form_state['values']['settings'])) {
    foreach ($form_state['values']['settings'] as $setting => $value) {
      $space->controllers->variable->set('vsite_setting_'.$setting, $settings[$setting]->submit($space, $value));
      
      if (!$form_state['redirect'] && is_callable(array($settings[$setting], 'modifyRedirect'), FALSE)) $form_state['redirect'] = $settings[$setting]->modifyRedirect($value);
    }
  }
}

/**
 * Reset submit handler for cp spaces settings.
 */
function cp_settings_form_reset($form, &$form_state) {
   // get the space and the settings we want to save
  $space = $form_state['values']['space'];
  $setting = $form_state['values']['setting'];
  
  $settings = cp_get_vsite_settings();
  if (!empty($form_state['values']['settings'])) {
    foreach ($form_state['values']['settings'] as $setting => $value) {
      if (method_exists($settings[$setting], 'reset')) {
        
        $old_setting = $space->controllers->variable->get('vsite_setting_'.$setting);
        
        //If the setting has the reset function let them decide what that means
        $settings[$setting]->reset($space, $old_setting );
        $space->controllers->variable->set('vsite_setting_'.$setting,$old_setting); //Save the modified setting
      }
      else {
        //If they don't have a reset function we will just remove all settings
        $space->controllers->variable->del('vsite_setting_'.$setting);
      }
    }
  }
}

/**
 * Validate handler for spaces features form
 */
function cp_settings_form_validate($form, &$form_state) {
  if ($form_state['submitted'] && $form_state['submit_handlers'] && in_array('cp_settings_form_reset', $form_state['submit_handlers'])) return;
  
  $space = $form_state['values']['space'];
  $settings = cp_get_vsite_settings();

  if (is_array($form_state['values']['settings'])) {
    foreach ($form_state['values']['settings'] as $setting => $value) {
      $settings[$setting]->validate($space, $value);
    }
  }
}

