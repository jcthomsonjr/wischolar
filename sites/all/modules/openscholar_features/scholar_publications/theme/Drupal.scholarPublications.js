

/**
 * Generic replacement click handler to open the modal with the destination
 * specified by the href of the link.
 */
var clickAJAXPublication = function() {
  if ($(this).hasClass('ctools-ajaxing')) {
    return false;
  }

  var url = "/publications/abstract";
  var object = $(this);
  $(this).addClass('ctools-ajaxing');
  try {
    url = url.replace('/nojs/', '/ajax/');
    $.ajax({
      type: "POST",
      url: url,
      data: 'path='+$(this).attr('href'),
      global: true,
      success: Drupal.CTools.AJAX.respond,
      error: function() { 
        alert("An error occurred while attempting to process " + url); 
      },
      complete: function() {
        object.removeClass('ctools-ajaxing');
      },
      dataType: 'json'
    });
  }
  catch (err) {
    alert("An error occurred while attempting to process " + url); 
    $(this).removeClass('ctools-ajaxing');
    return false;
  }

  return false;
};

Drupal.behaviors.scholarlayout = function() {
	  //Tell Ctools to take over the click for the abstract	
	$('.'+Drupal.settings.scholarPublications.abstract_id+' a:not(.publication-abstract-processed)')
    .addClass('publication-abstract-processed')
    .click(clickAJAXPublication);
};