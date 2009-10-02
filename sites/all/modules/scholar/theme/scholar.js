Drupal.behaviors.scholar = function (context){
        $('.toggle', context).click(function(){
                $(this).next('.slider').slideToggle(400);
                return false;
        });
}
