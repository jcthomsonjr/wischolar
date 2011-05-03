<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>

<body class="<?php print $body_classes; ?>">

<div id="startpage" class="page">
  <div id="startpage-header" class="wrap header">
  <h1>Scholars at Harvard</h1>
  <h2>Personal Websites Exclusively for Harvard Scholars</h2>
  <ul id="header-info" class="inline">
    <?php
    $home_link =  l('Powered by OpenScholar','http://openscholar.harvard.edu', array('attributes' => array('class' => 'poweredby'),'html'=>TRUE));
    $login_link = theme('vsite_login_link',"Login",array('class' => 'footer-login'));
   ?>
    <li><a href="http://openscholar.harvard.edu">Not a Harvard Scholar? Find out how to create a similar site at your institution.</a></li>
  </ul>
  <?php print $search_box; ?>
</div><!--/startpage-header -->
  <div id="start-content" class="wrap dark">
  <div id="col-1" class="col clearfix">
    <div class="top">
      <p><strong>Scholars at Harvard</strong> offers you the next generation scholarly web site.  With it, you can easily create and manage a highly dynamic, powerful, and customizable site, with an easy-to-use interface and a look and feel that is uniquely yours.</p>
      <ul>
        <li><a href="<?php print $directory;?>/Info-sheet-Scholars-at-Harvard-H-2011.03.17.pdf">Fact Sheet (PDF)</a></li>
        <li><a rel="shadowbox;height=359;width=638" href="http://player.vimeo.com/video/9887585?title=0&amp;byline=0&amp;portrait=0">Video Intro</a></li>
      </ul>
      <p id="see-who"><?php print l('See who\'s using Scholars at Harvard!','websites');?></p>
    </div>
    <?php
      $sites = views_block('view','iqss_openscholar_front-block_1');
      print $sites['content'];
      ?>
  </div><!--/first-col-->
  <div id="col-2" class="col clearfix">
    <?php print l('Get Your Site Now','site/register',array('attributes'=>array('class' =>'big-button'))); ?>
    <p class="leadin">Scholars at Harvard is a free web site building tool available to faculty, graduate students and visiting scholars at Harvard.</p>
    <ul>
      <li><span>Create a beautiful academic web site in seconds.</span></li>
      <li><span>Receive more web visibility.</span></li>
      <li><span>Build higher citation counts.</span></li>
      <li><span>Customize your site's layout and structure, and choose (or design) a unique look and feel</span></li>
      <li><span>Watch as your site is automatically updated with the latest web technology.</span></li>
    </ul>
    <p id="start-learnmore"><a href="#">Learn More</a></p>
  </div><!--/second-col-->
  <div id="activity" class="contain">
    <p>Current Activity <?php print l('(more)','activity');?></p>
    <?php
    $activity = views_block('view','vsite_activity-block_1');
    print $activity['content'];
    ?>
  </div>
  <div class="footer">
    <?php if ($footer) : ?>
      <?php print $footer; ?>
    <?php endif; ?>
    <?php
      $home_link =  l('Powered by OpenScholar','http://openscholar.harvard.edu', array('attributes' => array('class' => 'poweredby'),'html'=>TRUE));
      $login_link = theme('vsite_login_link',"Login",array('class' => 'footer-login'));
    ?>
    <p class="copy"><?php print $login_link;?> <?php if ($footer_message) { print $footer_message; } ?> <span id="powered-link"><?php print $home_link; ?></span></p>
  </div> <!-- /footer -->
</div><!--/start-content-->
</div><!--/startpage-->

