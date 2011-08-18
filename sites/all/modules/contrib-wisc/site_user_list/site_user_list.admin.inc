<?php

/**
 * Admin pages for site_user_list module.
 */

/// NOT YET CONVERTED TO DRUPAL 6!

/**
 * the admin settings page
 */
function site_user_list_admin_settings_form() {
  drupal_add_css(drupal_get_path('module', 'site_user_list') . '/site_user_list.css');
  
  $form = array();
  
  // store as query, view, table; use cron
  $form['query_type_fs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Database'),
  );
  // *** database views not available before MySQL 5.0
  // *** subselect queries not available before MySQL 4.1
  $query_type_options = array(
    'query' => t('subselect query'),
    'view' => t('database view'),
    'table' => t('table'),
  );
  $query_type_default = 'query';
  if (($GLOBALS['db_type'] == 'mysql') or ($GLOBALS['db_type'] == 'mysqli')) {
    $db_version = db_version();
    if (version_compare($db_version, '4.1', '<')) {
      unset($query_type_options['query']);
      unset($query_type_options['view']);
      $query_type_default = 'table';
    }
    elseif (version_compare($db_version, '5.0', '<')) {
      unset($query_type_options['view']);
    }
  }
  $form['query_type_fs']['site_user_list_query_type'] = array(
    '#type' => 'select',
    '#title' => t('Retrieve data from a'),
    '#default_value' => variable_get('site_user_list_query_type', $query_type_default),
    '#options' => $query_type_options,
    '#description' => t('The best choice is view; query may be slow and not work, table won\'t always be up-to-date.'),
  );
  $form['query_type_fs']['site_user_list_use_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Rebuild when cron jobs are run'),
    '#default_value' => variable_get('site_user_list_use_cron', 0),
    '#description' => t('Select this option if you want to rebuild the table, view, or query every time cron is run. You should only need to do this if you are using a table.'),
  );
  $form['query_type_fs']['rebuild_link'] = array(
    '#type' => 'markup',
    '#value' => t('If you wish to manually rebuild the table, view, or query, you can go to ') . l(base_path() . 'site_user_list/rebuild', 'site_user_list/rebuild'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  $form['query_type_fs']['site_user_list_log_rebuilds'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log rebuild actions'),
    '#default_value' => variable_get('site_user_list_log_rebuilds', 0),
    '#description' => t('If you select this option, whenever the table, view, or query is rebuilt, a log entry will be made.'),
  );
  
  // general ui information
  $form['ui_options_fs'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Interface Options'),
  );
  $form['ui_options_fs']['site_user_list_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Site user list page title'),
    '#default_value' => variable_get('site_user_list_title', t('Site user list')),
    '#description' => t('The title of the page listing the site users, as well as the title of the link on the navigation menu.'),
  );
  $form['ui_options_fs']['site_user_list_column_delta'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum column weight'),
    '#default_value' => variable_get('site_user_list_column_delta', 20),
    '#description' => t('The maximum weight of a column.  Note that you have twice as many weights available as this number, as you also have negative weights.  This number must be greater than zero, but less than or equal to 400.  If you need more than 800 slots, this module really isn\'t the right one for you.'),
    '#size' => 6,
  );
  
  // display elements
  $form['display_elements_fs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display elements'),
  );
  $form['display_elements_fs']['display_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display Options Form'),
    '#weight' => variable_get('site_user_list_d_weight', -3),
  );
  $form['display_elements_fs']['display_form']['site_user_list_d_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the display options form'),
    '#default_value' => variable_get('site_user_list_d_show', 1),
  );
  $form['display_elements_fs']['display_form']['site_user_list_d_weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight of the display options form'),
    '#default_value' => variable_get('site_user_list_d_weight', -3),
    '#delta' => 5,
  );
  
  $form['display_elements_fs']['search_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search Form'),
    '#weight' => variable_get('site_user_list_s_weight', -2),
  );
  $form['display_elements_fs']['search_form']['site_user_list_s_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the search form'),
    '#default_value' => variable_get('site_user_list_s_show', 1),
  );
  $form['display_elements_fs']['search_form']['site_user_list_s_weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight of the search form'),
    '#default_value' => variable_get('site_user_list_s_weight', -2),
    '#delta' => 5,
  );
  $form['display_elements_fs']['search_form']['site_user_list_s_before'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the search filter above the results'),
    '#default_value' => variable_get('site_user_list_s_before', 0),
  );
  $form['display_elements_fs']['search_form']['site_user_list_s_after'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the search filter below the results'),
    '#default_value' => variable_get('site_user_list_s_after', 0),
  );
  
  
  $form['display_elements_fs']['results_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Results'),
    '#weight' => variable_get('site_user_list_r_weight', 0),
  );
  $form['display_elements_fs']['results_form']['site_user_list_r_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the results'),
    '#default_value' => variable_get('site_user_list_r_show', 1),
  );
  $form['display_elements_fs']['results_form']['site_user_list_r_weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight of the results'),
    '#default_value' => variable_get('site_user_list_r_weight', 0),
    '#delta' => 5,
  );
  $form['display_elements_fs']['results_form']['site_user_list_r_count'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the number of displayed users'),
    '#default_value' => variable_get('site_user_list_r_count', 1),
  );
  $form['display_elements_fs']['results_form']['site_user_list_include_blocked_users'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include blocked users in results'),
    '#default_value' => variable_get('site_user_list_include_blocked_users', 0),
  );
  $form['display_elements_fs']['results_form']['site_user_list_display_sql_query'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the SQL query'),
    '#default_value' => variable_get('site_user_list_display_sql_query', 0),
  );

  $form['display_elements_fs']['reset_link'] = array(
      '#type' => 'fieldset',
      '#title' => t('Reset Link'),
      '#weight' => variable_get('site_user_list_rl_weight', -1),
  );
  $form['display_elements_fs']['reset_link']['site_user_list_rl_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the reset link'),
    '#default_value' => variable_get('site_user_list_rl_show', 0),
  );
  $form['display_elements_fs']['reset_link']['site_user_list_rl_weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight of the reset link'),
    '#default_value' => variable_get('site_user_list_rl_weight', -1),
    '#delta' => 5,
  );
  
  $form[] = array(
    '#type' => 'submit',
    '#value' => 'Save configuration',
  );
  
  return $form;
}

