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
      <?php if ($header_top || $header_main || $header_left || $header_right || $navbar) { ?>

      <div id="header">
        <?php if (!empty($header_top)){ ?>
        <div id="header-top">
          <?php print $header_top; ?>
        </div><!-- /header-top -->
        <?php }; ?>
        <div id="header-wrapper">
          <?php if (!empty($header_main)){ ?>
            <div id="header-main" class="column">
              <?php print $header_main; ?>
            </div><!-- /header-main -->
          <?php }; ?>
                    
          <?php if (!empty($header_left)){ ?>
            <div id="header-left" class="column">
              <?php print $header_left; ?>
            </div><!-- /header-left -->
          <?php }; ?>
                    
          <?php if (!empty($header_right)){ ?>
          <div id="header-right" class="column">
             <?php print $header_right; ?>
          </div><!-- /header-right -->
            <?php }; ?>
        </div><!-- /header wrapper -->        
        <?php if (!empty($navbar)){ ?>
        <div id="navbar">
          <?php print $navbar; ?>
        </div><!-- /navbar -->
        <?php }; ?>        
      </div> <!-- /header -->
      <?php }; ?>  
      
      <div id="content-wrapper">
      
        <div id="content-main" class="column">
          <?php if (!empty($content_top) || $context_links){ ?>
            <div id="content-top">
              <?php print $context_links;?>
              <?php print $content_top; ?>
            </div><!-- /content-top -->
          <?php }; ?>
          
          <div id="content">
          <?php if (!empty($title)){ ?>
            <h2 class="title"><?php print $title; ?></h2>
           <?php }; ?>
           <?php if (!empty($tabs)){ ?>
            <div class="tabs"><?php print $tabs; ?></div>
            <?php }; ?>
            <?php print $help; ?>
            <?php print $messages; ?>
            <?php print $content; ?>
          </div> <!-- /content -->
        
          <?php if (!empty($content_bottom)){ ?>
            <div id="content-bottom">
              <?php print $content_bottom; ?>
            </div><!--/content-bottom-->
          <?php }; ?>
          </div><!-- /content main -->
            
          
            <?php if (!empty($left)){ ?>
        <div id="sidebar-left" class="column">
          <?php print $left; ?>
        </div> <!-- /sidebar-left -->
        <?php }; ?>
    
          <?php if (!empty($right)){ ?>
        <div id="sidebar-right" class="column">
          <?php print $right; ?>
        </div> <!-- /sidebar-right -->
        <?php }; ?>
      </div> <!-- / content wrapper -->
      <div id="content-wrapper-bottom"></div>
      <?php if ($footer || $footer_message) { ?>    
      <div id="footer">
      <?php if ($footer_message){ ?>
        <div id="footer-message"><?php print $footer_message; ?></div>
      <?php }; ?>
      <?php if ($footer){ ?>
        <?php print $footer; ?>
      <?php }; ?>
      </div> <!-- /#footer -->
      <?php }; ?>
    </div> <!-- /container -->
  </div> <!-- /wrapper -->
  <div id="extradiv"></div>
  <?php if ($closure_region){ ?>
    <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php }; ?>
  <?php print $closure; ?>
</body>
</html>