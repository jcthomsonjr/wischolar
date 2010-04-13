<div id="footer">
  <?php if ($footer_message): ?>
    <div id="footer-message"><?php print $footer_message; ?></div>
  <?php endif; ?>
  <?php if ($footer) : ?>
    <?php print $footer; ?>
  <?php endif; ?>
  <?php
        global $user, $base_url;
        purl_disable(TRUE);
        $home_link =  l('The Scholars\' Web Sites Project, IQSS, Harvard University',$base_url);
        $login_link = (!$user -> uid) ? l("Login", "user", array('attributes' => array('class' => 'footer-login'),'absolute' => TRUE)) : "";
  ?>
  <p class="copy"><?php print $home_link; ?>. Copyright &copy; <?php echo date('Y');?> President &amp; Fellows of Harvard University. <?php print $login_link;?></p>
</div> <!-- /#footer -->