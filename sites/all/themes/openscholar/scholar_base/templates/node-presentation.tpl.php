<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <div class="node-inner">

    <?php if (!$page): ?>
      <?php if ($node->field_presentation_date[0]['value'] || $terms) : ?>
      <div class="presentation-meta">
        <?php if ($node->field_presentation_date[0]['value']) : ?>
        <div class="dates">
         <?php print $node->field_presentation_date[0]['view'];?>
        </div>
        <?php endif; ?>
        <?php if ($terms): ?>
        <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
        <?php endif; ?>
       <?php endif; ?>
       </div>

      <div class="presentation-content">
      <h3 class="title">
        <a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a></h3>
      <?php endif; ?>

    <?php if ($page): ?>

    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>

     <?php if ($terms): ?>
       <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
     <?php endif; ?>
    <div class="content">
    <?php endif; ?>


      <?php print $content; ?>
    <?php if ($page): ?>
    </div>
    <?php endif;?>
    <?php print $links; ?>
    <?php if (!$page): ?>
    </div>
    <?php endif;?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->