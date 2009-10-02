Drupal.behaviors.scholar = function (context){
        $('.toggle', context).click(function(){
                $(this).next('.slider').toggle(400);
                return false;
        });
}
