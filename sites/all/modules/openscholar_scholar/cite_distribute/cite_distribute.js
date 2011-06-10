// The following line will prevent a JavaScript error if this file is included and vertical tabs are disabled.
Drupal.verticalTabs = Drupal.verticalTabs || {};

Drupal.verticalTabs.cite_distribute_selections = function() {
  var vals = [];
  
  /* Get checked options, add their label text to array */
  $('fieldset.vertical-tabs-cite_distribute_selections input:checked')
    .parent()
    .each( function(){vals.push( $(this).text() )} )
  
  if (vals.join(', ') == '') {
    return Drupal.t('None');
  }
  return vals.join(', ');
}