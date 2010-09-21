<?php

function gking_biblio_download_links($node = NULL) {
  $files = '';
  if (!empty ($node->files) && count($node->files) > 0 && user_access('view uploaded files')) {
    $files .= '<span class="biblio_file_links">';
    //$files .= '&nbsp;'. t('Download') .':&nbsp;';
    $file_count = 0;
    foreach ($node->files as $file) {
      if ($file->list) {
        $file_count++;
        $alias = db_result(db_query("SELECT dst FROM {url_alias} WHERE src = '%s'",'filefield_paths/alias/' . $file -> fid));
        $href = ($alias) ?  $alias : file_create_url($file->filepath);
        $text = $file->description ? $file->description : $file->filename;
        //$files .= l($text, $href) .'&nbsp;('. format_size($file->filesize).')';
        $files .= l($text, $href);
      }
    }
    $files .= '</span>';
  }
  if (module_exists('filefield')) { // now lets get any CCK FileField files...
    $fields = filefield_get_field_list('biblio');
    foreach ($fields as $field_name => $field) {
      if (filefield_view_access($field_name, $node)) {
        $field_files = filefield_get_node_files($node, $field_name);
        if ($field_files) {
          foreach ($field_files as $file) {
            if ($file['fid']) {
              $files .= theme('filefield_file', $file);
            }
          }
        }
      }
    }
  }

  return $files;
}
