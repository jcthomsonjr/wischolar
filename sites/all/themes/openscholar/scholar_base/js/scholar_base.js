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
  $('#header #block-scholar-1').vAlign();
  $('#header #block-scholar_project-1').vAlign();
  $('#header #scholar-shield').vAlign();
});