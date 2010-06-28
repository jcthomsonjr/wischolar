<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_book_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Booklet'),
      'module' => 'features',
      'description' => t('A <em>booklet</em> is a series of content pages organized into a collection of related entries. Each <em>booklet page</em> automatically displays links to adjacent pages, providing a simple navigation system for organizing and reviewing structured content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
