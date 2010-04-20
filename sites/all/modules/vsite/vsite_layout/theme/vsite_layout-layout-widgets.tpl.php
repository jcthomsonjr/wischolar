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
<div class="widget-prev"></div><div class="widget-next"></div>
<dl id="<?php print $wgts_id; ?>" class = "<?php print $wgts_class; ?>">
	<?php foreach($wgts as $s_widget_key => $w):?>
	  <?php $s_class = (isset($w['hidden']) && $w['hidden'])? 'scholarlayout-item disabled':'scholarlayout-item'; ?>
		<dt><?php print $s_region_name;?></dt>
		<dd class="<?= $s_class ?>" id="<?php print $s_widget_key; ?>"> <?php print $w['label']; ?>
		 <div class="close-this">Remove</div>
		 <?php
		 if($w['overides']){
		 	 ?>

		   <span class="scholarlayout-item-settings">Appears here on all pages with these <span>exceptions</span>
        <ul class="item-settings-popup">
		 	 <?php
		 	  foreach ($w['overides'] as $overide) print "<li>{$overide}</li>";
		 	 ?>
		 	  </ul>
		 	 </span>
		 	 <?php
		 }
		 ?>

		</dd>
	<?php endforeach?>
</dl>

