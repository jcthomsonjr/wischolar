/* disables submit button while ajax calls are still being processed */

$(document).ready(function() {
  $('#edit-path').ajaxStop(function() {
    $('#edit-submit').attr('disabled', 'false').attr('style', 'color:black')
  });
  
  $('#edit-path').ajaxSend(function() {
    $('#edit-submit').attr('disabled', 'true').attr('style', 'color:gray !important')
  });
});