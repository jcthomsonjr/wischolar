<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_widgets_user_default_permissions() {
  $permissions = array();

  // Exported permission: view addthis
  $permissions['view addthis'] = array(
    'name' => 'view addthis',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
		  '4' => 'administrator',
		  '5' => 'manager',
    ),
  );

  return $permissions;
}
