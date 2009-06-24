<div id="node-<?php print $node->nid; ?>" class="node <?php print $swapbase_node_classes; ?>">
 <?php print $swap_images?>
  <?php print $picture ?>

  <?php if ($page == 0): ?>
    <h3><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h3>
  <?php endif; ?>

  <?php if ($submitted): ?>
    <span class="submitted"><?php print $submitted; ?></span>
  <?php endif; ?>

  <div class="content">
    <?php print $content ?>
  </div>

  <?php if ($links||$taxonomy){ ?>
    <div class="meta">

      <?php if ($links): ?>
        <div class="links">
          <?php print $links; ?>
        </div>
      <?php endif; ?>

      <?php if ($taxonomy): ?>
        <div class="terms">
          <?php print $terms ?>
        </div>
      <?php endif;?>

      <span class="clear"></span>

    </div>
  <?php }?>

</div>
