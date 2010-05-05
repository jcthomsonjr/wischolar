<?php

/**
 * Implementation of hook_drush_help().
 */
function gkimport_drush_help($section) {
  switch ($section) {
    case 'drush:gkimport':
      return dt("Begins import process for current Gary's site information to his Scholars' Projects site.");
      break;

    case 'drush:gkimport-export-layout':
      return dt("Exports layout settings to serialized string.");
      break;

    case 'drush:gkimport-save-layout':
      return dt("Exports layout settings to serialized string.");
      break;
  }
}

/**
 * Implementation of hook_drush_command().
 */
function gkimport_drush_command() {
  $items['gkimport'] = array(
  'callback' => 'gkimport_import',
  'callback arguments' => array(1),
  'description' => "Begins import process for current Gary's site information to his Scholars' Projects site.",
  );

  $items['gkimport-export-layout'] = array(
  'callback' => 'gkimport_export_site_layout',
  'callback arguments' => array(1),
  'description' => "Exports layout settings to serialized string",
  );

  $items['gkimport-save-layout'] = array(
  'callback' => 'gkimport_save_site_layout',
  'callback arguments' => array(1),
  'description' => "Imports saved layout settings to site",
  );
  return $items;
}