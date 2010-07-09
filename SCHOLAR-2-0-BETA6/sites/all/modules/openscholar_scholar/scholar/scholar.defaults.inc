<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments
  $permissions[] = array(
    'name' => 'access comments',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
