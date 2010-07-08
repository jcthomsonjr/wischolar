<?php


/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _iqss_remote_source_user_default_permissions() {
  $permissions = array();

  // Exported permission: create bio content
  $permissions[] = array(
    'name' => 'manage remote node source',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );


  return $permissions;
}