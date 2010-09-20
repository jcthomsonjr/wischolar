$(document).ready(function() {
  $(window).resize(function() {
  var w = $(window).width();
  if (w < 1031) {
   $('#content-wrapper').addClass('no-bg');
    $('#footer').addClass('no-bg');
    } else {
   $('#content-wrapper').removeClass('no-bg');
   $('#footer').removeClass('no-bg');
   }
  });
});