function site_user_list_admin_settings_form_validate($form, &$form_state) {
  if ($form_state['values']['site_user_list_column_delta'] != '20') {
    $cd = $form_state['values']['site_user_list_column_delta'];
    $is_error = true;
    
    if (is_numeric($cd)) {
      $cd_val = $cd + 0;
      if (is_int($cd_val) and (0 < $cd_val) and ($cd_val <= 400)) {
        $is_error = false;
      }
    }
  
    if ($is_error) {
      form_set_error('site_user_list_column_delta', 'The maximum weight of a column must be between 1 and 400 inclusive.');
    }
  }
}

function site_user_list_admin_settings_form_submit($form, &$form_state) {
  // basically just run through and set the variables
  variable_set('site_user_list_query_type', $form_state['values']['site_user_list_query_type']);
  if ($form_state['values']['site_user_list_query_type'] == 'query') {
    variable_set('site_user_list_select_from', '');
  }
  else {
    // node that we include the '{' and '}' in the name; queries include the '(' and ')'
    variable_set('site_user_list_select_from', '{site_user_list_' . $form_state['values']['site_user_list_query_type'] . '}');
  }
  
  variable_set('site_user_list_use_cron', $form_state['values']['site_user_list_use_cron']);

  $old_log = variable_get('site_user_list_log_rebuilds', 0);
  if ($old_log != $form_state['values']['site_user_list_log_rebuilds']) {
    watchdog('site_user_list', 'Rebuild logging ' . ($form_state['values']['site_user_list_log_rebuilds'] ? 'enabled' : 'disabled'));
  }
  variable_set('site_user_list_log_rebuilds', $form_state['values']['site_user_list_log_rebuilds']);
  
  variable_set('site_user_list_title', $form_state['values']['site_user_list_title']);
  cache_clear_all('*', 'cache_menu', true); // this should clear the menu cache, allowing a title change to come through
  
  variable_set('site_user_list_column_delta', $form_state['values']['site_user_list_column_delta']);
  
  variable_set('site_user_list_d_show', $form_state['values']['site_user_list_d_show']);
  variable_set('site_user_list_d_weight', $form_state['values']['site_user_list_d_weight']);

  variable_set('site_user_list_s_show', $form_state['values']['site_user_list_s_show']);
  variable_set('site_user_list_s_weight', $form_state['values']['site_user_list_s_weight']);
  variable_set('site_user_list_s_before', $form_state['values']['site_user_list_s_before']);
  variable_set('site_user_list_s_after', $form_state['values']['site_user_list_s_after']);

  variable_set('site_user_list_r_show', $form_state['values']['site_user_list_r_show']);
  variable_set('site_user_list_r_weight', $form_state['values']['site_user_list_r_weight']);
  variable_set('site_user_list_r_count', $form_state['values']['site_user_list_r_count']);
  variable_set('site_user_list_include_blocked_users', $form_state['values']['site_user_list_include_blocked_users']);
  variable_set('site_user_list_display_sql_query', $form_state['values']['site_user_list_display_sql_query']);

  variable_set('site_user_list_rl_show', $form_state['values']['site_user_list_rl_show']);
  variable_set('site_user_list_rl_weight', $form_state['values']['site_user_list_rl_weight']);

  // because we've potentially changed the query type, we need to
  // drop all the extant tables and rebuild
  _site_user_list_drop_all();
  site_user_list_build();
  
  drupal_set_message(t('The settings have been saved'));
}

