<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes; ?>">
  <div class="node-inner">
    <div class="os-links">
      <?php print $vsite_admin_links; ?>
    </div>
    <?php if (!$page): ?>
      <h3 class="title">
        <a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
      </h3>
    <?php endif; ?>
    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>
    <?php if ($page): ?>
      <?php if ($terms): ?>
       <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
    <?php endif; ?>
    <div class="content">
    <?php if ($page && $node->field_scholar_software_logo[0]['fid']): ?>
      <div class="flR">
        <?php print theme_image($node->field_scholar_software_logo[0]['filepath'],$node->title, $node->title);?>
      </div>
    <?php endif; ?>
      <?php print $content; ?>
    </div>
    <?php if (!$page): ?>
     <?php if ($terms): ?>
       <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
    <?php endif; ?>
    <?php if ($links):?>
    <div class="links links-inline">
      <?php print $links;?>
    </div>
    <?php endif ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->
