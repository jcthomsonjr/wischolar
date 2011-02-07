<?php
// $Id;

function adminformcols_front_form($form_state) {
  $form = array();
  
  $form['add_form'] = array(
  	'#type' => 'textfield',
    '#title' => t('Add Form to List'),
    '#description' => t('Enter a path or form_id to add it to list below for editting.'),
    '#maxlength' => 255,
    '#size' => 60,
  );
  
  $form['submit1'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  $form['container'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => 'adminformcols_front_form_table',
  );
  
  // put together a list of all the admin forms available
  $res = db_query("SELECT * FROM {adminformcols_enabled}");
  while ($r = db_fetch_array($res)) {
    $form['container']['form_'.$r['form_id']] = array(
      '#type' => 'checkbox',
      '#title' => t($r['form_id']),
      '#default_value' => $r['enabled']?1:0,
      '#theme' => 'adminformcols_enable_checkbox',
    );
  }
  
  $form['submit2'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}

/**
 * 
 * Enables or disables selected forms in the database
 * @param array $form
 * @param array $form_state
 */

function adminformcols_front_form_submit($form, &$form_state) {
  foreach ($form['container'] as $key => $field) {
    $frags = explode('_', $key);
    if ($frags[0] != 'form') continue;
    
    db_query("UPDATE {adminformcols_enabled} SET enabled = %d WHERE form_id = %d", $field['#value'], $frags[1]);
  }
  
  if (!empty($form_state['values']['add_form'])) {
  	$new_form = $form_state['values']['add_form'];
  	$closest = '';
  	$lev = 500;
  	$found_form = '';
  	// check to make sure it's a valid path or form_id
  	$q = db_query("SELECT path, page_arguments FROM {menu_router} WHERE page_callback = 'drupal_get_form' AND ( path LIKE '%%%s%%' OR page_arguments LIKE '%%%s%%' )", $new_form, $new_form);
  	while ($r = db_fetch_array($q)) {
  		$r['page_arguments'] = unserialize($r['page_arguments']);
  		if ($r['page_arguments'][0] == $new_form) {
  			// we found it in page arguments. add it
  			$found_form = $new_form;
  			break;
  		}
  		else {
  			// we found it's path. we have to find the closest path match and use that
  			$dist = levenshtein($new_form, $r['path']);
  			if ($dist == 0) {
  				$found_form = $r['page_arguments'][0];
  				$lev = 0;
  				break;
  			}
  			elseif ($dist < $lev) {
  				$found_form = $r['page_arguments'][0];
  				$lev = $dist;
  			}
  		}
  	}
  	
  	if (!empty($found_form)) {
  		// we now have a known existing form_id. insert it.
  		// if it's already there, good. Mission accomplished.
  		@db_query("INSERT INTO {adminformcols_enabled} VALUES ('%s', 0, '')", $found_form);
  	}
  	else {
  		drupal_set_message(sprintf('No form found with path %1$s or form_id %1$s', $form_state['values']['add_form']), 'error');
  	}
  }
}

function adminformcols_config_form($form_state, $form_id) {
  require_once(drupal_get_path('module', 'nodeformcols') . '/nodeformcols.admin.inc');
  $form = array();
  // fields:
  // enabled checkbox
  // default values to use to get form
  // list of regions
  
  // getting initial parameters and the such
  $q = db_query("SELECT form_id, params, page_arguments, file, enabled FROM {adminformcols_enabled} INNER JOIN {menu_router} WHERE form_id = '%s' AND INSTR(page_arguments, form_id)", $form_id);
  $r = db_fetch_array($q);
  $r['params'] = unserialize($r['params']);
  $r['page_arguments'] = unserialize($r['page_arguments']);
  $form_name = @array_shift($r['page_arguments']);
  $form_name = $r['form_id'];
  
  // some initialization if it hasn't been done already
  if (!is_array($r['params'])) {
    $r['params'] = array();
  }
  
  if (!is_array($r['page_arguments'])) {
    $r['page_arguments'] = array();
  }
  
  foreach ($r['page_arguments'] as $k => $v) {
    if (!isset($r['params'][$k]))
      $r['params'][$k] = '';
  }
  
  $form_fields = _adminformcols_get_form_fields($form_name, $r['params'], $r['file'], $form_id);
  
  // setting #region to 'none' places it out of the columns
  $form['header'] = array(
  	'#type' => 'markup',
  	'#value' => ucwords(str_replace('_' ,' ', $form_name)),
  	'#region' => 'none',
    '#prefix' => '<h2>',
  	'#suffix' => '</h2>'
  );
  
  // tells the form that it's fields will be in columns
  $form['#columns'] = TRUE;
  
  // building the form
  
  // puts the enabled field in the right region by default
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => $r['enabled'] || $enabled,
    '#region' => 'right',
  );
  
  // and the param fields as well
  if (count($r['params']) > 0) {  
    $form['params'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default Parameters'),
      '#value' => '',
      '#region' => 'right',
    );
    
    foreach ($r['params'] as $key => $param) {
      $form['params'][$key.'_param'] = array(
        '#type' => 'textfield',
        '#title' => t('Parameter #').($key+1),
        '#size' => 60,
        '#default_value' => $r['params'][$key],
      );
    }
  }
  
  // get the fields in the form
  // as well as their relevant data
  $form_fields = _adminformcols_get_form_fields($form_name, $r['params'], $r['file'], $form_id);
  
  // by leaving the #region blank, it is automatically placed in Main
  $form['conf'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => array('nodeformcols_configuration')
  //  '#theme' => 'adminformcols_config_form_table',
  );
  
  $options = _adminformcols_regions();
  $options['none'] = 'None';
  foreach ($form_fields as $key => $field) {
    $form['conf'][$field['#region']][$key] = array(
    	'#weight' => $field['#weight'],
      $key.'_name' => array(
      	'#type' => 'markup',
      	'#value' => !empty($field['#title']) ? $field['#title'] : ucwords(str_replace('_', ' ', $key)),
      ),
      $key . '_region' => array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $field['#region'],
        '#attributes' => array(
          'class' => 'field-region-select field-region-'. $field['#region'],
        ),
      ),
      $key . '_weight' => array(
        '#type' => 'textfield',
        '#default_value' => $field['#weight'],
        '#size' => 3,
        '#attributes' => array(
          'class' => 'field-weight field-weight-'. $field['#region'],
        ),
      ),
    );
    
    if ($field['#collapsible']) {
    	$form['conf'][$field['#region']][$key][$key.'_collapsed'] = array(
    		'#type' => 'checkbox',
    	  '#default_value' => $field['#collapsed'],
    	  '#title' => t('Show Collapsed'),
    	);
    }
    
    if (!_nodeformcols_has_required($field)) {
      $form['conf'][$field['#region']][$key][$key . '_hidden'] = array(
        '#type' => 'checkbox',
        '#title' => t('Hide'),
        '#default_value' => $field['#hidden'],
      );
    }
  }
  
  $form['column_form_id'] = array(
    '#type' => 'hidden',
    '#value' => $r['form_id'],
  );
  
  // the submit button goes in the footer region by default
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#region' => 'footer'
  );
  
  $form['#after_build'][] = '_nodeformcols_configuration_form_after_build';
  //$form['#after_build'][] = '_adminformcols_config_form_after_build';
  
  return $form;
}

