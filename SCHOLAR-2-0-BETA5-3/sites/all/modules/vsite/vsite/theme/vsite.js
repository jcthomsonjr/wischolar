Drupal.behaviors.scholar = function (context){
  $('.toggle', context).click(function(){
	   $(this).toggleClass("expanded")
       $(this).next('.slider').slideToggle("fast");

       return false;
  });
}
