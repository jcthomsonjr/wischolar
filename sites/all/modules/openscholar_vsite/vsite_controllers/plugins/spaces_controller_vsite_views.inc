<?php
class spaces_controller_vsite_views extends spaces_controller {

  static $fields = array('header', 'header_format', 'header_empty', 'footer', 'footer_format', 'footer_empty');

  /**
   * Loads the original values
   * Is run on the first ::get() call
   * Don't expect any values for it before that
   * @see spaces_controller::load_original_values()
   */
  protected function load_original_values($id = NULL) {
    $view = views_get_view($id);

    $this->values['original'][$view->name] = array();
    foreach (spaces_controller_vsite_views::$fields as $f) {
      if (isset($views->display_handler->options[$f])) {
        $this->values['original'][$view->name][$f] = $views->display_handler->options[$f];
      }
    }
  }
}