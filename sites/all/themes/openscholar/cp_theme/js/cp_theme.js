$(document).ready(function(){
  $("#collapser").toggle(function(event){
    $('body').addClass('toolbar-collapsed');
     }, function() {
    $('body').removeClass('toolbar-collapsed');
    });
});
