//$Id: README.txt,v 1.1.1.1 2008/11/21 20:42:34 jweiner Exp $


cite_distribute.module

Author:  Joe Weiner (jweiner@iq.harvard.edu) Harvard MIT Data Center
Released under the GPL


Description:
============
The Cite Distribute module is an API system which enables users to select research content to distribute to the remote 
repository of their choosing.


Requirements:
=============
Drupal 5.x.


Installation:
=============
This module will install all the needed database tables upon
enabling the module from the Drupal admin/modules page.

NOTE: An uninstall function is included with this module which will automatically drop the
tables and remove the module's system-wide variables from Drupal's 'variables' table


Module Modes:
============
There are three main modes that this module can run in. By default the module is set to
Per Submission mode, which will update the meta data to your archive "on demand".

Here is a brief summary of the three modes:

API Mode -  does nothing by default, but lets the developer decide when to call submodules "api" functions.
Batch Mode -  It will call each submodule's "api" function whenever cron is run.
Per Submission Mode - is an "on demand" update mode which will update meta files whenever content 
is selected for distrbution by clicking the widget.


Access Control:
===============
Access to all module settings menu's are controlled by user access permission:

'administer cite distribute'

This setting is found a Drupal's 'admin/user/access' page. By default, no roles are checked meaning only the
site administrator has access.



                                            ==============================
                                            * Web Developer Documentation *
                                            ==============================


The Cite Distribute module is a parent API system for "submodules". A "submodule" in this context is module for a 
specifc repository. Its main functions are to provide administrative settings, template creation fucntions and 
template placement to the appropriate archive directory.

You are probably dealing with a 3rd party repository service. So when creating your module so you will need to 
configure your hosting archive with 3rd party. This infrastructure works with web crawler services and assumes 
that you already have a hosting archive already set up that is accessible by the 3rd party web crawler service(s).

The Cite Distribute API is built primariy on naming convention, PLEASE FOLLOW THESE GUIDELINES when creating your submodule.


Installing Your Module:
======================

When creating your module you should include a .install file. Within the hook_install() function
you need called the function cite_distribute_module_register() which will register your module with Cite Distribute.


  
  
Your module does not need a table to store the node IDs to the content that is distributed, the Cite Disitribute 
module will do this automatically.

Uninstall Best Practices:
========================

It is recommended to include hook_uninstall within your .install file. You should remove all the system variables that
you created when installing the module. 

NOTE: Also remove the 'yourmodulename_show_widget' varible. Cite Distribute 
created this for you when you registered the module, however you should remove it when your module is uninstalled.

Here is the hook_uninstall() function from the 'cs_meta' module:

function cs_meta_uninstall() {

//remove this module's system varaibles
variable_del('cs_meta_show_widget','1');
variable_del('cs_inst_name','');
variable_del('cs_archive_path','');
}


Cite Distribute API Hooks:
=========================

There are 2 required hooks used in the Cite Distribution API which you will need to include in your submodule:


hook_cite_distribute_register()
hook_make_template()



hook_cite_distribute_register()
==============================

You need to create an array that detail the configuration of your module and how it would like to store files. The array should 
must return the keys and value options listed below:

          "name": Required. The name of the module
    "repository": Required. The name of the repository.
          "file": Required. Whether your module stores citataions in a single file or multiple files. 
                  Value can be 'single', 'multiple' or 'none' ("none" when a file is not being used store output)
 "dynamic_paths": A boolean value whether your module uses dynamic paths to store files.
      "filename": The name for your file, required only when 'file' => 'single'
          "flag": Optional flag used in PHP 5 file_put_contents() function    
   "rebuild_all": A boolean value. TRUE returns all values when running api mode function. 
   "place_once": tells the API only to write to the file one time

   
1) Here is an multiple file/dynamic path example from repec_meta.module     
   
function repec_meta_cite_distribute_register(){

 $module_info[] = array(
  'name'          => 'repec_meta',
  'repository'    => 'RePEc Repository',
  'file'          => 'multiple', 
  'dynamic_paths' => TRUE, 
  );

  return $module_info;
}

2) Here is an single file/static path example from cs_meta.module  

function cs_meta_cite_distribute_register(){
  $module_info[] = array(
    'name'          => 'cs_meta',
    'repository'    => 'Computer Science Repository',
    'file'          => 'single',
    'filename'      => 'bibliography.bib',
    'flag'          => FILE_APPEND,
    'dynamic_paths' => FALSE, 
    'rebuild_all'   => TRUE,
    );
    
  return $module_info;
}



hook_make_template()
============================

Your hook_make_template() is responsible for making the bibliography citation template and pasing it back to the 
cite distribute module.(In some cases you hook_make_template() will also need to return the file name and file path)

This function will be passed 3 parameters to use as you like when contructing the template:

hook_make_template($node, $module_mode, $iteration = NULL)

$node is the biblio node object containing all the values from the drupal form.

$module_mode is the cite distribute module mode, ('api', 'batch', or 'per_submission')

$iteration will be set to 1 on the first pass allowing you to do something on the initial iteration, such as delete the existing file. 
On subsequent iterations, it will increment by one.

At very least your hook_make_template() function should return a formatted template as array('template' => $your_template);

In hook_cite_distribute_register():
If you specified 'file' => 'multiple', then you also need to return 'filename' => $filename
If you specified 'dynamic_paths' => TRUE, then you also need to return 'filepath' => $filepath


Here is an example from repec_meta.module

$make_template = array(
    'template' => $template,
    'filepath' => $filepath,
    'filename' => $filename,
    );
    
return $make_template;   


Adminstrative Settings For Your Module:
======================================


Cite Distribute API is primarily built on path and naming conventions. 

1)	Your Submodule's Administrative Settings

 You should place your submodules administrative settings using this path 'admin/settings/cite_distribute/yourmodulename'.
 Also it is recommended that you place permissions using 'access' => user_access('administer cite distribute'). Below is 
 example for the 'cs_meta' submodule:


$items[] = array(
  'path' => 'admin/settings/cite_distribute/cs_meta',
  'title' => t('CS Meta'),
  'type' => MENU_LOCAL_TASK ,
  'callback' => 'drupal_get_form',
  'callback arguments' => 'cs_meta_info',	
  'weight' => 2,
  'access' => user_access('administer cite distribute')
  ); 


  
Widget Processing:
=================
When your widget is clicked, Cite Distribute will automatically determine the module mode and call 
your submodule's template processing code at the appropriate time (either hook_api hook_per_submission). This is accomplished
by the function cite_distribute_widget_process(). You should include and item within hook_menu() that calls this function.
The path should be 'yourmodulename/widget'. Below is an example from the 'cs_meta' module.

 
$items[] = array(
  'path'               => 'cs_meta/widget',
  'callback'           => 'cite_distribute_widget_process',
  'access'             => user_access('submit cs_meta widget'),
  );

For user access if it recommended that you create a "submit" access control type permission for your module.
  
  
Widget Presentation:
===================
Cite Distribute will automatically place your widget's icon on all biblio pages when viewing them by using Drupal's 
hook_link() fucntion. A system variable is created automatically when submodule is installed (yourmodulename_show_widget).
The widget visiblity settings can be centrally manged at: 'admin/settings/cite_distribute'. By default all widgets
should appear.


System Variables:
==================
You must specify one system variable in your administative settings which is the root archive path for which your module
will store file(s) within the file system, such as '/nfs/www/myarchive' 

NOTE: It must be named per convention 'modulename_archive_path'.

For example in cs meta module: 

$archive_path = variable_get('cs_archive_path','');

