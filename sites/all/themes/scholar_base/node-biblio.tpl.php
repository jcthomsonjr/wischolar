<?php
// $Id: node.tpl.php,v 1.4 2008/09/15 08:11:49 johnalbin Exp $

/**
 * @file node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>
  <?php if ($submitted or $terms): ?>
    <div class="meta">
      <?php if ($submitted): ?>
        <div class="submitted">
          <?php print $submitted; ?>
        </div>
      <?php endif; ?>
      <?php if ($terms): ?>
        <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <div class="content">
    <?php if (!$page && $field_biblio_image): ?>
    <div class="bookcover">
      <?php print $field_biblio_image_rendered;?>
    </div>
  <?php endif;?>
    <?php print $content; ?>
    <?php if ($page && $field_biblio_image): ?>
    <div class="bookcover">
      <?php print $field_biblio_image_rendered;?>
    </div>
  <?php endif;?>
  </div>
  <?php print $links; ?>
</div> <!-- /node -->