Drupal.behaviors.CpNiceButton = function(context){
  $(':submit:not(.cp-nice-button-processed)', context)
  .addClass('cp-nice-button-processed')
  .each(function(){
    var $this = $(this);
    //var f = this.form;
    var link = $('<a class="submit-link ' + $this.attr("id") + '" href="#"><span class="button-inner"><span class="label">' + $this.val() + '</span></span></a>')
               .bind('click',[$this],function(e){
                 e.data[0].click();
                 return false;
               }).bind('mousedown',[$this],function(e){
            	 e.data[0].trigger('mousedown');
                 return true;
               }).bind('mouseup',[$this],function(e){
            	 e.data[0].trigger('mouseup');
                 return true;
               });
    $this.after(link).css({position:'absolute', top:'-2000px'});	  
  });
}
