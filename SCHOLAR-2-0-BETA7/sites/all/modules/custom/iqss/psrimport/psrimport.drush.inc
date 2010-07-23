<?php

/**
 * Implementation of hook_drush_help().
 */
function psrimport_drush_help($section) {
  switch ($section) {
    case 'drush:psrimport':
      return dt("Begins import process for PSR site information to Scholars' Projects site.");
  }
}

/**
 * Implementation of hook_drush_command().
 */
function psrimport_drush_command() {
  $items['psrimport'] = array(
    'callback' => 'psrimport_import',
    'callback arguments' => array(1),
    'description' => "Begins import process for PSR site information to Scholars' Projects site.",
  );
  return $items;
}