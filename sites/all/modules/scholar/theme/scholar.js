Drupal.behaviors.scholar = function (context){
  $('.toggle', context).click(function(){
       $(this).next('.slider').slideToggle("fast").toggleClass("expanded");
;
       return false;
  });
}
