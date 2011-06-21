<?php



/**
 * Implementation of hook_flag_default_flags().
 */
function citation_distribute_flag_default_flags() {
  $flags = array();
  // Exported flag: "".
  $flags['citation_distribute_service'] = array(
    'content_type' => 'node',
    'title' => '',
    'global' => FALSE,
    'types' => array(
      '0' => 'biblio',
    ),
    'flag_short' => NULL,
    'flag_long' => NULL,
    'flag_message' => '',
    'unflag_short' => 'Remove from ',
    'unflag_long' => 'Remove from ',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        '0' => '2',
      ),
      'unflag' => array(
        '0' => '2',
      ),
    ),
    'show_on_page' => FALSE,
    'show_on_teaser' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'citation_distribute',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "SWORD".
  $flags['service_sword'] = array(
    'content_type' => 'node',
    'title' => 'SWORD',
    'global' => FALSE,
    'types' => array(
      '0' => 'biblio',
    ),
    'flag_short' => 'SWORD',
    'flag_long' => 'SWORD',
    'flag_message' => '',
    'unflag_short' => 'Remove from SWORD',
    'unflag_long' => 'Remove from SWORD',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        '0' => '2',
      ),
      'unflag' => array(
        '0' => '2',
      ),
    ),
    'show_on_page' => FALSE,
    'show_on_teaser' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'citation_distribute',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "DASH".
  $flags['sword_dash'] = array(
    'content_type' => 'node',
    'title' => 'DASH',
    'global' => FALSE,
    'types' => array(
      '0' => 'biblio',
    ),
    'flag_short' => 'DASH',
    'flag_long' => 'DASH',
    'flag_message' => '',
    'unflag_short' => 'Remove from DASH',
    'unflag_long' => 'Remove from DASH',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        '0' => '2',
      ),
      'unflag' => array(
        '0' => '2',
      ),
    ),
    'show_on_page' => FALSE,
    'show_on_teaser' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'citation_distribute',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
    // Exported flag: "google".
  $flags['google'] = array(
    'content_type' => 'node',
    'title' => 'Google Scholar',
    'global' => FALSE,
    'types' => array(
      '0' => 'biblio',
    ),
    'flag_short' => 'Google Scholar',
    'flag_long' => 'Google Scholar',
    'flag_message' => '',
    'unflag_short' => 'Remove from Google Scholar',
    'unflag_long' => 'Remove from Google Scholar',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        '0' => '2',
      ),
      'unflag' => array(
        '0' => '2',
      ),
    ),
    'show_on_page' => FALSE,
    'show_on_teaser' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'citation_distribute',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}
