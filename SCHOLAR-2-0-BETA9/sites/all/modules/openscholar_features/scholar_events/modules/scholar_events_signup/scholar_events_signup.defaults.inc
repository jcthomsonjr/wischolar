<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_events_signup_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer all signups
  $permissions[] = array(
    'name' => 'administer all signups',
    'roles' => array(),
  );

  // Exported permission: administer signups for own content
  $permissions[] = array(
    'name' => 'administer signups for own content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: cancel own signups
  $permissions[] = array(
    'name' => 'cancel own signups',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: cancel signups
  $permissions[] = array(
    'name' => 'cancel signups',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own signups
  $permissions[] = array(
    'name' => 'edit own signups',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'scholar admin',
      '2' => 'scholar user',
    ),
  );

  // Exported permission: email all signed up users
  $permissions[] = array(
    'name' => 'email all signed up users',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: email users signed up for own content
  $permissions[] = array(
    'name' => 'email users signed up for own content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: sign up for content
  $permissions[] = array(
    'name' => 'sign up for content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: view all signups
  $permissions[] = array(
    'name' => 'view all signups',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
