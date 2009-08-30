<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_publications_node_info() {
  $items = array(
    'biblio' => array(
      'name' => t('Biblio'),
      'module' => 'biblio',
      'description' => t('Manages bibliographies'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}
