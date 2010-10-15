<div id="panel-wrapper">
  <div id="front-panel-1" class="panel">
    <div class="row">
        <div id="publications">
          <?php
          $publications = views_block('view','scholar_publications-block_1');
          print '<h2>' . $publications['subject'] . '</h2>';
          print $publications['content'];
          ?>
        </div>
        <div id="activity">
            <?php
            $activity = views_block('view','vsite_activity-block_1');
            print '<h2>' . $activity['subject'] . '</h2>';
            print $activity['content'];
            ?>
        </div>
        <div id="about-abstract">
          <h2>Harvard Scholars: Create a dynamic feature-full personal web site in seconds. For free!
          (No, there’s no catch.)</h2>

          <div id="big-button"><?php print l('Create your web site!','site/register');?></div>

          <h3>Great features for academics</h3>
          <div class="illustration illust-widget"></div>
          <p>Manage your CV, bio, publications, blogs, announcements, links, image galleries, events, class materials. Automatically have your publications submitted to induces such as RePEc,
          Computer Science Repository, and Google Scholar.</p>

          <h3>Super easy-to-use admin tools</h3>
          <div class="illustration illust-wrench"></div>
          <p>Use a web browser on any networked computer in the workd to create and edit content, move useful widgets in and out of your site; change menus, categorize your work.</p>

          <h3>Beautiful themes</h3>
          <div class="illustration illust-theme"></div>
          <p>Instantly change the look of your site with many elegant themes, or import your own custom theme.</p>
          <p id="learn-more-toggle"><a href="learn-more">Learn More about <span><?php print variable_get('site_name', ''); ?></span></a></p>
        </div><!--/about-abstract -->
      </div><!--/row -->
    </div><!--/panel -->
  <div id="front-panel-2" class="panel">
    <div class="row">
      <p id="activity-toggle"><a href="welcome">Recent Activity</a></p>
    </div><!--/row -->
    <div class="row row-video">
      <?php
      $video = openscholar_front_block('view','video_info');
      print $video['content'];

      ?>

      <div id="more-info">
        <?php
        $mission = openscholar_front_block('view','site_mission');
        print $mission['content'];
        ?>

      </div>
    </div><!--/row -->
    <div class="row row-features">
      <h2>Features</h2>
      <ul id="features">
        <li id="feature-academic-content" class="featureblock">
          <h3>Create anything related to an academic site.</h3>
          <p>CV, bio, publications, blogs, announcements, links, image galleries, class materials. Easy as using a word processor.</p>
        </li>
        <li id="feature-biblio" class="featureblock">
          <h3>Maintain an accurate and  citable bibliography of all your writings.</h3>
          <p>Automatically have your publications submitted to induces such as RePEc, Computer Science Repository, and Google Scholar.</p>
        </li>
        <li id="feature-look-feel" class="featureblock">
          <h3>Control the look and feel of your site.</h3>
          <p>Move useful widgets in and out of your site; change menus, and overall look of your site in seconds.</p>
        </li>
        <li id="feature-collaborate" class="featureblock">
          <h3>Collaborate with your colleagues.</h3>
          <p>Allow commentary on your work by whomever you select. Manage your Twitter feeds; keep track of colleagues, publications and blogs.</p>
        </li>
      </ul>
  </div><!--/row -->
    <div class="row row-openscholar">
        <p class="docs"><strong><?php print variable_get('site_name', ''); ?></strong> includes complete <strong>documentation</strong> <?php print l('Go there now.','help/vsitehelp/OpenScholar-Documentation');?></p>
        <p class="os-link"><strong><?php print variable_get('site_name', ''); ?></strong> is build on <strong>OpenScholar</strong>, an open-source web-creation tool.  <?php print l('Learn more.','http://openscholar.harvard.edu',array('attributes'=>array('html'=>TRUE)));?></p>
  </div><!--/row -->
 </div><!--/panel -->

</div><!--/panel wrapper -->

<script type="text/javascript">
  $(document).ready(function() {
    $('#learn-more-toggle a').attr("href","#").click(function(event){
      $('#panel-wrapper').animate({left:'-1000'},"1500");
    });
    $('#activity-toggle a').attr("href","#").click(function(event){
      $('#panel-wrapper').animate({left:'0'},"1500");
    });

   });
</script>