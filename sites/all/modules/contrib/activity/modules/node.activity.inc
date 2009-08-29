<?php
// $Id: node.activity.inc,v 1.1.2.9 2009/06/15 22:58:41 scottreynolds Exp $

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