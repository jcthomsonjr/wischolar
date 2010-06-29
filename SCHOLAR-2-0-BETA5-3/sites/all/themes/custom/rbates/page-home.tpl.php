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
  <script type="text/javascript">
			$(document).ready(function() {
				$('#map li').hover(function(){
					var thisclass= $(this).attr("class");
					$(this).parent().attr("class","");
					$(this).parent().addClass("map-" +  thisclass);
				},
				function () {
        $(this).parent().removeClass();
          }
				);
			});
   </script>
</head>

<body class="<?php print $body_classes; ?>">
    <?php if ($cp_toolbar) : ?>
    <div id="top">
  	   <?php print $cp_toolbar;?>
  	 </div>
  	 <?php endif;?>
  <div id="wrapper">
    <div id="container">

      <?php if ($header_top || $header_main || $header_left || $header_right || $navbar) : ?>

      <div id="header">
        <?php if (!empty($header_top)): ?>
        <div id="header-top">
          <?php print $header_top; ?>
        </div><!-- /header-top -->
        <?php endif; ?>
        <div id="header-wrapper">
          <?php if (!empty($header_main)): ?>
            <div id="header-main" class="column">
              <?php print $header_main; ?>
            </div><!-- /header-main -->
          <?php endif; ?>

          <?php if (!empty($header_left)): ?>
            <div id="header-left" class="column">
              <?php print $header_left; ?>
            </div><!-- /header-left -->
          <?php endif; ?>

          <?php if (!empty($header_right)): ?>
          <div id="header-right" class="column">
            <?php print $header_right; ?>
          </div><!-- /header-right -->
            <?php endif; ?>
        </div><!-- /header wrapper -->
        <?php if (!empty($navbar)): ?>

        <?php endif; ?>
      </div> <!-- /header -->
      <?php endif; ?>

      <div id="bates-front-menu">
        <div id="bg">
					<ul id="map">
						<li class="publications"><a href="publications">Vita with Publications</a></li>
						<li class="bio"><a href="biocv">Bio</a></li>
						<li class="data"><a href="data">Data</a></li>
						<li class="classes"><a href="classes">Classes</a></li>
						<li class="contact"><a href="contact_owner">Contact</a></li>
					</ul>
				</div>
      </div> <!-- / bates-front-menu -->
      <div id="content-wrapper-bottom"></div>
      <div id="footer">
      <?php if ($footer_message): ?>
        <div id="footer-message"><?php print $footer_message; ?></div>
      <?php endif; ?>
      <?php if ($footer) : ?>
        <?php print $footer; ?>
      <?php endif; ?>
      <?php
            global $user, $base_url;
            $home_link =  l('Powered by OpenScholar',$base_url, array('attributes' => array('class' => 'poweredby'),'html'=>TRUE));
            $login_link = (!$user -> uid) ? l("Login", "user", array('attributes' => array('class' => 'footer-login'),'absolute' => TRUE, 'alias' => FALSE)) : "";
          ?>
          <p class="copy">Copyright &copy; <?php echo date('Y');?> President &amp; Fellows of Harvard University. <?php print $login_link;?> <span id="powered-link"><?php print $home_link; ?></span></p>
      </div> <!-- /#footer -->
    </div> <!-- /container -->
  </div> <!-- /wrapper -->
  <div id="extradiv"></div>
  <?php if ($closure_region): ?>
    <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php endif; ?>
  <?php print $closure; ?>
</body>
</html>