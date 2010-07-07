<?php
/**
 * template file for theming the theme_picker
 * Note that this is used just for the img, theme name and theme description
 * and not the html radios
 * Variables:
 * ----------
 * $info : the whole theme object  (dpm($info) to see everything
 * $sub_theme : the rendered select element for the subtheme
 *
 */


  $screenshot = t('no screenshoot available');
  if (file_exists($info['screenshot'])){
    $screenshot = theme('image', $info['screenshot'], t('Screenshot for %theme theme', array('%theme' => $info['name'])), '', array('class' => 'screenshot', 'id' => 'screenshot_'.$info['theme_name']), FALSE);
  }
?>
<div class="item-theme-picker">

  <?= $screenshot?>
  <h3><?= $info['name'] ?></h3><?= $sub_theme ?>
	<p> <?= $info['description'] ?></p>
</div>
