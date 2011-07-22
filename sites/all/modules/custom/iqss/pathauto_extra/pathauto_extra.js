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
  
  //add listener to URL path settings.  fetch new path via ajax
  $('a.vertical-tabs-list-path').click(function(){
    var href = href = 'http://' + document.location.host + '/pathauto_extra/alias_js';
    var data = Drupal.settings.pathauto_extra;
    data.title = $.trim($('#edit-title').attr('value'));
    
    if (  data.title.length > 0 && $('#edit-pathauto-perform-alias').attr('checked')  ) {
      $.getJSON(href, data, function(json) {
        if (json.status) {
          $('#edit-path').attr('value', json.data);
        }
      });
    }
  });
});