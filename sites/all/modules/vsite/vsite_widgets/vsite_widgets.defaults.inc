<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_widgets_user_default_permissions() {
  $permissions = array();

  // Exported permission: search content
  $permissions[] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
