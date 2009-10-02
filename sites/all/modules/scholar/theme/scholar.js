Drupal.behaviors.scholar = function (context){
        $('.toggle', context).click(function(){
                $(this).next('.slider').slideToggle("fast");
                return false;
        });
}
