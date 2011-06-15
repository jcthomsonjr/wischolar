var pathname = window.location.pathname;
var images = ['01.jpg', '02.jpg', '03.jpg', '04.jpg'];

$(document).ready(function() {
    $('.front #content-main').prepend('<div id="front-rotate"></div>');
    $('#front-rotate').css({'background-image': 'url(sites/all/themes/custom/scholar_jwe/images/rotating/' + images[Math.floor(Math.random() * images.length)] + ')'});
    
    /*
    var offset = document.all['content-main'].offsetWidth * -1;
    offset += parseFloat(document.all['content-main'].currentStyle.paddingLeft);
    offset += parseFloat(document.all['sidebar-first'].currentStyle.paddingLeft);
    offset += parseFloat(document.all['sidebar-first'].currentStyle.paddingRight);
    $('#sidebar-first').css({'margin-left': offset+'px'});
    */
  });

//$('#front-rotate').css({'background-image': 'url(/sites/all/themes/custom/scholar_jwe/images/rotating/' + images[Math.floor(Math.random() * images.length)] + ')'});