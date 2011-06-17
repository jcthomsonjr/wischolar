<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_cc_user_default_permissions() {
  $permissions = array();

  // Exported permission: use creative commons user defaults
  $permissions['use creative commons user defaults'] = array(
    'name' => 'use creative commons user defaults',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer creative commons
  $permissions['administer creative commons'] = array(
    'name' => 'administer creative commons',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: attach creative commons
  $permissions['attach creative commons'] = array(
    'name' => 'attach creative commons',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  return $permissions;
}
