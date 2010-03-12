<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_pages_user_default_permissions() {
  $permissions = array();

  // Exported permission: create page content
  $permissions[] = array(
    'name' => 'create page content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own page content
  $permissions[] = array(
    'name' => 'delete own page content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own page content
  $permissions[] = array(
    'name' => 'edit own page content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override page promote to front page option
  $permissions[] = array(
    'name' => 'override page promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override page published option
  $permissions[] = array(
    'name' => 'override page published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override page revision option
  $permissions[] = array(
    'name' => 'override page revision option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override page sticky option
  $permissions[] = array(
    'name' => 'override page sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}
