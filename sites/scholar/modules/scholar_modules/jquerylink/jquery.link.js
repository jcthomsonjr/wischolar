$(function()
  {
    $(':submit').each(
       function()
       {
          var $this = $(this);
          var f = this.form;
          var link = $('<a class="submit-link" href="#"><span class="button-inner"><span class="label">' + $this.val() + '</span></span></a>')
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