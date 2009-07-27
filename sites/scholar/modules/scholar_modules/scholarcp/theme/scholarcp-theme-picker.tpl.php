<?php
/**
 * template file for theming the theme_picker
 * Note that this is used just for the img, theme name and theme description
 * and not the html radios
 * Variables:
 * ----------
 * $info : the whole theme object  (dpm($info) to see everything
 * 
 */

  $screenshot = t('no screenshoot available');
  if (file_exists($info['screenshot'])){
    $screenshot = theme('image', $info['screenshot'], t('Screenshot for %theme theme', array('%theme' => $info['theme_name'])), '', array('class' => 'screenshot'), FALSE);
  }
  print '<div class= "item-theme-picker">' .$screenshot . $info['theme_name'] . $info['description'] . '</div>';
?>