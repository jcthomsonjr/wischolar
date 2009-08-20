<?php

// Declare all the .view files in the views subdir that end in .view
function cp_content_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'cp_content'). '/includes', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      // cp_content. is 10 char long
      $views[substr($file->name, 11)] = $view;
    }
  }
  return $views;
}
