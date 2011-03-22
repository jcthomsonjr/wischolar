<?php

/**
 * Provides home override
 */
class cp_settings_home implements vsite_setting {

  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'home';
    }
  }

  function form($space, $value = array()) {
    $options = array(0 => '---');

    // This is exceedingly hackish but effective way of ensuring that
    // the link options provided are correct, especially when being
    // generated on preset forms.
//    $original = spaces_get_space();
//    spaces_set_space($space, TRUE);
//    $links = features_menu_links();
//    spaces_set_space($original, TRUE);

    $form = array();
//    if (count($links)) {
//      foreach ($links as $link) {
//        $options[$link['href']] = $link['title'];
//      }
//      $form = array(
//        '#title' => t('Homepage'),
//        '#description' => t('The default page for this space.'),
//        '#type' => 'select',
//        '#options' => $options,
//        '#default_value' => $value ? $value : 0,
//      );
//    }
    return $form;
  }

  function validate($space, $value) {
    // Exclude space "prototypes" (like that used for the preset form)
    /*
    if ($space->sid) {
      if (!$value && is_array($space->features) && (array_sum($space->features) != 0)) {
        form_set_error('settings]['. $this->id, t('You must select a homepage for this space.'));
      }
    }
    */
  }

  function submit($space, $value) {
    return $value;
  }
}

