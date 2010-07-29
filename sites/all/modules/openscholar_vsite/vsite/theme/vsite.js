Drupal.behaviors.scholar = function (context){
  $('.toggle', context).click(function(){
	   $(this).toggleClass("expanded")
       $(this).next('.slider').slideToggle("fast");

       return false;
  });
  
  $('li.vsite-admin div.ctools-dropdown-container').hover(function(){
	var parent = $(this).parents('div.node');
	if(!parent.length) parent = $(this).parents('div.biblio-entry');
	parent.addClass('active');
  },function(){
	var parent = $(this).parents('div.node');
	if(!parent.length) parent = $(this).parents('div.biblio-entry');
	parent.removeClass('active');
  });

  $('.disto-toggle', context).click(function(){
	   $(this).parents('.ctools-dropdown-container').css({width:'auto'}).animate({width:342},250);
     $(this).next('.slider').slideToggle("fast");
       return false;
  });
}
