<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_user_default_permissions() {
  $permissions = array();

  // Exported permission: access site-wide contact form
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: attach creative commons
  $permissions['attach creative commons'] = array(
    'name' => 'attach creative commons',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: collapse format fieldset by default
  $permissions['collapse format fieldset by default'] = array(
    'name' => 'collapse format fieldset by default',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: collapsible format selection
  $permissions['collapsible format selection'] = array(
    'name' => 'collapsible format selection',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: create openscholar site on behalf of others
  $permissions['create openscholar site on behalf of others'] = array(
    'name' => 'create openscholar site on behalf of others',
    'roles' => array(),
  );

  // Exported permission: create own openscholar site
  $permissions['create own openscholar site'] = array(
    'name' => 'create own openscholar site',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar user',
    ),
  );

  // Exported permission: create users
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: create vsite content
  $permissions['create vsite content'] = array(
    'name' => 'create vsite content',
    'roles' => array(),
  );

  // Exported permission: edit own vsite content
  $permissions['edit own vsite content'] = array(
    'name' => 'edit own vsite content',
    'roles' => array(),
  );

  // Exported permission: show format selection for blocks
  $permissions['show format selection for blocks'] = array(
    'name' => 'show format selection for blocks',
    'roles' => array(),
  );

  // Exported permission: show format selection for comments
  $permissions['show format selection for comments'] = array(
    'name' => 'show format selection for comments',
    'roles' => array(),
  );

  // Exported permission: show format selection for nodes
  $permissions['show format selection for nodes'] = array(
    'name' => 'show format selection for nodes',
    'roles' => array(),
  );

  // Exported permission: show format tips
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
  );

  // Exported permission: show more format tips link
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
  );

  // Exported permission: upload files
  $permissions['upload files'] = array(
    'name' => 'upload files',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: use creative commons user defaults
  $permissions['use creative commons user defaults'] = array(
    'name' => 'use creative commons user defaults',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'scholar admin',
    ),
  );

  // Exported permission: view advanced help popup
  $permissions['view advanced help popup'] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: view advanced help topic
  $permissions['view advanced help topic'] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: view uploaded files
  $permissions['view uploaded files'] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
