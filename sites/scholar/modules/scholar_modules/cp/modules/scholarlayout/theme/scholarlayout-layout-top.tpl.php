<?php
/** 
 *  template for theming the top area of the layout page (list of widgets)
 *  Variables:
 *  ----------
 *  $wgts -> list of all the widgets (dpm($wgts) for more info)
 */
?>
<div id="scholarlayout-top-widgets">
	<ul class = "scholarlayout-top-widgets-list">
	<?php foreach($wgts as $w):?>
		<li class="scholarlayout-item" id="<?php print $w['module']; ?>-<?php print $w['delta']; ?>"> <?php print $w['label']; ?> </li>
	<?php endforeach?>
	</ul>
</div>
