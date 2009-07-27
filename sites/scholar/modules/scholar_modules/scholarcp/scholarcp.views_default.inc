<?php

// Declare all the .view files in the views subdir that end in .view
function scholarcp_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'scholarcp'). '/views', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      $views[substr($file->name, 10)] = $view;
      //$views['mainview'] = $view;
    }
  }
  dpm($views);
  return $views;
}
