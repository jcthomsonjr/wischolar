/**
 * Sets up a linkage between the links in a Table of Contents block and the actual contents of a book page
 */
(function($){
	var display, header, content = {}, perma;
	
	Drupal.behaviors.os_book_linkage = function() {
		if (!$('body.node-type-book').length) return;
		var pages = $('.book-page p');
		display = $('#content p').not(pages);
		var blocks = $().not('*');
		perma = $('#book-permalink');
		title = $('#content-main .title');
		
		pages.each(function(index, elem){
			// get the nid of the content
			var nid = parseInt(elem.parentNode.id.replace('book-node-',''));
			
			// save it to the content object
			var title = $(elem).prev().html();
			content[nid] = {title: title, content: elem.innerHTML};
			
			// add nid as attribute of links with same title
			$('.block a:contains("'+title+'")').each(function (index, elem) {
				elem.setAttribute('nid', nid);
				var parents = $(elem).parents('div.block');
				blocks.add(parents);
			});
		});
		
		// attach click handler to blocks
		blocks.click(toc_click);
	}
	
	function toc_click(e) {
		var nid = e.target.getAttribute('nid');
		display.html(content[nid].content);
		title.html(content[nid].title);
		perma.attr('href', e.target.getAttribute('href'));
		e.preventDefault();
	}
})(jQuery);