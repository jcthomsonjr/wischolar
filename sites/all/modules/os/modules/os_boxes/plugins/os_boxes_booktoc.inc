<?php

/**
 * @file
 * The class for "Book Table of Contents" type widgets.
 */


class os_boxes_booktoc extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['book_nid'] = 0;
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {

    $view = views_get_view('scholar_book_list');
    $view->execute('default');

    $options = array(0 => 'Select Book');
    foreach ($view->result as $row) {
      $options[$row->nid] = $row->node_title;
    }
    $form = array(
      '#type' => 'select',
      '#title' => t('Which Book'),
      '#options' => $options,
      '#default_value' => $this->options['book_nid'],
    );

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $block['title'] = $title;
    $block['subject'] = $title;
    $block['delta'] = $this->delta;
    return $block;
  }
}
