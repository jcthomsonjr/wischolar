<?php
// $Id: activity.views.inc,v 1.1.2.12 2009/08/25 18:34:42 sirkitree Exp $
/**
 * @file: provides views data integration for activity module as the base table
 */

/**
 * Implementation of hook_views_data().
 */
function activity_views_data() {
  $data['activity']['table']['group'] = t('Activity');
  
  $data['activity']['table']['base'] = array(
    'field' => 'aid',
    'title' => t('Activity'),
    'help' => t('Activity are items that are recorded for a users activity within the site'),
  );
  
  // Database columns
  $data['activity']['uid'] = array(
    'title' => t('Activity Actor'),
    'help' => t('The ID of the person who recorded the activity'),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['activity']['access_uid'] = array(
    'title' => t('Allow Access to the Actor'),
    'help' => t('Allow the actor to see their own activity'),
    'group' => t('Activity Access'),
    'filter' => array(
      'handler' => 'activity_views_handler_filter_uid_access',
      'field' => 'uid',
    ),
  );
  $data['activity']['op'] = array(
    'title' => t('Operation'),
    'help' => t('The operation being performed (update, insert, etc.)'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['activity']['type'] = array(
    'title' => t('Type'),
    'help' => t('The type of object being acted upon (node, user, etc.)'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['activity']['created'] = array(
    'title' => t('Activity Creation Date'),
    'help' => t('The time that the activity was created'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  
  $data['activity_access']['table']['group'] = t('Activity Access');
  $data['activity_access']['table']['join'] = array(
    'activity' => array(
      'type' => 'INNER',
      'left_field' => 'aid',
      'field' => 'aid',
    ),
  );
    
  foreach (activity_get_module_info() as $module => $info) {
    if (!empty($info->realms)) {
      $data['activity_access']["value_$module"] = array(
        'title' => t("@module Access", array("@module" => drupal_ucfirst($module))),
        'help' => t('Allow @module to filter activity messages', array('@module' => $module)),
        'filter' => array(
          'handler' => 'activity_views_handler_filter_access',
          'module' => $module,
          'field' => 'value',
        ),
      );
    }
  }
  
  // describe the targets table so Views knows how to join it in
  // this table will be used to join the activity table to the message table
  $data['activity_targets']['table'] = array(
    'group' => t('Activity'),
    'join' => array(
      'activity' => array(
        'type' => 'INNER',
        'left_field' => 'aid',
        'field' => 'aid',
        'extra' => array(
          array(
            'value' => 0, // grab the non-personal message
            'numeric' => TRUE,
            'field' => 'uid',
          ),
        ),
      ),
    ),
  );
  
  // describe the personal targets table so Views knows how to join it in
  // this table will be used to join the activity table to the personal message table
  $data['activity_personal_targets']['table'] = array(
    'group' => t('Activity'),
    'join' => array(
      'activity' => array(
        'type' => 'LEFT',
        'left_field' => 'aid',
        'field' => 'aid',
        'extra' => array(
          array(
            'value' => '***CURRENT_USER***', // grab the personal message
            'numeric' => TRUE,
            'field' => 'uid',
          ),
        ),
        'table' => 'activity_targets',
      ),
    ),
  );
  
  // add in the activity message table
  $data['activity_messages']['table']['group'] = t('Activity');
  $data['activity_messages']['table']['join'] = array(
    'activity' => array(
      'left_table' => 'activity_targets',
      'left_field' => 'amid',
      'field' => 'amid',
      'type' => 'INNER',
    ),
  );
  
  // create a faux table, that is really activity messages
  $data['activity_personal_messages']['table']['join'] = array(
    'activity' => array(
      'left_table' => 'activity_personal_targets',
      'left_field' => 'amid',
      'field' => 'amid',
      'type' => 'LEFT',
      'table' => 'activity_messages',
    ),
  );
  
  $data['activity_messages']['message'] = array(
    'title' => t('Message'),
    'help' => t('The message may or may not be personalized for the user. Just depends on if the user was involved in the Action'),
    'field' => array(
      'handler' => 'activity_views_handler_field_message',
    ),
  );
  
  // Links to operate upon the activity records
  $data['activity']['delete_activity'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the activity.'),
      'handler' => 'activity_handler_field_activity_link_delete',
    ),
  );
  
  return $data;
}

/**
 * Implementation of hook_views_data_alter() to add items from the users table.
 */
function activity_views_data_alter(&$data) {
  $data['users']['table']['join']['activity'] = array(
    'left_table' => 'activity',
    'left_field' => 'uid',
    'field' => 'uid',
  );
  $data['node']['table']['join']['activity'] = array(
    'left_table' => 'activity',
    'left_field' => 'nid',
    'field' => 'nid',
  );
  // do CCK mappings here
  if (module_exists('content')) {
    foreach (content_fields() as $field) {
      $module = $field['module'];
      $result = module_invoke($module, 'field_settings', 'views data', $field);
      if (empty($result)) {
        // setup up result getting the defaults
        $table_alias = content_views_tablename($field);
        $db_info = content_database_info($field);
        $table = $db_info['table'];
      }
      if (is_array($result)) {
        $table_alias = key($result);
        $table = $result[$table_alias]['table']['join']['node']['table'];
      }
      if (isset($table_alias)) {
        $data[$table_alias]['table']['join']['activity'] = array(
          'left_table' => 'activity',
          'left_field' => 'nid',
          'field' => 'nid',
          'table' => $table,
        );
      }
    }
  }
}

/**
 * Implementation of hook_views_handlers().
 */
function activity_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'activity') . '/views',
    ),
    'handlers' => array(
      'activity_views_handler_field_message' => array(
        'parent' => 'views_handler_field',
      ),
      'activity_views_handler_filter_access' => array(
        'parent' => 'views_handler_filter',
      ),
      'activity_views_handler_filter_uid_access' => array(
        'parent' => 'views_handler_filter',
      ),
      'activity_handler_field_activity_link' => array(
        'parent' => 'views_handler_field',
      ),
      'activity_handler_field_activity_link_delete' => array(
        'parent' => 'activity_handler_field_activity_link',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_query_alter().
 */
function activity_views_query_alter(&$view, &$query) {
  if ($query->get_table_info('activity_access')) {
    $query->set_distinct();
  }
}

/**
 * return the group id for the where clause
 */
function activity_views_group($new_group = NULL) {
  static $group_id = NULL;
  if (isset($new_group)) {
    $group_id = $new_group;
  }
  
  return $group_id;
}
