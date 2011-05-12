$.fn.vAlign = function(offset) {
	return this.each(function(i){
	var ah = $(this).height();
	var ph = $(this).parents('.wrap').height();
	var mh = Math.ceil((ph-ah) / 2) - offset;
	$(this).css('margin-top', mh);
	});
};

$(document).ready(function() {
  $('#header #block-scholar-1').vAlign(10);
  $('#header #block-scholar_project-1').vAlign(10);
  $('#header #scholar-shield').vAlign(20);
});