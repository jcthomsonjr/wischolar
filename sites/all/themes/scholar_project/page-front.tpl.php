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
        <div id="header-left" class="column">
          <h1><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a></h1>
        </div><!-- /header-left -->        
        <div id="header-right" class="column">
          <?php print $header_right; ?>
            <ul id="top-front">
              <li>What's New</li>
              <li>Features</li>
              <li>Tutorials</li>
              <li>Log in</li>
              <li id="get-form">Get your site now!</li>
             </ul>
         </div><!-- /header-right -->
      </div> <!-- /header -->
      
      <div id="content-wrapper">
      
        <div id="content-main" class="column">

            <div id="content-row-1">
              <?php print $row1; ?>
              <div id="tutorial-link">See a video tutorial</div>
              <div class="content">
                <h2>Create a dynamic feature-full web site in seconds. For free!</h2>
                <h3>(No, there’s no catch.)</h3>
              </div>
            </div><!-- /content-row 1-->

            <div id="content-row-2">
              <?php print $row2; ?>
              <div id="feature-academic-content" class="featureblock">
                <h3>Create anything related to an academic site.</h3>
                <p>CV, bio, publications, blogs, announcements, links, image galleries, class materials. Easy as using a word processor.</p>
              </div>
              <div id="feature-biblio" class="featureblock">
                <h3>Maintain an accurate and  citable bibliography of all your writings.</h3>
                <p>Automatically have your publications submitted to induces such as RePEc, Computer Science Reposity, and Google Scholar.
                </p>
              </div>
              <div id="feature-look-feel" class="featureblock">
                <h3>Control the look and feel of your site.</h3>
                <p>Move useful widgets in and out of your site; change menus, and overall look of your site in seconds.</p>
              </div>
              <div id="feature-collaborate" class="featureblock">
                <h3>Collaborate with your colleagues.</h3>
                <p>Allow commentary on your work by whomever you select. Manage your Twtter feeds; keep track of colleagues’ publications and blogs.</p>
              </div>
            </div><!--/content-row 2-->


            <div id="content-row-3">
              <?php print $row3; ?>
              <h3>New Sites</h3>
              <div id="search-person"></div>
              <div id="new-sites">
                <div class="new-site-block">
                  <div class="photo">
                    <a href="site01"><img src="<?php print $base_url . $directory;?>/images/scholar-photo1.jpg" /></a>
                   </div>
                 <h4>Susan J. Pharr</h4>
                 <h5>Edwin O. Reischauer Professor of Japanese Politics</h5>
                </div>
                <div class="new-site-block">
                  <div class="photo">
                    <a href="site02"><img src="<?php print $base_url . $directory;?>/images/scholar-photo2.jpg" /></a>
                   </div>
                 <h4>Susan J. Pharr</h4>
                 <h5>Edwin O. Reischauer Professor of Japanese Politics</h5>
                </div>
                <div class="new-site-block">
                  <div class="photo">
                    <a href="site03"><img src="<?php print $base_url . $directory;?>/images/scholar-photo3.jpg" /></a>
                   </div>
                 <h4>Susan J. Pharr</h4>
                 <h5>Edwin O. Reischauer Professor of Japanese Politics</h5>
                </div>
                <div class="new-site-block">
                  <div class="photo">
                    <a href="site04"><img src="<?php print $base_url . $directory;?>/images/scholar-photo4.jpg" /></a>
                   </div>
                 <h4>Susan J. Pharr</h4>
                 <h5>Edwin O. Reischauer Professor of Japanese Politics</h5>
                </div>
                <div class="new-site-block">
                  <div class="photo">
                    <a href="site05"><img src="<?php print $base_url . $directory;?>/images/scholar-photo5.jpg" /></a>
                   </div>
                 <h4>Susan J. Pharr</h4>
                 <h5>Edwin O. Reischauer Professor of Japanese Politics</h5>
                </div>
                <div class="new-site-block">
                  <div class="photo">
                    <a href="site06"><img src="<?php print $base_url . $directory;?>/images/scholar-photo6.jpg" /></a>
                   </div>
                 <h4>Susan J. Pharr</h4>
                 <h5>Edwin O. Reischauer Professor of Japanese Politics</h5>
                </div>
               </div>
            </div><!--/content-row 3-->

          </div><!-- /content main --> 
      </div> <!-- / content wrapper -->
      
      <div id="footer">
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