<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?= $language->language ?>" lang="<?= $language->language ?>" dir="<?= $language->dir ?>">

<head>
  <title><?= $head_title; ?></title>
  <?= $head ?>
  <?= $styles ?>
  <?= $scripts ?>
</head>

<body class="<?= $body_classes ?>">
    <?php if ($cp_toolbar) : ?>
    <div id="top">
  	   <?= $cp_toolbar?>
  	 </div>
  	 <?php endif;?>
  <div id="wrapper">
    <div id="container">
    
      <?= eval( scholar_base_render_layout() ); ?>

    </div> <!-- /container -->
  </div> <!-- /wrapper -->
  <div id="extradiv"></div>
  <?php if ($closure_region): ?>
    <div id="closure-blocks"><?= $closure_region ?></div>
  <?php endif; ?>
  <?php print $closure; ?>
</body>
</html>