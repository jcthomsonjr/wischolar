<?php
// $Id: comment.activity.inc,v 1.1.2.12 2009/06/15 22:58:41 scottreynolds Exp $

/**
 * @file
 * Activity definition file for comment.module
 */

/**
 * Implementation of hook_activity_grants().
 */
function comment_activity_grants($activity) {
  $grants = array();
  if (!empty($activity->nid)) {
    // tell activity to record 'comment' | nid
    $grants = array(
      'comment' => array($activity->nid),
    );
  }
  return $grants;
}

/**
 * Implementation of hook_activity_access_grants().
 */
function comment_activity_access_grants($account) {
  // tell activity what activities this user has based on the 'comment' realm
  $grants = array();
  
  // select the nodes you have created
  $created_result = db_query("SELECT nid FROM {node} WHERE uid = %d", $account->uid);
  while ($created = db_fetch_object($created_result)) {
    $grants['comment'][] = $created->nid;
  }
  
  // select the nodes you commented on
  $commented_result = db_query("SELECT nid FROM {comments} WHERE uid = %d", $account->uid);
  while ($commented = db_fetch_object($commented_result)) {
    $grants['comment'][] = $commented->nid;
  }
  return $grants;
}

/**
 * Implementation of hook_activity_type_check().
 */
function comment_activity_type_check($token_objects, $types) {
  return (in_array($token_objects['node']->type, $types));
}