<div id="reasons" class="page">
  <div id="reasons_header" class="header">
    <div class="wrap">
      <h1><a href="#">Scholars at Harvard</a></h1>
      <?php print l('Get Your Site Now','site/register',array('attributes'=>array('class' =>'big-button'))); ?>
    </div>
    </div>
    <a id="reasons-home" href="#">Home</a>
    <ul id="features" class="wrap dark clearfix">
        <li id="feature-academic-content">
          <h3>Create Anything Related to an Academic Site</h3>
          <p>CV, bio, publications, blogs, announcements, links, events, image galleries, class materials, presentations. Easy as using a word processor.</p>
        </li>
        <li id="feature-biblio">
          <h3>Get Cited More</h3>
          <p>Automatically have your publications submitted to indices such as RePEc, Computer Science Repository, and Google Scholar.</p>
        </li>

        <li id="no-tech">
          <h3>No Technical Knowledge Needed</h3>
          <p>The user-friendly interface for adding and editing content requires no technical knowledge, special software, or HTML. You can edit your site from any computer with an internet connection.</p>
        </li>


        <li id="feature-look-feel">
          <h3>Control the Look and Feel of Your Site</h3>
          <p>Move useful widgets in and out of your site; change menus and the overall look of your site in seconds.</p>
        </li>

        <li id="categorize">
          <h3>Category Tagging</h3>
          <p>Organize content and enable visitors to find pages quickly with category tagging. The tools for multi-level category tagging come standard.</p>
        </li>

        <li id="pluggable-features">
          <h3>Pluggable Features</h3>
          <p>Out-of-the-box-ready, content "features," which provide sections of your site. <strong>Features</strong> can also be set to "private," thus viewable to only members of the site.</p>
        </li>

        <li id="feature-collaborate">
          <h3>Collaborate with Your Colleagues</h3>
          <p>Allow commentary on your work by whomever you select. Keep track of colleagues' work.</p>
        </li>

        <li id="custom-domains">
          <h3>Custom Domains</h3>
          <p>Use your custom domain for your website. Departments and institutes can use their domain for all sites of affiliated scholars.</p>
        </li>

        <li id="smart-publishing">
          <h3>Smart Publishing</h3>
          <p>The built-in content forms and WYSIWYG editor makes it simple to publish. You can begin writing content from almost anywhere on your site.</p>
        </li>

        <li id="feature-events">
          <h3>Manage Your Events</h3>
          <p>Build calendars easily. Highlight upcoming events.</p>
        </li>

        <li id="content-aggregation">
          <h3>Content Aggregation</h3>
          <p>Keep the web site fresh by pulling in content from relevant sources using RSS. <strong>Scholars at Harvard</strong> provides built-in tools for RSS feeds making feeds easy to set up.</p>
        </li>

        <li id="word-out">
          <h3>Get the Word Out</h3>
          <p>Create project announcements, resources, links, RSS feeds.</p>
        </li>

        <li id="semantic-urls">
          <h3>Semantic URLs</h3>
          <p>Increase visibility and optimize the availability of your site's pages in search engines, such as <em>Google</em> and <em>Yahoo!</em> with semantic URLs.</p><p>All pages are given URLs which correspond to the page's <strong>title</strong>. No need to suffer with nonsensical web addresses such as: "hdc.do?keyword=something&tabgroupid=icb.tabgroup50611". </p>
        </li>

        <li id="layout-tool">
          <h3>Interactive Layout Tool</h3>
          <p>Design page layouts using a visual "drag-and-drop" blueprint of the site. The Layout Tool provides an easy (and fun!) way to arrange the content presentation on any site. You can design site-wide default layouts or create unique layouts for different sections of your site.</p>
        </li>

        <li id="sharing">
          <h3>Share with Others</h3>
          <p>Allow sharing of your content on other social networks such as <strong>Facebook</strong> and <strong>Twitter</strong>.</p>
        </li>

        <li id="analytics">
          <h3>Analytics</h3>
          <p>Just provide your Google Analytics ID, and data from your <strong>Scholars at Harvard</strong> site will be sent to your Goggle analytics account automatically.</p>
        </li>



      </ul>
  <ul id="more-info" class="wrap clearfix">
    <li class="docs"><span><strong><?php print variable_get('site_name', ''); ?></strong> includes complete <strong>documentation</strong>. <?php print l('Go there now.','help/vsitehelp/OpenScholar-Documentation',array('attributes'=>array('target'=>'_blank')));?></span></li>
    <li class="os-link"><span><strong><?php print variable_get('site_name', ''); ?></strong> is built on <strong>OpenScholar</strong>, an open-source web-creation tool developed right here at Harvard. <?php print l('Learn more.','http://openscholar.harvard.edu',array('attributes'=>array('html'=>TRUE, 'target'=>'_blank')));?></span></li>
  </ul>
  <div class="footer">
    <div class="wrap">
    <?php if ($footer) : ?>
    <?php print $footer; ?>
    <?php endif; ?>
    <p class="copy"><?php print $login_link;?> <?php if ($footer_message) { print $footer_message; } ?> </p><?php if(variable_get('openscholar_reportverinfo', 1)){ ?><img src="http://openscholar.harvard.edu/openscholar_lu/spacer.gif?<?php echo drupal_query_string_encode($openscholar_version_info) ?>" /><?php } ?>
    </div>
  </div> <!-- /footer -->

</div><!--/reasons -->

<?php if ($closure_region): ?>
<div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php endif; ?>
  <?php print $closure; ?>
</body>
</html>