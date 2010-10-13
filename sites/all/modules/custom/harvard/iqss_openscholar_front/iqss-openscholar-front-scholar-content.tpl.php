<div id="panel-wrapper">
<div class="panel">
<div class="row">

<?php
$publications = openscholar_front_block('view','recent_publications');
print $publications['content'];

$activity = openscholar_front_block('view','site_activity');
print $activity['content'];
?>

<div id="about-abstract">
<h2>Harvard Scholars: Create a dynamic feature-full personal web site in seconds. For free!
(No, there’s no catch.)</h2>

<h3>Great features for academics</h3>
<img src="widget.png" alt="">
<p>Manage your CV, bio, publications, blogs, announcements, links, image galleries, events, class materials. Automatically have your publications submitted to induces such as RePEc,
Computer Science Repository, and Google Scholar.</p>

<h3>Super easy-to-use admin tools</h3>
<img src="wrench.png" alt="">
<p>Use a web browser on any networked computer in the workd to create and edit content, move useful widgets in and out of your site; change menus, categorize your work.</p>

<h3>Beautiful themes</h3>
<img src="theme.png" alt="">
<p>Instantly change the look of your site with many elegant themes, or import your own custom theme.</p>
</div>

<p id="learn-more-toggle"><a href="learn-more">Learn More about <span>[title]</span></a></p>
<div><!--/row -->
</div><!--/panel -->
<div class="panel">
<p id="activity-toggle"><a href="welcome">Recent Activity</a></p>

<div class="row">
<?php
$video = openscholar_front_block('view','video_info');
print $video['content'];

$mission = openscholar_front_block('view','site_mission');
print $mission['content'];
?>
</div><!--/row -->

<div class="row">
<p><strong>Scholars at Harvard</strong> is a free web site building tool available to faculty, graduate students and visiting scholars at Harvard. It is one of two main Harvard installations
of <strong>OpenScholar</strong> and a creation of Harvard’s <em>Institute for Quantitative Social Sciences.</em></p>

<p><strong>Scholars at Harvard</strong> (and the project-oriented <strong>Projects at Harvard</strong>) provide simple web site creation and management with a suite of features
tailored to the particular needs of academics.</p>

<h3>Features</h3>
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
</div><!--/panel -->
</div>