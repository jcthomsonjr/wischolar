$(function()
  {
    $(':submit').each(
       function()
       {
          var $this = $(this);
          var f = this.form;
          var link = $('<a href="#"><span>' + $this.val() + '</span></a>')
             .bind(
                'click',
                function()
                {
                   $(f).trigger('submit');
                   return false;
                }
             )
          $this.after(link).css({position:'absolute', top:'-2000px'});
       }
    )
});