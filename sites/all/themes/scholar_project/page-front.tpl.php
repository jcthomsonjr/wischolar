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
  <div id="wrapper">
    <div id="container">

      <div id="header">
        <div id="header-wrapper">
          <div id="header-left" class="column">
            <h1><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a></h1>
          </div><!-- /header-left -->
          <div id="header-right" class="column">
            <?php print $header_right; ?>
              <ul id="top-front">
                <!--<li>What's New</li>
                <li>Features</li>-->
                <li><?php print l('About', 'help/vsitehelp/Scholar-Web-Sites-Project-Documentation'); ?> </li>
                <li><?php print  ($user->uid > 0) ? l('Log out', 'logout') :   l('Log in', 'user'); ?></li>
                <li id="<?php print $front_button_id ?>"> <?php print $front_button_link ?> </li>           
               </ul>
           </div><!-- /header-right -->
         </div><!-- /header-wrapper -->
      </div> <!-- /header -->

      <div id="content-wrapper">

        <div id="content-main" class="column">
            <?php if ($messages) print $messages; ?>
            <?php if ($content) print $content; ?>

              <?php print $content_top;?>

          </div><!-- /content main -->
      </div> <!-- / content wrapper -->

      <div id="footer">
        <p class="copy">Copyright © President & Fellows of Harvard University. A project of the <?php print l('Institute for Quantitative Social Sciences', 'http://iq.harvard.edu') . '. ' . l('Contact & Feedback', 'contact'); ?> </li></p>
      <?php if ($footer_message){ ?>
        <div id="footer-message"><?php print $footer_message; ?></div>
      <?php }; ?>
      <?php if ($footer){ ?>
        <?php print $footer; ?>
      <?php }; ?>
      </div> <!-- /#footer -->

    </div> <!-- /container -->
  </div> <!-- /wrapper -->
  <?php if ($closure_region){ ?>
    <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php }; ?>
  <?php print $closure; ?>
</body>
</html>