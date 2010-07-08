<?

/**
 * Form Builder. Configure iqss_remote_source
 */
function iqss_remote_source_settings_form() {
  $form['iqss_remote_source_valid_ogs'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Enabled VSites'),
	  '#default_value' => variable_get('iqss_remote_source_valid_ogs',''),
	  '#size' => 60,
	  '#maxlength' => 128,
	  '#required' => FALSE,
	  '#description' => "A comma seperated list of og ids for groups you wish to have this functionality"
	);
  return system_settings_form($form);
}
