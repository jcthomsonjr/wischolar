<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>">
  <div id="wrapper">
    <div id="wrapper-inner">
      <div id="reasons_header" class="header">
        <div class="contain">
            <h1><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">Scholars at Harvard</a></h1>
            <?php print l('Get Your Site Now','site/register',array('attributes'=>array('class' =>'big-button'))); ?>
          </div>
        </div>
      <div id="container">
      <div id="content-wrapper" class="clear-block">
        <div id="content-wrapper-inner">
          <div id="content-main" class="column">
            <?php if (!empty($content_top)): ?>
              <div id="content-top">
                <?php print $content_top; ?>
              </div><!-- /content-top -->
            <?php endif; ?>
            <div id="content" class="clear-block">
            <?php print $context_links;?>
            <?php if (!empty($title)): ?>
              <h2 class="title<?php if ($tabs) : print ' with-tabs'; endif;?>"><?php print $title; ?></h2>
             <?php endif; ?>
             <?php if (!empty($tabs)): ?>
              <div class="tabs"><?php print $tabs; ?></div>
              <?php endif; ?>
              <?php print $help; ?>
              <?php print $messages; ?>
              <?php print $content; ?>
            </div> <!-- /content -->
            <?php if (!empty($content_bottom)): ?>
              <div id="content-bottom">
                <?php print $content_bottom; ?>
              </div><!--/content-bottom-->
            <?php endif; ?>
            </div><!-- /content main -->
          <?php if (!empty($left)): ?>
          <div id="sidebar-left" class="column sidebar">
            <?php print $left; ?>
          </div> <!-- /sidebar-left -->
          <?php endif; ?>
          <?php if (!empty($right)): ?>
          <div id="sidebar-right" class="column sidebar">
            <?php print $right; ?>
          </div> <!-- /sidebar-right -->
          <?php endif; ?>
        </div> <!-- / content wrapper inner -->
      </div> <!-- / content wrapper -->
      <div class="footer">
    <?php if ($footer) : ?>
      <?php print $footer; ?>
    <?php endif; ?>
    <?php
      $home_link =  l('Powered by OpenScholar','http://openscholar.harvard.edu', array('attributes' => array('class' => 'poweredby'),'html'=>TRUE));
      $login_link = theme('vsite_login_link',"Login",array('class' => 'footer-login'));
    ?>
    <p class="copy"><?php print $login_link;?> <?php if ($footer_message) { print $footer_message; } ?> <span id="powered-link"><?php print $home_link; ?></span></p>
  </div> <!-- /footer -->
    </div> <!-- /container -->
    </div><!-- /wrapper-inner -->
  </div> <!-- /wrapper -->
  <?php if ($closure_region): ?>
    <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php endif; ?>
  <?php print $closure; ?>
</body>
</html>