<?php

/*
 * Implementation of cite_distribute_admin()
 */
function citation_distribute_admin() {
	$form = array();
  $form['citation_distribute'] = array(
	  '#type' => 'fieldset',
	  '#title' => t('Configure Citation Distribute'),
	  '#collapsible' => FALSE,
	  '#collapsed' => FALSE,
	 );

  $form['citation_distribute']['citation_distribute_module_mode'] = array(
	  '#type' => 'select',
	  '#title' => t('Select the mode for this module'),
	  '#options' => array('api'=> 'API Mode', 'batch' => 'Batch Process Mode', 'per_submission' => 'Per Submission Mode'),
	  '#required' => TRUE,
	  '#default_value' => variable_get('citation_distribute_module_mode','per_submission'),
	  '#description' => t('<strong>API mode</strong> does nothing by default, but lets the developer decide when to call the module\'s functions.
	      <br><strong>Batch mode</strong> is intended to be run by cron will update all meta files at once in a batch process. 
	      <br><strong>Per Submission mode (Recommended) </strong> will update or create a meta file whenever content submitted or updated.')
   );
   
   
   $form['citation_distribute']['citation_distribute_cron_limit'] = array(
     '#type' => 'textfield',
   	 '#title' => 'Batch Size Limit',
   	 '#description' => t('(Batch mode only) Limit how many publications can be submitted per cron run.'),
   	 '#required' => FALSE,
   	 '#default_value' => variable_get('citation_distribute_cron_limit', _CRON_LIMIT),
     //only show up during batch mode.  use ahah to reveal this setting?
   );
   
   
   return system_settings_form($form);
}

/**
 * implementation of form_validate
 */
function citation_distribute_admin_validate($form, &$form_state) {
	if ((int)$form_state['values']['citation_distribute_cron_limit'] > 0) {
		return;		
	} else {
		form_set_error('', t('Batch size limit must be a positive integer.'));
	}
}
 