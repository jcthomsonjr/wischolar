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
    <?php if ($submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>
    
    <?php
    if (!$page){
      //If teaser unify with views by using biblio entry theme
      print theme( 'scholar_publications_biblio_entry' ,$node, variable_get('biblio_base', 'biblio'), biblio_get_style(), ( variable_get('biblio_inlinemode_in_links',0)? true : false), false);
    }else{ ?>
      <?php if ($page && $terms): ?>
        <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
      <div class="content">
        <?php print $content; ?>
      </div>
      <?php print $links; ?>
    <?php } ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->