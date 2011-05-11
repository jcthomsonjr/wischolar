$(document).ready(function() {
    $('<div id="bates-front-menu"><div id="bg"><ul id="map"><li class="publications"><a href="rbates/publications">Vita with Publications</a></li><li class="bio"><a href="rbates/biocv">Bio</a></li><li class="data"><a href="rbates/data">Data</a></li><li class="classes"><a href="rbates/classes">Classes</a></li><li class="contact"><a href="rbates/contact_owner">Contact</a></li></ul></div></div>').appendTo('.front #header');
    $('#map li').hover(function(){
      var thisclass= $(this).attr("class");
      $(this).parent().attr("class","");
      $(this).parent().addClass("map-" +  thisclass);
      },
      function () {
        $(this).parent().removeClass();
      });
});
