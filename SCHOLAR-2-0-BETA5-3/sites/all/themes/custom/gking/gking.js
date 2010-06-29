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

  });
