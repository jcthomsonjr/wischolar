var pathname = window.location.pathname;
var images = ['01.jpg', '02.jpg', '03.jpg', '04.jpg'];

$(document).ready(function() {
    $('.page-home #content-main').prepend('<div id="front-rotate"></div>');
    $('#front-rotate').css({'background-image': 'url(/sites/all/themes/custom/scholar_jwe/images/rotating/' + images[Math.floor(Math.random() * images.length)] + ')'});
  });

//$('#front-rotate').css({'background-image': 'url(/sites/all/themes/custom/scholar_jwe/images/rotating/' + images[Math.floor(Math.random() * images.length)] + ')'});