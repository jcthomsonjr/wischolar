Drupal.behaviors.scholar = function (context){
  $('.toggle').click(function(){
	   $(this).toggleClass("expanded")

	   if(!$.browser.msie) {
         $(this).nextAll('.slider').slideToggle("fast");
	   }else{
		 //IE8 Does not work with the slider
	     if ($(this).hasClass('expanded')) {
		   $(this).nextAll('.slider').show();
	     }
	     else {
		     $(this).nextAll('.slider').hide();
	     }
	   }
	   return false;
  });

$('div.links .vsite-admin').hover(function(){
	var parent = $(this).parents('.node');
	parent.addClass('os-links-trail');
  },function(){
  var parent = $(this).parents('.node');
  parent.removeClass('os-links-trail');
  });
}
