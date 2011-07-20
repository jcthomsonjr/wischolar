/* detects an illegal slash at the beginning of url path aliases */

$(document).ready(function() {
  //remove front slash, show message
  $('#edit-path').blur(function() {
    var path = $('#edit-path').attr('value');
    if (path.indexOf('/') == 0) {
      path = path.substr(1);
      $('#edit-path').attr('value', path).change(); //.change() updates vtab preview
      $('#edit-path + div.description').after(
          '<div class="description" id="path-slash-warning">URL Path alias cannot begin with a slash.</div>'
      );
    }
  });
  
  //remove message, if displayed
  $('#edit-path').focus(function() {
    $('#path-slash-warning').remove();
  });
});