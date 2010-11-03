<?php
/**
 * template file for the theme_picker list that allows you to select a theme
 *
 * Variables:
 * ----------
 * $count : the number of themes
 *
 */

?>
<div class="theme_subnav">
  <h3>Select a Theme</h3>
  <div id="prev" class="theme-pointer"></div>
  <ul>
<?php
for($i=1;$i<=$count;$i++) {
  print "<li>&nbsp;{$i}&nbsp;</li>";
}
?>
  </ul>
  <div id="next" class="theme-pointer"></div>
</div>
