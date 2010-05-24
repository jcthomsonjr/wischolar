<?php
// $Id: node.tpl.php,v 1.4 2008/09/15 08:11:49 johnalbin Exp $

/**
 * @file node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <div class="node-inner">
    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>
    <?php if ($submitted or $terms): ?>
      <div class="meta">
        <?php if ($submitted): ?>
          <div class="submitted">
            <?php print $submitted; ?>
          </div>
    <?php if ($submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
     <?php endif; ?>
     <?php if ($page): ?>
     <?php if ($terms): ?>
       <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
     <?php endif; ?>
     <?php endif; ?>
    <div class="content">
      <?php print $content; ?>
    </div>
    <?php if (!$page): ?>
      <?php if ($terms): ?>
      <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
    <?php endif; ?>
    <?php print $links; ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->