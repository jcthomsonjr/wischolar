<?php
// $Id: user.activity.inc,v 1.1.2.10 2009/08/02 15:22:01 sirkitree Exp $

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