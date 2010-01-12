<?php
// $Id: image.inc,v 1.1 2009/07/28 00:03:44 deciphered Exp $
/**
 * @file
 * Contains Image module integration for the File Aliases module.
 */

/**
 * Implementation of file_aliases_hook_process().
 */
function file_aliases_image_process(&$node, &$file, &$path, &$alias, &$count) {
  $node->content['image']['#value'] = str_replace($file['field']['filepath'], $alias, $node->content['image']['#value']);
}

/**
 * Implementation of file_aliases_hook_views_handlers().
 */
function file_aliases_image_views_handlers(&$handlers) {
  $handlers['file_aliases_image_handler_field_image_node_image'] = array(
    'parent' => 'image_handler_field_image_node_image',
  );
}

/**
 * Implementation of file_aliases_hook_views_data_alter().
 */
function file_aliases_image_views_data_alter(&$data) {
  $data['node']['image_image']['field']['handler'] = 'file_aliases_image_handler_field_image_node_image';
}
