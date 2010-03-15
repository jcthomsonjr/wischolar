<?php
$file_path = $node -> field_person_photo[0]['filepath'];
if($file_path){
	$logo_teaser = theme('imagecache','square_80_80', $file_path);
	$logo_teaser = l($logo_teaser, 'node/'. $node -> nid, array('absolute' => FALSE, 'html' => TRUE));
	$logo_page = theme('imagecache','vsite_design_landscape_logo', $file_path);
	$person_logo = $page ? $logo_page : $logo_teaser;
}
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <div class="node-inner">
      <?= (($person_logo)?$person_logo:"") ?>
    <?php print $picture; ?>
    <?php if (!$page): ?>
      <h3 class="title">
        <a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
      </h3>
    <?php endif; ?>
    <?php if ($page): ?>
      <?php drupal_set_title(check_plain(''));?>
      <h2 class="title">
       <?php print $title; ?>
      </h2>
    <?php endif; ?>
    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>
    <?php if ($submitted or $terms): ?>
      <div class="meta">
        <?php if ($terms): ?>
          <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <div class="content">
      <?php print $content; ?>
    </div>
    <?php print $links; ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->
