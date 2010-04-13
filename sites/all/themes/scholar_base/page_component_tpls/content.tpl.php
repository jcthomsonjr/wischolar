<div id="content">
  <?= $context_links ?>
  <? if(!empty($title)){ ?>
    <h2 class="title<?= ($tabs)?' with-tabs':"" ?>"><?= $title; ?></h2>
  <? } ?>
  <? if (!empty($tabs)){ ?>
    <div class="tabs"><?php print $tabs; ?></div>
  <? } ?>
  <?= $help ?>
  <?= $messages ?>
  <?= $content ?>
</div> <!-- /content -->