function adminformcols_config_form_submit($form, &$form_state) {
  
  $q = db_query("SELECT * FROM {adminformcols_enabled} WHERE form_id = %d", $form_state['values']['column_form_id']);
  $res = db_fetch_array($q);
  $res['params'] = unserialize($res['params']);
  
  // runs through each form value
  
  // each field has one of 4 parameters. 
  // the pattern is fieldname_attribute
  // we assume the attribute wont have a _, but the fieldname can have as many as it likes
  // once we know it's an attribute, stick it in the _fields database
  
  // if its a param, we update the params in the _enabled database
  
  foreach ($form_state['values'] as $field => $value) {
    $frags = explode('_', $field);
    $type = array_pop($frags);
    $field = implode('_', $frags);
    if ($type == 'region' || $type == 'collapsed' || $type == 'hidden' || $type == 'weight') {
    	$region = '';
    	$collapsed = $hidden = $weight = 0;
    	$$type = $value;
      if (!@db_query("INSERT INTO {adminformcols_fields} VALUES ('%s', '%s', '%s', %d, %d, %d)", $form_state['values']['column_form_id'], $field, $region, $weight, $collapsed, $hidden)) {
        // it exists already. update instead
        db_query("UPDATE {adminformcols_fields} SET %s = '%s' WHERE form_id = '%s' AND name = '%s'", $type, $value, $form_state['values']['column_form_id'], $field);
      }
    }
    elseif ($type == 'param') {
      $res['params'][(int)$field] = $value;
    }
  }
  
  db_query("UPDATE {adminformcols_enabled} SET enabled = %d, params = '%s' WHERE form_id = '%s'", $form_state['values']['enabled'], $res['params']?serialize($res['params']):'', $form_state['values']['column_form_id']);
}

