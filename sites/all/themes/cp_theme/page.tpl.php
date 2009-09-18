<?php
// $Id: page.tpl.php,v 1.10.2.4 2009/02/13 17:30:22 swortis Exp $
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>">
  <div id="container">
  	 <div id="top">
  	   <?php print $cp_toolbar;?>
  	 </div>
     <div id="main-content">
     <?php if ($left) : ?>
      <div id="cp-sidemenu">
        <div class="frame">
          <div class="innerframe">
          <?php print $left;?>
          </div>
        </div>
	  </div><!-- /cp-sidemenu -->
	 <?php endif;?>
			<div id="cp-content">
			  <div class="frame">
          <div class="innerframe">
           <?php if ($context_links) print $context_links;?>
           <?php //main tabs ($tabs) comes in the block on the left ?>
            <?php if (!empty($tabs2)){ ?>
            <?php print 'not empty';?>
            <div class="tabs"><?php print $tabs2; ?></div>
            <?php }; ?>
            <?php print $help; ?>
            <?php print $messages; ?>

            <?php print $content; ?>
            <?php if (!empty($feed_icons)){ ?>
            <div class="feed-icons"><?php print $feed_icons; ?></div>
            <?php }; ?>
			    </div>
        </div>
			</div> <!-- /cp-content -->
			<?php if ($right) : ?>
      <div id="sidebar-right">
        <div class="frame">
          <div class="innerframe">
          <?php print $right;?>
          </div>
        </div>
			</div><!-- /sidebar-right -->
      <?php endif; ?>
		</div> <!-- / main-content -->
     <div id="footer">
        <h3>The Scholars' Web Sites Project <span>IQSS, Harvard University</span></h3>
        <ul>
          <li>&copy; 2008-<?php echo date(Y);?> President &amp; Fellows Harvard University</li>
          <li><a href="/docs">Documentation</a></li>
          <li><a href="/contact">Feedback</a></li>
          <li><a href="/legal">Legal</a></li>
          <li class="last">Version 2.13</li>
        </ul>
        <?php if ($footer_message){ ?>
          	<div id="footer-message"><?php print $footer_message; ?></div>
        <?php }; ?>
        <?php if ($footer){ ?>
        	<?php print $footer; ?>
        <?php }; ?>
      </div> <!-- /#footer -->
	</div> <!-- /container -->
  <?php if ($closure_region){ ?>
    <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php }; ?>

  <?php print $closure; ?>
</body>
</html>