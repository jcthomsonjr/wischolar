<?php
// $Id: user.activity.inc,v 1.1.2.17 2010/05/15 22:29:17 scottreynolds Exp $

/**
 * @file
 * Activity definition file for user.module
 */

/**
 * Implementation of hook_activity_type_check().
 */
function user_activity_type_check($token_objects, $types) {
  // $types has the role id as values and $token_objects['account']->roles has
  // the role id as keys. Need to get them to match up before checking for
  // intersection.
  $intersection = array_intersect(array_keys($token_objects['account']->roles), $types);
  return !empty($intersection);
}

/**
 * Implementation of hook_activity_token_list().
 */
function user_activity_token_list($type = 'all') {
  if ($type == 'user' || $type == 'all') {
    return array(
      'user' => array(
        'activity-user-link' => t('Link to the user. Used only when doing user based activity (i.e \'login\' \'update\' etc)'),
      ),
    );
  }
  return array();
}

/**
 * Implementation fo hook_activity_token_values().
 */
function user_activity_token_values($type, $object = NULL, $options = array()) {
  if ($type == 'user') {
    return array(
      'activity-user-link' => theme('activity_username', $object),
    );
  }
  return array();
}