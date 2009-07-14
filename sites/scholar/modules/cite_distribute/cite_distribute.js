	//$Id: cite_distribute.js,v 1.1.1.1 2008/11/21 20:42:34 jweiner Exp $

if (Drupal.jsEnabled) {
  $(document).ready(function(){
    $('a.widget-link').click(function(){   	
      var updateSub = function (data) {
        var result = Drupal.parseJson(data);
        
        //these are the widget display and widget saved classes
        var wd = result['widget_display'];
        var ws = result['widget_saved'];

        //not using these vars yet
        var allmodules = result['allmodules'];
        var nonmodules = result['nonmodules'];
         
        //first hide the widget that has just been clicked on     
        $(wd).hide();  
         
        // show the text that the widget has been saved        
        $(ws).css("margin-left", "100px").css("background-color", "#f0f0f0").css("color", "#888")
        .css("padding", "5px").css("-moz-border-radius", "3px")
        .show('slow').html(result['saved']);
        }
      $.get(this.href, null, updateSub);
      
      return false;
    });
  });
}

