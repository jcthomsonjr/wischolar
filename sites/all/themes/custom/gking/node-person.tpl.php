<?php
// $Id: node.tpl.php,v 1.4 2008/09/15 08:11:49 johnalbin Exp $

/**
 * @file node.tpl.php
 */
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <div class="node-inner">
    <?php if (!$page):?>
      <?php if ($node->field_person_website[0]['url']['value']) {
        $person_link = $node->field_person_website[0]['url'];
        } elseif ($node->field_person_email[0]['value']) {
        $person_link = 'mailto:' . $node->field_person_email[0]['value'];
        }
      ?>
      <?php if ($person_link) { ?>
      <h3 class="title">
        <a href="<?php print $person_link; ?>" title="Contact <?php print $title ?>"><?php print $title; ?></a><?php } else { ?>
        <h3 class="title"><?php print $title; ?>
      <?php }
        if ($node->field_person_title[0]['value']) { ?><span class="position">, <?php print $node->field_person_title[0]['value'];?></span>
      <?php } ?></h3>
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
    <?php print $links; ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->