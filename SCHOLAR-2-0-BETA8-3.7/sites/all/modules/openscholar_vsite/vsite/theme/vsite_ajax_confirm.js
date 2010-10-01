Drupal.behaviors.vsiteLink = function(context) {
        $('a.vsite-pls-confirm:not(.vsite-link-processed)', context).addClass('vsite-link-processed').click(function(){
                $(this).parent().children('.vsite-confirm-message').toggle();
                return false;
        });

};

