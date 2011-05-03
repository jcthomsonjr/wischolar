<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes; ?>">
  <div class="node-inner">
    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>
    <?php if ($submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>
    <?php
    if (!$page){ ?>
    <?php //If teaser unify with views by using biblio entry theme
      print theme( 'scholar_publications_biblio_entry' ,$node, variable_get('biblio_base', 'biblio'), biblio_get_style(), ( variable_get('biblio_inlinemode_in_links',0)? true : false), false);
    } elseif ($page){ ?>
      <?php if ($terms): ?>
        <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
      <?php if ($links):?>
      <div class="os-links links links-inline">
      <?php print $links;?>
    </div>
    <?php endif ?>
      <div class="content">
        <?php print $content; ?>
      </div>
    <?php } ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->