<?php

// Declare all the .view files in the views subdir that end in .view
function vsite_front_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'vsite_front'). '/includes', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      // vsite_front. is 9 char long
      $views[substr($file->name, 12)] = $view;
    }
  }
  return $views;
}