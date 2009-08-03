<?php
// $Id: page.tpl.php,v 1.2 2008/12/23 15:36:05 falimadh Exp $
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">
  <head>
    <title><?php print $head_title ?></title>
    <?php print $head ?>
    <?php if (isset($googlescholar)) : ?>
    <?php print $googlescholar; ?>
    <?php endif; ?>
    <?php print $styles ?>
    <?php print $scripts ?>
    <!--[if lte IE 7]><?php print iqss_base_get_ie_styles(); ?><![endif]--><!--If Less Than or Equal (lte) to IE 7-->

  </head>
  <body class="<?php print $body_classes; ?>">
  
<!-- Layout -->
	<div id="wrapper">
		<div id="container">
			<div id="header">
				<div id="verytop">
					<?php print $header; ?>
					<?php if (isset($secondary_links)): print theme('links', $secondary_links, array('class' => 'links secondary-links')); endif;?>
				</div>
				
				<?php print '<h1><a href="'. check_url($front_page) .'" title="'. check_plain($site_name) .'"></a></h1>';?>
	
				<div id="nav">
					<?php if (isset($primary_links)) : ?>
						<?php print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
					<?php endif; ?>
				</div> <!-- /#nav -->	
				
		  </div> <!-- /#header -->
	
		  <div id="main">
		  	<div id="main_wrap"> 
				<?php if ($left): ?>
				  <div id="sidebar-left" class="sidebar">
					<?php print $left ?>
				  </div> <!-- /#sidebar-left -->
				<?php endif; ?>
		
				<div id="center">
					  <?php print $breadcrumb; ?>
					  <?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
					  <?php if ($tabs): print '<div id="tabs-wrapper" class="clear-block">'; endif; ?>
					  <?php if ($title): print '<h2'. ($tabs ? ' class="with-tabs"' : '') .'>'. $title .'</h2>'; endif; ?>
					  <?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
					  <?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
					  <?php if ($show_messages && $messages): print $messages; endif; ?>
					  <?php print $help; ?>
					  <?php //print_r(get_defined_vars()); ?>
					  <?php print $content ?>
					</div> <!-- /#center -->
		  
				<?php if ($right): ?>
				  <div id="sidebar-right" class="sidebar">
				  	<?php if ($search_box): print $search_box; endif; ?>
					<?php print $right ?>
				  </div> <!-- /#sidebar-right -->
				<?php endif; ?>
			  	<span class="clear"></span>
			  </div><!--/#main_wrap -->
		  </div> <!-- /#main -->
		</div> <!-- /#container -->
	</div><!-- /#wrapper-->
	<div id="footer">
		<p class="copy">&copy; 1997-<?php echo date("Y") ?> President &amp; Fellows Harvard University. IQSS, 1737 Cambridge Street, Cambridge, MA, 02138 p: (617) 496-2450 f: (617) 496-5149. <a href="<?php print $base_path;?>contact">Contact Us</a></p>
		<?php print $footer_message . $footer ?>
		<?php print $feed_icons ?>
	</div> <!-- /#footer -->
	<!-- /layout -->
  <?php print $closure ?>

  </body>
</html>
