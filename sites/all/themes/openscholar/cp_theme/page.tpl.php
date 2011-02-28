<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
    <title><?php print $head_title ?></title>
  </head>
  <body <?php print drupal_attributes($attr) ?>>
  <?php //print $skipnav ?>
  <div id="wrapper">
    <!--
    <?php if ($cp_toolbar):?>
    <div id="cp-toolbar">
      <a id="collapser" href="#">Collapse</a>
      <?php print $cp_toolbar;?>
    </div>
    <?php endif;?>
    -->
    <div id="container">
      <div id='branding' class='clear-block'>
        <div class='breadcrumb clear-block'><?php print $breadcrumb ?></div>
        <?php if ($user_links) print theme('links', $user_links) ?>
      </div>
      <?php
        $menu_item = menu_get_item();
      ?>
      <div id='page-title' class='clear-block'>
        <?php if ($help_toggler) print $help_toggler ?>
        <h1 class='page-title'><span class='icon'></span><?php if ($title && ($node || $menu_item['page_callback'] == 'node_add')) print $title ?></h1>
        <?php if ($tabs): ?><?php print $tabs ?><?php endif; ?>
      </div>

      <div id='page'>
        <?php if ($tabs2): ?><div class='secondary-tabs clear-block'><?php print $tabs2 ?></div><?php endif; ?>
        <?php if ($help) print $help ?>
        <div class='page-content clear-block'>
          <?php //if ($show_messages && $messages): ?>
          <?php if ($messages): ?>
            <div id='console' class='clear-block'><?php print $messages; ?></div>
          <?php endif; ?>

          <div id='content'>
            <?php if (!empty($content)): ?>
              <div class='content-wrapper clear-block'><?php print $content ?></div>
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
    <div id='footer' class='clear-block'>
      <?php if ($feed_icons): ?>
        <div class='feed-icons clear-block'>
          <label><?php print t('Feeds') ?></label>
          <?php print $feed_icons ?>
        </div>
      <?php endif; ?>
      <?php if ($footer_message): ?><div class='footer-message'><?php print $footer_message ?></div><?php endif; ?>
    </div>
  </div>
  <?php print $closure ?>
  </body>
</html>
