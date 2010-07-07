<?php
/**
 *  template for theming the top area of the layout page (list of widgets)
 *  Variables:
 *  ----------
 *  $wgts -> list of all the widgets (dpm($wgts) for more info)
 */
?>

<div class="prev"></div><div class="next"></div>
<div id="scholarlayout-top-widgets">
	<ul class = "scholarlayout-top-widgets-list" >
	<?php foreach($wgts as $s_widget_key => $w):?>
		<li class="scholarlayout-item" id="<?php print $s_widget_key; ?>"> <?php print $w['label']; ?> </li>
	<?php endforeach?>
	</ul>
</div>
