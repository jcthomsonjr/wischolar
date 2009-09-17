<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_user_default_permissions() {
  $permissions = array();

  // Exported permission: configure spaces features
  $permissions[] = array(
    'name' => 'configure spaces features',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: search content
  $permissions[] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: upload files
  $permissions[] = array(
    'name' => 'upload files',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: view advanced help popup
  $permissions[] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: view advanced help topic
  $permissions[] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: view uploaded files
  $permissions[] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: view users outside groups
  $permissions[] = array(
    'name' => 'view users outside groups',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
