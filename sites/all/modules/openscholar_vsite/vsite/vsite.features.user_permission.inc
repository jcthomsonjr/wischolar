<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_user_default_permissions() {
  $permissions = array();

  // Exported permission: create openscholar site on behalf of others
  $permissions['create openscholar site on behalf of others'] = array(
    'name' => 'create openscholar site on behalf of others',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
    ),
  );

  // Exported permission: create own openscholar site
  $permissions['create own openscholar site'] = array(
    'name' => 'create own openscholar site',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
