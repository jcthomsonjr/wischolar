<?php

function adminformcols_front_form($form_state) {
  $form = array();
  $form['container'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => 'adminformcols_front_form_table',
  );
  
  // put together a list of all the admin forms available
  $res = db_query("SELECT * FROM {adminformcols_enabled}");
  while ($r = db_fetch_array($res)) {
    $form['container']['form_'.$r['fid']] = array(
      '#type' => 'checkbox',
      '#title' => t($r['form_id']),
      '#default_value' => $r['enabled']?1:0,
      '#theme' => 'adminformcols_enable_checkbox',
    );
  }
  
  $form['submit'] = array(
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
    
    db_query("UPDATE {adminformcols_enabled} SET enabled = %d WHERE fid = %d", $field['#value'], $frags[1]);
  }
}

function adminformcols_config_form($form_state, $fid) {
  require_once(drupal_get_path('module', 'nodeformcols') . '/nodeformcols.admin.inc');
  $form = array();
  // fields:
  // enabled checkbox
  // default values to use to get form
  // list of regions
  
  // getting initial parameters and the such
  $q = db_query("SELECT fid, form_id, params, page_arguments, file, enabled FROM {adminformcols_enabled} INNER JOIN {menu_router} WHERE fid = %d AND INSTR(page_arguments, form_id)", $fid);
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
  
  $form_fields = _adminformcols_get_form_fields($form_name, $r['params'], $r['file'], $fid);
  
  $form['header'] = array(
  	'#type' => 'markup',
  	'#value' => ucwords(str_replace('_' ,' ', $form_name)),
  	'#region' => 'none',
    '#prefix' => '<h2>',
  	'#suffix' => '</h2>'
  );
  
  $form['#columns'] = TRUE;
  // building the form
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => $r['enabled'] || $enabled,
    '#region' => 'right',
  );
  
  if (count($r['params']) > 0) {  
    $form['params'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default Parameters'),
      '#value' => '',
      '#region' => 'right',
    );
    
    foreach ($r['params'] as $key => $param) {
      $form['params']['param_'.$key] = array(
        '#type' => 'textfield',
        '#title' => t('Parameter #').($key+1),
        '#size' => 60,
        '#default_value' => $r['params'][$key],
      );
    }
  }
  
  // get the fields in the form
  $form_fields = _adminformcols_get_form_fields($form_name, $r['params'], $r['file'], $fid);
  $form['conf'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => array('nodeformcols_configuration')
  //  '#theme' => 'adminformcols_config_form_table',
  );
  
  $options = _adminformcols_regions();
  //$options['none'] = 'None';
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
    
    if (isset($field['#collapsed'])) {
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
  
  $form['fid'] = array(
    '#type' => 'hidden',
    '#value' => $r['fid'],
  );
  
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
  
  $q = db_query("SELECT * FROM {adminformcols_enabled} WHERE fid = %d", $form_state['values']['fid']);
  $res = db_fetch_array($q);
  $res['params'] = unserialize($res['params']);
  
  // runs through each form value
  // if its a field, we update the region in the _fields database
  // if its a param, we update the params in the _enabled database
  
  foreach ($form_state['values'] as $field => $value) {
    $frags = explode('_', $field);
    $type = array_pop($frags);
    $field = implode('_', $frags);
    if ($type == 'region' || $type == 'collapsed' || $type == 'hidden' || $type == 'weight') {
    	$$type = $value;
      $q = db_query("SELECT region FROM {adminformcols_fields} WHERE fid = %d AND name = '%s'", $form_state['values']['fid'], $field);
        $r = db_fetch_array($q);
        if ($r) {
          // it exists already
          db_query("UPDATE {adminformcols_fields} SET %s = '%s' WHERE fid=%d AND name = '%s'", $type, $value, $form_state['values']['fid'], $field);
        }
        else {
          // it doesn't exist, make a new one
          db_query("INSERT INTO {adminformcols_fields} VALUES (%d, '%s', '%s', %d, %d, %d)", $form_state['values']['fid'], $field, $region, $weight, $collapsed, $hidden);        
        }
    }
    elseif ($type == 'param') {
      $res['params'][(int)$field] = $value;
    }
  }
  
  db_query("UPDATE {adminformcols_enabled} SET enabled = %d, params = '%s' WHERE fid = %d", $form_state['values']['enabled'], $res['params']?serialize($res['params']):'', $form_state['values']['fid']);
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

    $row = array();
    $row[] = ucwords(str_replace('_',' ',$field['#title']));
    $row[] = drupal_render($field);
    $row[] = l('Edit Form', 'admin/settings/system_forms/'.$frags[1]);
    
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

function _adminformcols_get_form_fields($form_id, $parameters, $file, $fid) {
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
    if (substr($key, 0, 1) == '#' || substr($key, 0, 8) == 'section_' || (isset($field['#access']) && $field['#access'] == FALSE) ||
          $field['#type']=='value' || $field['#type']=='hidden'|| $field['#type']=='token') {
        continue;
      }
      
      // Ensure a weight so that we don't have to worry about it later
      $field['#weight'] = isset($field['#weight']) ? $field['#weight'] : 0;
      
      $q = db_query("SELECT region, weight, collapsed, hidden FROM {adminformcols_fields} WHERE fid = %d AND name = '%s' ORDER BY weight ASC", $fid, $key);
      $r = db_fetch_array($q);
      if ($r['region']) {
        $field['#region_original'] = $field['#region'];
        $field['#region'] = $r['region'];
      }
      if ($field['#type'] == 'fieldset') $field['#collapsed'] = $r['collapsed']?$r['collapsed']:0;
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