<?php
/** 
 *  template for theming a list of widgets
 *  Variables:
 *  ----------
 *  $wgts -> list of all the widgets (dpm($wgts) for more info)
 *  $wgts_id -> the id of the ul
 *  $wgts_class -> the class of the ul
 */
?>

<ul id="<?php print $wgts_id; ?>" class = "<?php print $wgts_class; ?>">
	<?php foreach($wgts as $w):?>
		<li class="scholarlayout-item" id="<?php print $w['module']; ?>-<?php print $w['delta']; ?>"> <?php print $w['label']; ?> 
		<span class="scholarlayout-item-settings">Edit 
      <ul class="item-settings-popup">
        <li>Settings</li>
        <li>Settings</li>
        <li>Settings</li>
        <li>Settings</li>
        <li>Settings</li>
      </ul>
		 </span>
		</li>
	<?php endforeach?>
</ul>