/*
 * Not Used
function _adminformcols_config_form_after_build($form) {
	$regions = _adminformcols_regions();
  foreach ($regions as $region => $title) {
    if (is_array($form[$region])) {
      uasort($form[$region], "element_sort");
    }
  //  drupal_add_tabledrag('fields', 'match', 'sibling', 'field-region-select', 'field-region-'. $region, NULL, FALSE);
  //  drupal_add_tabledrag('fields', 'order', 'sibling', 'field-weight', 'field-weight-'. $region);
  }
  return $form;
} */

/**
 * 
 * Theme function for the front page of adminformcols
 * Arranges the list of forms into a table
 * @param unknown_type $container
 */

function theme_adminformcols_front_form_table($container) {
  $header = array(t('Name'), t('Enabled'), t('Edit'));
  
  $rows = array();
  foreach ($container as $field_name => $field) {
    $frags = explode('_', $field_name);
    if ($frags[0] != 'form') continue;
    array_shift($frags);
    $field_name = implode('_', $frags);

    $row = array();
    $row[] = ucwords(str_replace('_',' ',$field['#title']));
    $row[] = drupal_render($field);
    $row[] = l('Edit Form', 'admin/settings/system_forms/'.$field_name);
    
    $rows[] = $row;
  }
  
  return theme_table($header, $rows);
}

/**
 * Just unsets the title for the checkbox.
 * @param unknown_type $field
 */

function theme_adminformcols_enable_checkbox($field) {
  unset($field['#title']);
  
  return theme('checkbox', $field);
}

/**
 * Theme hook for admincols_config_form's table
 * @param unknown_type $container
 */

function theme_adminformcols_config_form_table($container) {
  
  $headers = array(t('Field'), t('Region'));
  
  $rows = array();
  foreach ($container as $field_name => $field) {
    if (substr($field_name, 0, 1) == '#') continue;
    $row = array();
    $row[] = ucwords(str_replace(array('_', 'field'), ' ',$field_name));
    $row[] = drupal_render($field);
    
    $rows[] = $row;
  }
  
  return theme_table($headers, $rows);
}

/**
 * Gets a flat array of all the fields we want 
 * to position.
 * @param unknown_type $form_id
 * @param unknown_type $parameters
 * @param unknown_type $file
 */

function _adminformcols_get_form_fields($form_id, $parameters, $file, $form_id) {
	if (empty($form_id)) return array();
  if (!empty($file))
    include_once($file);
  
  // put together args for drupal_retrieve_form
  // it takes form_id, form_state, then the contents of $parameters
  
  $form_state = array(
      'storage' => NULL,
      'submitted' => FALSE,
  );
  
  array_unshift($parameters, $form_id, $form_state);
  $form = call_user_func_array('drupal_retrieve_form', $parameters);
  drupal_prepare_form($form_id, $form, $form_state);
  
  // we have the form
  // filter the top level # parameters out
  // also, any hiddens, values, and tokens
  
  // while we're at it, look for the field in the database and use its 
  // region if its there
  
  $fields = array();
  foreach ($form as $key => $field) {
  	// filtering
    if (substr($key, 0, 1) == '#' || substr($key, 0, 8) == 'section_' || 
          $field['#type']=='value' || $field['#type']=='hidden'|| $field['#type']=='token') {
        continue;
      }
      
      // Ensure a weight so that we don't have to worry about it later
      $field['#weight'] = isset($field['#weight']) ? $field['#weight'] : 0;
      
      // check the database - get settings from there if it exists
      $q = db_query("SELECT region, weight, collapsed, hidden FROM {adminformcols_fields} WHERE form_id = '%s' AND name = '%s' ORDER BY weight ASC", $form_id, $key);
      $r = db_fetch_array($q);
      if ($r['region']) {
        $field['#region_original'] = $field['#region'];
        $field['#region'] = $r['region'];
      }
      if ($field['#type'] == 'fieldset' && $field['#collapsible']) $field['#collapsed'] = $r['collapsed']?$r['collapsed']:$field['#collapsed'];
      $field['#hidden'] = $r['hidden'];
      
      if (!$field['#region']) {
        // it wasn't in the database, nor did it have it's own setting. set a default for it.
        $field['#region'] = 'main';
      }
      
      $field['#weight'] = $r['weight'];
      
      $fields[$key] = $field;
  }
  
  return $fields;
}