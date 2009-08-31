<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_publications_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'publication',
    'description' => '',
    'node' => array(
      '0' => 'biblio',
    ),
  );
  return $items;
}
