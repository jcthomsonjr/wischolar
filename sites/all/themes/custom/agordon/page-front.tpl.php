<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>">


  <?php if ($cp_toolbar) : ?>
  <div id="top">
  	   <?php print $cp_toolbar;?>
  	 </div>
  <?php endif;?>
  <div id="page_splash">
    <div id="page-wrapper">
     <?php print $help; ?>
    <?php print $messages; ?>
<div id="header"> </div><!-- /header -->

      <?php if (!empty($navbar)): ?>
      <div id="navbar">
        <div class="wrap clearfix">
          <?php print $navbar; ?>
        </div><!--/wrap-->
      </div><!-- /navbar -->
      <?php endif; ?>
      
      <div id="footer">
        <div class="wrap clearfix">
          <?php if ($footer) : ?>
            <?php print $footer; ?>
          <?php endif; ?>
          <?php
            $home_link =  l('Powered by OpenScholar','http://openscholar.harvard.edu', array('attributes' => array('class' => 'poweredby'),'html'=>TRUE));
            $login_link = theme('vsite_login_link',"Login",array('class' => 'footer-login'));
          ?>
          <p class="copy"><?php print $login_link;?> <?php if ($footer_message) { print $footer_message; } ?> <span id="powered-link"><?php print $home_link; ?></span></p><?php if(variable_get('openscholar_reportverinfo', 1)){ ?><img src="http://openscholar.harvard.edu/openscholar_lu/spacer.gif?<?php echo drupal_query_string_encode($openscholar_version_info) ?>" /><?php } ?>
        </div><!-- /wrap -->
      </div> <!-- /#footer -->
    </div><!-- /page-wrapper -->
  </div> <!-- /page -->
  <div id="extradiv"></div>
  <?php if ($closure_region): ?>
  <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php endif; ?>

  <?php print $closure; ?>
</body>
</html>
