<?php
// $Id: node.tpl.php,v 1.4 2008/09/15 08:11:49 johnalbin Exp $

/**
 * @file node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <div class="node-inner">
    <?php print $picture; ?>
    <?php if (!$page): ?>
      <h3 class="title">
        <a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
      </h3>
    <?php endif; ?>
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
      <?php// print $content; ?>
      <?php if ($field_user_profile_photo_rendered) {
        print $field_user_profile_photo_rendered;
        } ?>
      <h3><?php print $vsite_users_first_name[0]['value'] . ' ' . $vsite_users_last_name[0]['value'];?></h3>
      <p><?php print $vsite_users_title[0]['value'];?></p>

    </div>
    <?php print $links; ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->