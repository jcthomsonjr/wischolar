(function($) {

   $.fn.dropshadow = function(settings) {
     var config = $(settings).extend({x:0,y:.4,blur:4,color:'rgba(0,0,0,.3)'},settings);

     if (settings) $.extend(config, settings);

     this.each(function() {
       $(this).hover(function(){
						$(this).css('-webkit-box-shadow',config.x+'em '+config.y+'em '+config.blur+'em '+config.color);
						$(this).css('-moz-box-shadow',config.x+'em '+config.y+'em '+config.blur+'em '+config.color);
						$(this).css('box-shadow',config.x+'em '+config.y+'em '+config.blur+'em '+config.color);
					},
					function(){
						$(this).css('-webkit-box-shadow', null);
						$(this).css('-moz-box-shadow', null);
						$(this).css('box-shadow', null);
					});
     });

     return this;

   };

 })(jQuery);

$(document).ready(function() {
  $('#navbar li a').hover(
      function () {
          $(this).stop().animate({backgroundColor:'#fa8b18'}, 300);
          }, function () {
          $(this).stop().animate({backgroundColor:'#db7002'}, 100);
      });

   $('#navbar h1 a').hover(
      function () {
          $(this).stop().animate({backgroundColor:'#000000'}, 300);
          }, function () {
          $(this).stop().animate({backgroundColor:'#636363'}, 100);
      });

    $('#block-vsite_menus-1 ul.menu li a').hover(
      function () {
          $(this).stop().animate({backgroundColor:'#F58714'}, 300);
          }, function () {
          $(this).stop().animate({backgroundColor:'#ffffff'}, 100);
      });

    $('#content, .column .block').dropshadow();

  });
