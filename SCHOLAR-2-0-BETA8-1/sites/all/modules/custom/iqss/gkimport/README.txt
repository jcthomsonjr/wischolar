gkimport for Drupal 6.x - 

Author: Joe Weiner
Institution: The Institute for Quantitative Social Science

SUMMARY
--------------
gkimport is a module/script which attempts to import Gary King's current html based designed to be run 
once web site (http://gking.harvard.edu/) to an OpenScholar site. The script will create the 
user account, roles, site, taxonomy, nodes, etc. programatically parsing data from collected bibTex, csv 
and remote html files.


SYSTEM VARIABLES
--------------------------

1) gkimport_taxonomy_data -- an array of publications containing the node title as the key and term(s) as the value (some publications do not have terms).
2) gkimport_pub_nodes -- an array of node ID's of publications created from the biblio import (from a bibTex file)
3) gkimport_na_pub_nodes -- an array listing all publication node IDs created without abstracts
4) gkimport_drush_run -- integer, 1 if running script from Drush, 0 otherwise


DRUSH
----------
It is recommended that you call the script from drush to get real-time feedback and avoid page load 
time-outs. Assuming you have Drush installed (http://drupal.org/project/drush), you can instantiate 
the script by calling the drush command:

gkimport

As the script runs, real-time feedback will be displayed in your shell window.

