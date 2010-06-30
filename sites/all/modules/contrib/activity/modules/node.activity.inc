<?php
// $Id: node.activity.inc,v 1.1.2.20 2010/05/15 22:29:17 scottreynolds Exp $

/**
 * @file
 * Activity definition file for node.module
 */

/**
 * Implementation of hook_activity_type_check().
 */
function node_activity_type_check($token_objects, $types) {
  return (in_array($token_objects['node']->type, $types));
}

/**
 * Implementation of hook_activity_token_list().
 */
function node_activity_token_list($type = 'all') {
  if ($type == 'node' || $type == 'all') {
    return array(
      'node' => array(
        'activity-node-link' => t('Link to the node'),
        'activity-node-creator-link' => t('Link to the node creator'),
      ),
    );
  }
  return array();
}

/**
 * Implementation of hook_activity_token_values().
 */
function node_activity_token_values($type, $object = NULL, $options = array()) {
  if ($type == 'node') {
    return array(
      'activity-node-link' => l($object->title, "node/{$object->nid}"),
      'activity-node-creator-link' => theme('activity_username', $object),
    );
  }
  return array();
}

/**
 * Implementation of hook_activity_grants().
 */
function node_activity_grants($activity) {
  $grants = array();
  if (!empty($activity->nid)) {
    $grants = array(
      'node_author' => array(
        $activity->nid
      ),
    );
  }
  return $grants;
}

/**
 * Implementation of hook_activity_access_grants().
 */
function node_activity_access_grants($account) {
  $grants = array();

  // Select the nodes you have created.
  $created_result = db_query("SELECT nid FROM {node} WHERE uid = %d", $account->uid);
  while ($created = db_fetch_object($created_result)) {
    $grants['node_author'][] = $created->nid;
  }

  return $grants;
}

/**
 * Implementation of hook_activity_objects_alter().
 */
function node_activity_objects_alter(&$token_objects, $activity_type) {
  if ($activity_type == 'node') {
    $token_objects['user'] = $GLOBALS['user'];
  }
}
