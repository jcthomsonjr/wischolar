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
  <dt><?php print $region_name;?></dt>
	<?php foreach($wgts as $s_widget_key => $w):?>
	  <?php $s_class = (isset($w['hidden']) && $w['hidden'])? 'scholarlayout-item disabled':'scholarlayout-item'; ?>
		<dd class="<?php echo $s_class ?><?php if($w['overides']) {?> with-overrides<?php } ?>" id="<?php print $s_widget_key; ?>"> <?php print $w['label']; ?>
		  <div class="close-this">Remove</div>
		 <?php
		 if($w['block_config_path']){
		 	 print ctools_modal_text_button("Configure",$w['block_config_path']."/cp_layout","open the form to configure this block","configure");
		 }
		 if($w['overides']){
		 	 ?>

		   <span class="scholarlayout-item-settings">Appears here on all pages with <span class="toggle-exceptions">exceptions</span>
        <div class="layout-exceptions">
          <h4>Exceptions:</h4>
          <ul>
            <?php
            $removethis = array("scholar", "Scholar");
            print "<li>" . implode(' , </li><li>',$w['overides']) . "</li>";
           ?>
		 	    </ul>
		 	  </div>
		 	 </span>
		 	 <?php
		 }
		 ?>

		</dd>
	<?php endforeach?>
</dl>

