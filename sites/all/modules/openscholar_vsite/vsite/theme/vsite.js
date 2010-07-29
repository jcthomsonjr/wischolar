Drupal.behaviors.scholar = function (context){
  $('.toggle', context).click(function(){
	   $(this).toggleClass("expanded")
       $(this).next('.slider').slideToggle("fast");

       return false;
  });

  $('.disto-toggle', context).click(function(){
	   $(this).parents('.ctools-dropdown-container').css({width:'auto'}).animate({width:342},250);
     $(this).next('.slider').slideToggle("fast");
       return false;
  });
}
