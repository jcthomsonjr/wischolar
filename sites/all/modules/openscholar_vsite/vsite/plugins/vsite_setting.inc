<?php

/**
 * Interface for vsite settings.
 */
interface vsite_setting {
  function __construct($id = NULL);
  function form($space, $value = array());
  function validate($space, $value);
  function submit($space, $value);
}