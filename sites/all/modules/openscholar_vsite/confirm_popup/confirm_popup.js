/**
 * 
 */

Drupal.behaviors.confirm_popup = function () {
  Drupal.settings.confirm_popup_links = eval(Drupal.settings.confirm_popup_links);
  var links = $("a");
  var path = Drupal.settings.vsiteBasePath+"/";
  $.each(Drupal.settings.confirm_popup_links, function (i, item) {
  	// for every path we check against
  	var frags = item.split("%");
  	var links_t = links;
  	$.each(frags, function (i, item) {
  	  // filter the list of links by the path fragment
  	  links_t = links_t.filter("[href*="+item+"]");
  	});

	links_t.each(function (i, item) {
	  // add in the necessary path bits and classes
      item.href = item.href.replace(path, path+"confirm_popup/nojs/");
      if (item.className.indexOf("ctools-use-modal") == -1) {
        item.className += " ctools-use-modal ctools-modal-confirm-popup-modal";
	  }
	});
  });

  // tell ctools to go. We don\'t know if ctools has already processed or not.
  Drupal.behaviors.ZZCToolsModal();
}