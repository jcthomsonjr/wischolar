<?php

// Declare all the .view files in the views subdir that end in .view
function cp_front_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'cp_front'). '/includes', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      // cp_front. is 9 char long
      $views[substr($file->name, 9)] = $view;
    }
  }
  return $views;
}