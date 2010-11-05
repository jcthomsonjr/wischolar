<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_comments_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments
  $permissions[] = array(
    'name' => 'access comments',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: post comments
  $permissions[] = array(
    'name' => 'post comments',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: post comments without approval
  $permissions[] = array(
    'name' => 'post comments without approval',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
