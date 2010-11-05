Drupal.behaviors.vsitecontent = function(context){
  $("label.option:contains('Any')").hide();
  Drupal.settings.vbo.url = Drupal.settings.vsite_content.url; //Fix the VBO error when they override the action till they fix this in the next release
	
  // Reset the form action that VBO might destroy.
  $('form[id^=views-bulk-operations-form]').each(function() {
	$(this).attr('action', Drupal.settings.basePath+Drupal.settings.vsite_content.url);
  });

}