/**
 * the fields admin settings page
 */
function site_user_list_fields_form() {
  drupal_add_css(drupal_get_path('module', 'site_user_list') . '/site_user_list.css');
  
  // get the list of available fields
  $a_fields = module_invoke_all('site_user_list_fields');
  foreach (array_keys($a_fields) as $f) {
    if (!isset($a_fields[$f]['default_template'])) { $a_fields[$f]['default_template'] = $f; }
    if (!isset($a_fields[$f]['default_template_condition_columns'])) { $a_fields[$f]['default_template_condition_columns'] = ''; }
    $a_fields[$f]['template'] = $a_fields[$f]['default_template'];
    $a_fields[$f]['template_condition_columns'] = $a_fields[$f]['default_template_condition_columns'];
    $a_fields[$f]['display'] = 0;
    $a_fields[$f]['weight'] = 0;
  }

  // then, get data saved in database, overriding defaults returned by the hook
  $saved_query = db_query("SELECT * FROM {site_user_list_fields}");
  while($sf = db_fetch_array($saved_query)) {
    $f = $sf['field_identifier'];
    $a_fields[$f]['display'] = $sf['display'];
    $a_fields[$f]['column_header'] = $sf['column_header'];
    $a_fields[$f]['weight'] = $sf['weight'];
    $a_fields[$f]['eval_template'] = $sf['eval_template'];
    $a_fields[$f]['template'] = $sf['template'];
    $a_fields[$f]['sortable'] = $sf['sort_column'];
    $a_fields[$f]['searchable'] = $sf['search_column'];
    $a_fields[$f]['template_condition_columns'] = $sf['template_condition_columns'];
  }
  
  $form = array();
  
  // something to iterate over in the submit handler
  $form['a_fields'] = array(
    '#type' => 'value',
    '#value' => array_keys($a_fields),
  );
  
  $form['f'] = array(
    '#type' => 'fieldset',
    '#title' => t('Available Columns'),
    '#attributes' => array('class' => 'site-user-list-settings-fields-fieldset'),
  );
  
  // note which columns are being used
  $form['f']['used_p'] = array(
    '#type' => 'markup',
    '#value' => t('Columns being displayed'),
    '#weight' => -1000,
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  
  // note which columns are hidden
  $form['f']['hidden_separater_hr'] = array(
    '#type' => 'markup',
    '#value' => '<hr />',
    '#weight' => 500,
    '#prefix' => '<p>&nbsp;</p>',
  );
  $form['f']['hidden_separater_p'] = array(
    '#type' => 'markup',
    '#value' => t('Hidden columns'),
    '#weight' => 501,
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  
  // we want something to separate columns which are currently displayable from
  // those which aren't.
  $form['f']['in_use_separater_hr'] = array(
    '#type' => 'markup',
    '#value' => '<hr />',
    '#weight' => 900,
    '#prefix' => '<p>&nbsp;</p>',
  );
  $form['f']['in_use_separater_p'] = array(
    '#type' => 'markup',
    '#value' => t('Columns not currently being used:'),
    '#weight' => 901,
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  
  foreach ($a_fields as $f => $s) {
    // calculate the weight; default to the bottom
    $weight = 1000;
    if (!empty($s['display'])) {
      // hidden fields are in the middle
      if ($s['display'] == SITE_USER_LIST_HIDDEN_DISPLAY) {
        $weight = 600;
      }
      elseif ($s['display'] > SITE_USER_LIST_HIDDEN_DISPLAY) {
        $weight = $s['weight'];
      }
    }
    // if @user_view or @user_edit aren't being displayed, put them at the very bottom
    elseif ($f == '@user_view') {
      $weight = 1500;
    }
    elseif ($f == '@user_edit') {
      $weight = 1501;
    }
    
    $form['f'][$f . '_fs'] = array(
      '#type' => 'fieldset',
      '#title' => t($s['display_name']),
      '#weight' => $weight,
      '#collapsible' => true,
      '#collapsed' => ($s['display'] ? false : true),
      '#tree' => true,
    );
    
    // if the view or edit columns are not visible, sort them to the very bottom
    if ((($f == '@user_view') or ($f == '@user_edit')) and (!$s['display'])) {
      if ($f == '@user_view') {
        $form['f'][$f . '_fs']['#weight'] = 1500;
      }
      elseif ($f == '@user_edit') {
        $form['f'][$f . '_fs']['#weight'] = 1501;
      }
    }
    
    // display the description of the column
    $form['f'][$f . '_fs']['description'] = array(
      '#type' => 'markup',
      '#value' => t($s['description']),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
    
    $form['f'][$f . '_fs']['display'] = array(
      '#type' => 'select',
      '#options' => array(
        SITE_USER_LIST_NO_DISPLAY => t('not displayed'),
        SITE_USER_LIST_HIDDEN_DISPLAY => t('hidden'),
        SITE_USER_LIST_MAY_DISPLAY => t('may be displayed'),
        SITE_USER_LIST_DEFAULT_DISPLAY => t('displayed by default'),
        SITE_USER_LIST_ALWAYS_DISPLAY => t('always display'),
      ),
      '#default_value' => $s['display'],
    );
    
    $form['f'][$f . '_fs']['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Column weight'),
      '#default_value' => $s['weight'],
      '#delta' => variable_get('site_user_list_column_delta', 20),
    );
    
    $form['f'][$f . '_fs']['column_header'] = array(
      '#type' => 'textfield',
      '#title' => t('Column title'),
      '#default_value' => $s['column_header'],
    );
    
    if ($s['sort_column'] != '') {
      $can_sort = 0;
      if ($s['display']) {
        if ($s['sort_column'] == $s['sortable']) {
          $can_sort = 1;
        }
      }
      else {
        if ($s['sort_column'] != '') {
          $can_sort = 1;
        }
      }
      $form['f'][$f . '_fs']['sortable'] = array(
        '#type' => 'checkbox',
        '#title' => t('Allow this column to be sortable'),
        '#default_value' => $can_sort,
      );
    }
    if ($s['search_column'] != '') {
      $can_search = 0;
      if ($s['display']) {
        if ($s['search_column'] == $s['searchable']) {
          $can_search = 1;
        }
      }
      else {
        if ($s['search_column'] != '') {
          $can_search = 1;
        }
      }
      $form['f'][$f . '_fs']['searchable'] = array(
        '#type' => 'checkbox',
        '#title' => t('Allow this column to be searchable'),
        '#default_value' => $can_search,
      );
    }
    
    $form['f'][$f . '_fs']['template_options'] = array(
      '#type' => 'fieldset',
      '#title' => t('Template: ') . ($s['eval_template'] ? 'eval( ' : '') . check_plain($s['template']) . ($s['eval_template'] ? ' )' : ''),
      '#collapsible' => true,
      '#collapsed' => ($s['default_template'] == $s['template'] ? true : false),
    );

    $form['f'][$f . '_fs']['template_options']['template'] = array(
      '#type' => 'textfield',
      '#title' => t('Template'),
      '#default_value' => $s['template'],
      '#description' => t('Default value: ') . check_plain($s['default_template']),
    );

    if (($f != '@user_view') and ($f != '@user_edit')) {
      $form['f'][$f . '_fs']['template_options']['template_condition_columns'] = array(
        '#type' => 'textfield',
        '#title' => t('Conditional Column'),
        '#default_value' => $s['template_condition_columns'],
        '#description' => t('A column which must have a non-blank value in it for the template to be run.  If the column is ==\'\', the cell will be blank.') . '  ' . t('Default value: ') . check_plain($s['default_template_condition_columns']),
      );
    
      $form['f'][$f . '_fs']['template_options']['eval_template'] = array(
        '#type' => 'checkbox',
        '#title' => t('use eval for this template'),
        '#default_value' => $s['eval_template'],
        '#description' => t('If your template should be treated as PHP, check this.  This could slow down things a <strong>lot</strong>.  PHP templates should return a value to be displayed (using "return"). The columns available are stored in "$r".  If you don\'t eval the template, it will be passed through "strtr" with the column names (like "@uid", which is guaranteed to always be there) available.'),
      );
    }
    
    $form['f'][$f . '_fs']['db_column'] = array(
      '#type' => 'value',
      '#value' => $s['db_column'],
    );
    $form['f'][$f . '_fs']['search_column'] = array(
      '#type' => 'value',
      '#value' => $s['search_column'],
    );
    $form['f'][$f . '_fs']['sort_column'] = array(
      '#type' => 'value',
      '#value' => $s['sort_column'],
    );
  }

  $form[] = array(
    '#type' => 'submit',
    '#value' => t('Save field settings'),
  );
  
  return $form;
}

function site_user_list_fields_form_submit($form, &$form_state) {
  // rather than run into any kind of cache issues, or worrying about having to figure out what
  // changed, we'll delete everything and reinsert.  Since we're probably on the order of < 20
  // items to be inserted, this shouldn't slow things down.
  db_query("DELETE FROM {site_user_list_fields}");

  foreach($form_state['values']['a_fields'] as $f) {
    $d = $form_state['values'][$f . '_fs'];
    $d['field_identifier'] = $f;
    // if we shouldn't sort or search on this item, just suppress the column name
    if (!$d['sortable']) {
      $d['sort_column'] = '';
    }
    if (!$d['searchable']) {
      $d['search_column'] = '';
    }
    if (!$d['template_options']['template_condition_columns']) {
      $d['template_options']['template_condition_columns'] = '';
    }
    
    if ($d['display']) {
      db_query("INSERT INTO {site_user_list_fields} (field_identifier, display, column_header, weight, db_column, search_column, sort_column, eval_template, template_condition_columns, template)
                VALUES ('%s', %d, '%s', %d, '%s', '%s', '%s', %d, '%s', '%s')",
                $d['field_identifier'], $d['display'], $d['column_header'], $d['weight'],
                $d['db_column'], $d['search_column'], $d['sort_column'], $d['template_options']['eval_template'],
                $d['template_options']['template_condition_columns'], $d['template_options']['template']);
    }
  }
  
  site_user_list_build();

  drupal_set_message(t('The settings have been saved'));
}

/**
 * get rid of both view and table;
 * needed because DROP TABLE and DROP VIEW are different SQL statements
 */
function _site_user_list_drop_all() {
  if (db_table_exists('{site_user_list_view}')) {
    db_query("DROP VIEW {site_user_list_view}");
    if (variable_get('site_user_list_log_rebuilds', 0)) {
      watchdog('site_user_list', 'Dropped view with SQL: DROP VIEW {site_user_list_view}');
    }
  }
  if (db_table_exists('{site_user_list_table}')) {
    db_query("DROP TABLE {site_user_list_table}");
    if (variable_get('site_user_list_log_rebuilds', 0)) {
      watchdog('site_user_list', 'Dropped table with SQL: DROP TABLE {site_user_list_table}');
    }
  }
}
