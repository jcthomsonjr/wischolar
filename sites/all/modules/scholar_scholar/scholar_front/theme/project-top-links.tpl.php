<ul id="top-front">
  <li><?php print l('About', 'help/vsitehelp/OpenScholar-Documentation'); ?> </li>
  <li><?php print  ($user->uid > 0) ? l('Log out', 'logout') :   l('Log in', 'user'); ?></li>
  <li><?php print l('Need a Site for a Project?', 'http://projects.iq.harvard.edu');?></li>
  <li id="get-form"> <?php  if ($front_button_link ) { print $front_button_link; }
  else { print '<span id="coming-soon"> Coming Soon </span>'; } ?> </li>
</ul>