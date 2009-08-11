var cpSlidingContainer = Class.create({
	settings :{
			prevImageID: "#prev",
			nextImageID: "#next",
			noOfContainer: 4,
			containerW: 50,
			duration: 1000,
			mainListClass: '',
			listItemClass: '',
			navClass: ''
	},
	currentIndex: 0,
    init: function(options){
	  for ( var key in options ){
		this.settings[key] = options[key];
	  } 
    },
    sliding_container: function(element){
      var settings = this.settings;
      var i = this.currentIndex;
      return $(element).click(function(){
    	this.id==settings['prevImageID'].replace("#","")?$(function(){i++;i>0?i=(0-(settings['noOfContainer']-1)):"";}):this.id==settings['nextImageID'].replace("#","")?$(function(){i--;i<(0-(settings['noOfContainer']-1))?i=0:"";}):"";
    	$("ul."+settings['mainListClass']).animate({marginLeft: i* settings['containerW'] +"px"},settings['duration']);
    	$("."+settings['navClass']+" li" ).removeClass('active');
		$("."+settings['navClass']+" li:eq("+(i*-1)+")" ).addClass('active');
    	$("."+settings['listItemClass']).removeClass('active');
    	$("."+settings['listItemClass']+":eq("+(i*-1)+")").addClass('active');
      });
    },
    sliding_container_link: function(element,index){
    	var settings = this.settings;
    	var i = this.currentIndex;
    	return $(element).click(function(){
			$("ul."+settings['mainListClass']).animate({marginLeft: index * settings['containerW'] *-1+"px"},settings['duration']);

			$("."+settings['navClass']+" li" ).removeClass('active');
			$("."+settings['navClass']+" li:eq("+index+")" ).addClass('active');
			$("."+settings['listItemClass']).removeClass('active');
			$("."+settings['listItemClass']+":eq("+index+")").addClass('active');
			i = -1*index;
		 });
    }
});
