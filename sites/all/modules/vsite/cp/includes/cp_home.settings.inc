<?php
require_once( drupal_get_path('module', 'spaces').'/spaces.spaces.inc');

/**
 * Provides home override
 */
class cp_settings_home extends space_setting_home implements space_setting {


  function form($space, $value = array()) {
    //No Form the is disabled
  }

  function validate($space, $value) {
    //Overide any validation
  }

  //Don't even really need this, b/c there is no form to set a value we will never get here
  function submit($space, $value) {}
}

