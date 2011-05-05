(function ($) {
$.fn.vAlign = function() {
	return this.each(function(i){
	var ah = $(this).height();
	var ph = $(this).parents('.wrap').height();
	var mh = Math.ceil((ph-ah) / 2) - 10;
	$(this).css('margin-top', mh);
	});
};
})(jQuery);


$(document).ready(function() {
  $('#block-scholar-1').vAlign();
  if ($('.page-node .node li.vsite-admin')) {
    $('.page-node .node li.vsite-admin').appendTo('h2.title');
    $('li.vsite-admin a.ctools-dropdown-link').html('Actions');
  }
});