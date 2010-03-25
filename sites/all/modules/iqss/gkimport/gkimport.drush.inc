<?php

/**
 * Implementation of hook_drush_help().
 */
function gkimport_drush_help($section) {
  switch ($section) {
    case 'drush:gkimport':
      return dt("Begins import process for current Gary's site information to his Scholars' Projects site.");
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
  return $items;
}