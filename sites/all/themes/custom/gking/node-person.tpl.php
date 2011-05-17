<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes; ?>">
  <div class="node-inner">
    <div class="os-links">
      <?php print $vsite_admin_links; ?>
    </div>
    <?php if (!$page):?>
      <?php if ($node->field_person_website[0]['url']['value']) {
        $person_link = $node->field_person_website[0]['url'];
        } elseif ($node->field_person_email[0]['value']) {
        $person_link = 'mailto:' . $node->field_person_email[0]['value'];
        }
      ?>
      <?php if ($person_link) { ?>
        <h3 class="title">
        <?php print '<a href="' . $person_link .'" title="Contact '. $title . '">' . $title . '</a>';
        }
        else {
        print '<h3 class="title">'. $title;
        }
        if ($node->field_person_title[0]['value']) {
        print '<span class="position">, ' . $node->field_person_title[0]['value'] . '</span>';
        } ?></h3>
    <?php endif ?>

    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>
    <?php if ($submitted): ?>
        <p class="submitted"><?php print $submitted; ?></p>
      <?php endif; ?>
     <?php if ($page): ?>
     <?php if ($terms): ?>
       <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
     <?php endif; ?>
     <?php endif; ?>
     <?php if ($node->taxonomy[1589]): ?>
      <div class="content">
        <?php print $content; ?>
      </div>
    <?php endif; ?>
    <?php if (!$page): ?>
      <?php if ($terms): ?>
      <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
    <?php endif; ?>
    <?php if ($links): ?>
    <div class="links clearfix">
      <?php print $links; ?>
    </div>
    <?php endif;?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->