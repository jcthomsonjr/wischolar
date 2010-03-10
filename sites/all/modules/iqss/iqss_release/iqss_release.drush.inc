<?php
// $Id: iqss_release.drush.inc,v 1.0 2010/03/10 11:59:54 rbrandon Exp $

/**
 * @file
 * Drush integration for iqss release. Provides commands for upgrading
 */

/**
 * Implementation of hook_drush_help().
 */
function iqss_release_drush_help($section) {
  switch ($section) {
    case 'drush:iqss-release':
      return dt("Upgrade iqss scholar to the newest version. The first argumaent should be the profile ex(scholar or project). Results will print to stdout.");
  }
}

/**
 * Implementation of hook_drush_command().
 */
function iqss_release_drush_command() {
  $items['iqss-release'] = array(
    'callback' => 'drush_iqss_release_release',
    'description' => 'Upgrade IQSS core.',
  );
  return $items;
}

// Callback for iqss_release command.
function drush_iqss_release_release($s_preset = false) {
	// Report simple running errors
  error_reporting(E_ERROR | E_PARSE);

  require_once(drupal_get_path('module', 'iqss_release') .'/iqss_release.module');
  $a_info = _iqss_release_process_updates($s_preset);
  drush_print($a_info['messages']);
   
	drush_print($a_info['status']);
}