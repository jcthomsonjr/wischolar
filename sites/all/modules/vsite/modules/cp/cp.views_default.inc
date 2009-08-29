<?php

// Declare all the .view files in the views subdir that end in .view
function cp_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'cp'). '/views', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      // cp. is 10 char long
      $views[substr($file->name, 3)] = $view;
    }
  }
  return $views;
}
