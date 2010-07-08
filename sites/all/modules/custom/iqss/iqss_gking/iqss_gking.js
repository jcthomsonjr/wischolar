  $(document).ready(function(){
    $('.col dt span').hover(function() {
      $(this).after('<div class="bg"></div>');
      $(this).parent('dt').addClass('active');
      $(this).children('.more').fadeIn("fast");
      $(this).parent('dt').next('dd').fadeIn(180);
      }, function() {
        $(this).next('.bg').remove();
        $(this).parent('dt').removeClass('active');
        $(this).children('.more').fadeOut("fast");
        $(this).parent('dt').next('dd').fadeOut(180);
        });
      });