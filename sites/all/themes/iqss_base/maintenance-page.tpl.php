<?php
// $Id: maintenance-page.tpl.php,v 1.2 2008/12/23 15:36:05 falimadh Exp $
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">
  <head>
    <title><?php print $head_title ?></title>
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
    <!--[if lte IE 7]><?php print phptemplate_get_ie_styles(); ?><![endif]--><!--If Less Than or Equal (lte) to IE 7-->
  </head>
    <body class="<?php print $body_classes; ?>">

<!-- Layout -->
    <div id="wrapper">
      <div id="header">
        <?php print $header; ?>
        <?php print '<h1><a href="'. check_url($front_page) .'" title="'. $site_name .'">';
          if ($logo) {
            print '<img src="'. check_url($logo) .'" alt="'. $site_name .'" id="logo" />';
          }
          if ($site_name) {
            print check_plain($site_name);
          }
          if ($site_slogan) {
            print '<span id="slogan">'. $site_slogan .'</span>';
          }
          print '</a></h1>';
		?>    
        <div class="clear"></div>
      </div> <!-- /#header -->

      <div id="nav">
        <?php if (isset($primary_links)) : ?>
          <?php print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
        <?php endif; ?>
        <?php if (isset($secondary_links)) : ?>
          <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')) ?>
        <?php endif; ?>
      </div> <!-- /#nav -->

      <div id="container">

        <?php if ($left): ?>
          <div id="sidebar-left" class="sidebar">
            <?php print $left ?>
          </div> <!-- /#sidebar-left -->
        <?php endif; ?>

        <div id="center">
          <?php if ($title): print '<h2'. ($tabs ? ' class="with-tabs"' : '') .'>'. $title .'</h2>'; endif; ?>
          <?php print $help; ?>
          <?php print $messages; ?>
          <?php print $content ?>
        </div> <!-- /#center -->
  
        <?php if ($right): ?>
          <div id="sidebar-right" class="sidebar">
            <?php print $right ?>
          </div> <!-- /#sidebar-right -->
        <?php endif; ?>

        <div id="footer" class="clear">
          <?php print $footer_message . $footer ?>
          <?php print $feed_icons ?>
        </div> <!-- /#footer -->

      </div> <!-- /#container -->
      <span class="clear"></span>
    </div> <!-- /#wrapper -->
<!-- /layout -->

  <?php print $closure ?>

  </body>
</html>
