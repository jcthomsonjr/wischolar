/*
 * jQuery Rawr Sliding Container (RSC) v1.0 
 * Website: http://hungred.com
 * Demo Site: http://hungred.com/wp-content/demo/RSC/demo-RSC.html
 * Description: A simple sliding container that can be useful for you.
 * Contact: clay@hungred.com
 * version 1.0
 * 
 * TERMS OF USE -  Rawr Sliding Container (RSC)
 * Open source under the MIT License. 
 * Copyright (c) 2009 Clay Lua Czee Yong
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *  
 *
*/
(function($){
 $.fn.RSC= function(options) {

  var defaults = {
	prevImageID: "#prev",
	nextImageID: "#next",
	noOfContainer: 4,
	containerW: 50,
	duration: 1000
  };
  var op = $.extend(defaults, options);
  
  var i = 0;
  return this.each(function() {	
		$(this).click(function()
		{
			this.id==op.prevImageID.replace("#","")?$(function(){i++;i>0?i=(0-(op.noOfContainer-1)):"";}):this.id==op.nextImageID.replace("#","")?$(function(){i--;i<(0-(op.noOfContainer-1))?i=0:"";}):"";
			$("ul.theme-picker").animate({marginLeft: i*op.containerW+"px"},op.duration);
		});
  });
 };
 
 $.fn.RSC_Jump= function(index,options) {

	 var defaults = {
		containerW: 50,
		duration: 1000
	  };
	  var op = $.extend(defaults, options);

	  return $(this).click(function(){
				$("ul.theme-picker").animate({marginLeft: index*op.containerW*-1+"px"},op.duration);
			 });
	  
	};
})(jQuery);
