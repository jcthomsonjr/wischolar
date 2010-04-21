<script type="text/javascript">
  //Horizontal Sliding
  $(document).ready(function(){
    $('.with-overrides').hover(function(){
      $(".layout-exceptions").stop().animate({right:'-20px'},{queue:false,duration:300});
    }, function() {
      $(".layout-exceptions").stop().animate({right:'-101%'},{queue:false,duration:300});
    });
  });
</script>
<div id="scholarlayout-container" class="pad">
  <?php print $vsite_layout_header_main; ?>
  <?php print $vsite_layout_header_left; ?>
  <?php print $vsite_layout_header_right; ?>
  <?php print $vsite_layout_navbar; ?>
  <?php print $vsite_layout_left; ?>
  <?php print $vsite_layout_content; ?>
  <?php print $vsite_layout_right; ?>
  <?php print $vsite_layout_footer; ?>
</div>