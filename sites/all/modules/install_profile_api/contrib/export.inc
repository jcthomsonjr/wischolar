<?php
// $Id: export.inc,v 1.1.2.4 2009/05/29 23:25:12 jamesandres Exp $

/**
 * @file
 * CRUD functions for node_export (aka "export") module.
 */

/**
 * Import a node from a file.
 *
 * @param $file
 *   The path to a file containing the export.
 * @param $properties
 *   An array of node properties to override for each node imported.
 * @param $author
 *   The user all imported nodes should be authored by.
 */
function install_node_export_import_from_file($file, $properties = array(), $author = NULL) {
  if (!file_exists($file)) {
    drupal_set_message(t('The file !file could not be found or opened.', array('!file' => $file)));
    return FALSE;
  }

  global $user;

  // If the author isn't specified, use the logged in user
  if (!$author) {
    $author = $user;
  }

  // Default node properties
  $default_properties = array(
    'nid'     => NULL,
    'vid'     => NULL,
    'name'    => $author->name,
    'uid'     => $author->uid,
    'created' => NULL,
    'menu'    => NULL,
    'book'    => array('mlid' => NULL),
    'files'   => array(),
  );
  $properties = array_merge($default_properties, $properties);

  // This bit borrowed from node_export module, it wasn't possible to use
  // drupal_execute because the export_node_import() function deals with
  // $_POST directly.  When that issue is fixed, it should be feasible
  // to use reuse the node_export code.
  $export = file_get_contents($file);
  $node_code = str_replace('node(code(', 'array(array(', $export);
  $imported_nodes = eval("return " . $node_code . ";");

  $saved_nodes = array();

  foreach ($imported_nodes as $node) {
    $node = (object) $node;

    foreach ($properties as $key => $value) {
      $node->$key = $value;
    }

    node_save($node);

    $saved_nodes[] = $node;
  }

  return $saved_nodes;
}
