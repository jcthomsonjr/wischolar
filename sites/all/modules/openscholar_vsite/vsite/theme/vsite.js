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

  $('.os-links .vsite-admin').hover(function(){
	var parent = $(this).parents('.node');
	parent.addClass('os-links-trail');
  },function(){
  var parent = $(this).parents('.node');
  parent.removeClass('os-links-trail');
  });
}

Drupal.behaviors.vsiteAutocloseStatus = function(context) {

  // Growl-style system messages
  $('#messages > div.messages:not(.processed)')
    .addClass('processed')
    .each(function() {
      // If a message meets these criteria, we don't autoclose
      // - contains a link
      // - is an error or warning
      // - contains a lenghthy amount of text
      if ($('a', this).size() || $(this).is('.error') || $(this).is('.warning') || $(this).text().length > 100) {
        $(this).prepend("<div class='close-this'>X</span>");
        $('div.close-this', this).click(function() {
          $(this).parent().slideUp('fast');
        });
      }
      else {
        // This essentially adds a 3 second pause before hiding the message.
        $(this).animate({opacity:1}, 4000, 'linear', function() {
          $(this).slideUp('fast');
        });
      }
   });
  
};