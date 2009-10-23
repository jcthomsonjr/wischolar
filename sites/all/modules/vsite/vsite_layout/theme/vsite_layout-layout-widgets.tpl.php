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
	  <?php $s_class = (isset($w['hidden']) && $w['hidden'])? 'scholarlayout-item disabled':'scholarlayout-item'; ?>
		<li class="<?= $s_class ?>" id="<?php print $w['module']; ?>_<?php print $w['delta']; ?>"> <?php print $w['label']; ?>
		<!--
		<span class="scholarlayout-item-settings">Edit
      <ul class="item-settings-popup">
        <li>Settings</li>
        <li>Settings</li>
        <li>Settings</li>
        <li>Settings</li>
        <li>Settings</li>
      </ul>
		 </span>
		 -->
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

		</li>
	<?php endforeach?>
</ul>

