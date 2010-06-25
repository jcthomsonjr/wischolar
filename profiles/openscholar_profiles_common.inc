<?php

/**
 *  Change the biblio Config
 *  TODO: permissions
 */
function _openscholar_profiles_configure_biblio(){
  $s_common_string = <<<COMMON
a:4:{s:7:"storage";N;s:9:"submitted";b:1;s:6:"values";a:6:{s:15:"configured_flds";a:52:{i:15;a:4:{s:5:"title";s:19:"Year of Publication";s:4:"hint";s:33:"Enter YYYY, Submitted or In Press";s:6:"weight";s:3:"-45";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";s:8:"required";s:12:"autocomplete";i:0;}}i:1;a:5:{s:5:"title";s:7:"Authors";s:4:"hint";s:0:"";s:6:"weight";s:1:"2";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";s:8:"required";s:12:"autocomplete";s:12:"autocomplete";}s:9:"auth_type";a:18:{i:1;s:1:"1";i:2;s:1:"2";i:3;s:1:"3";i:4;s:1:"4";i:5;s:1:"5";i:10;s:2:"10";i:11;s:2:"11";i:12;s:2:"12";i:13;s:2:"13";i:14;s:2:"14";i:15;s:2:"15";i:16;s:2:"16";i:17;s:2:"17";i:18;s:2:"18";i:19;s:2:"19";i:20;s:2:"20";i:21;s:2:"21";i:22;s:2:"22";}}i:2;a:5:{s:5:"title";s:17:"Secondary Authors";s:4:"hint";s:0:"";s:6:"weight";s:1:"2";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}s:9:"auth_type";a:1:{i:2;s:1:"2";}}i:3;a:5:{s:5:"title";s:16:"Tertiary Authors";s:4:"hint";s:0:"";s:6:"weight";s:1:"3";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}s:9:"auth_type";a:1:{i:3;s:1:"3";}}i:4;a:5:{s:5:"title";s:18:"Subsidiary Authors";s:4:"hint";s:0:"";s:6:"weight";s:1:"4";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}s:9:"auth_type";a:1:{i:4;s:1:"4";}}i:5;a:5:{s:5:"title";s:17:"Corporate Authors";s:4:"hint";s:0:"";s:6:"weight";s:1:"5";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}s:9:"auth_type";a:1:{i:5;s:1:"5";}}i:6;a:4:{s:5:"title";s:15:"Secondary Title";s:4:"hint";s:0:"";s:6:"weight";s:2:"12";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:7;a:4:{s:5:"title";s:14:"Tertiary Title";s:4:"hint";s:0:"";s:6:"weight";s:2:"13";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:17;a:4:{s:5:"title";s:6:"Volume";s:4:"hint";s:0:"";s:6:"weight";s:2:"14";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:37;a:4:{s:5:"title";s:17:"Number of Volumes";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:43;a:4:{s:5:"title";s:7:"Section";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:28;a:4:{s:5:"title";s:5:"Issue";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:16;a:4:{s:5:"title";s:7:"Edition";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:18;a:4:{s:5:"title";s:6:"Number";s:4:"hint";s:0:"";s:6:"weight";s:2:"16";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:19;a:4:{s:5:"title";s:10:"Pagination";s:4:"hint";s:0:"";s:6:"weight";s:2:"17";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:20;a:4:{s:5:"title";s:14:"Date Published";s:4:"hint";s:9:"(mm/yyyy)";s:6:"weight";s:2:"18";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:13;a:4:{s:5:"title";s:9:"Publisher";s:4:"hint";s:0:"";s:6:"weight";s:2:"19";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:14;a:4:{s:5:"title";s:15:"Place Published";s:4:"hint";s:0:"";s:6:"weight";s:2:"20";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:25;a:4:{s:5:"title";s:12:"Type of Work";s:4:"hint";s:14:"Masters Thesis";s:6:"weight";s:2:"22";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:21;a:4:{s:5:"title";s:20:"Publication Language";s:4:"hint";s:0:"";s:6:"weight";s:2:"23";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:12;a:4:{s:5:"title";s:25:"Other Author Affiliations";s:4:"hint";s:0:"";s:6:"weight";s:2:"24";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:46;a:4:{s:5:"title";s:11:"ISSN Number";s:4:"hint";s:0:"";s:6:"weight";s:3:"150";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:9;a:4:{s:5:"title";s:11:"ISBN Number";s:4:"hint";s:0:"";s:6:"weight";s:3:"150";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:8;a:4:{s:5:"title";s:16:"Accession Number";s:4:"hint";s:0:"";s:6:"weight";s:3:"151";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:10;a:4:{s:5:"title";s:11:"Call Number";s:4:"hint";s:0:"";s:6:"weight";s:3:"152";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:11;a:4:{s:5:"title";s:13:"Other Numbers";s:4:"hint";s:0:"";s:6:"weight";s:3:"153";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:24;a:4:{s:5:"title";s:8:"Keywords";s:4:"hint";s:0:"";s:6:"weight";s:3:"154";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:12:"autocomplete";s:12:"autocomplete";s:8:"required";i:0;}}i:22;a:4:{s:5:"title";s:8:"Abstract";s:4:"hint";s:0:"";s:6:"weight";s:1:"1";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:23;a:4:{s:5:"title";s:15:"French Abstract";s:4:"hint";s:0:"";s:6:"weight";s:3:"156";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:27;a:4:{s:5:"title";s:5:"Notes";s:4:"hint";s:0:"";s:6:"weight";s:3:"157";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:26;a:4:{s:5:"title";s:3:"URL";s:4:"hint";s:0:"";s:6:"weight";s:3:"158";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:47;a:4:{s:5:"title";s:3:"DOI";s:4:"hint";s:0:"";s:6:"weight";s:3:"159";s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:29;a:4:{s:5:"title";s:13:"Reseach Notes";s:4:"hint";s:0:"";s:6:"weight";s:3:"160";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:30;a:4:{s:5:"title";s:8:"Custom 1";s:4:"hint";s:0:"";s:6:"weight";s:3:"161";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:31;a:4:{s:5:"title";s:8:"Custom 2";s:4:"hint";s:0:"";s:6:"weight";s:3:"162";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:32;a:4:{s:5:"title";s:8:"Custom 3";s:4:"hint";s:0:"";s:6:"weight";s:3:"163";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:33;a:4:{s:5:"title";s:8:"Custom 4";s:4:"hint";s:0:"";s:6:"weight";s:3:"164";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:34;a:4:{s:5:"title";s:8:"Custom 5";s:4:"hint";s:0:"";s:6:"weight";s:3:"165";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:35;a:4:{s:5:"title";s:8:"Custom 6";s:4:"hint";s:0:"";s:6:"weight";s:3:"167";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:36;a:4:{s:5:"title";s:8:"Custom 7";s:4:"hint";s:0:"";s:6:"weight";s:3:"168";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:38;a:4:{s:5:"title";s:11:"Short Title";s:4:"hint";s:0:"";s:6:"weight";s:3:"169";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:39;a:4:{s:5:"title";s:15:"Alternate Title";s:4:"hint";s:0:"";s:6:"weight";s:3:"170";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:40;a:4:{s:5:"title";s:16:"Translated Title";s:4:"hint";s:0:"";s:6:"weight";s:3:"170";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:41;a:4:{s:5:"title";s:20:"Original Publication";s:4:"hint";s:0:"";s:6:"weight";s:3:"171";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:42;a:4:{s:5:"title";s:15:"Reprint Edition";s:4:"hint";s:0:"";s:6:"weight";s:3:"172";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:44;a:4:{s:5:"title";s:12:"Citation Key";s:4:"hint";s:0:"";s:6:"weight";s:3:"175";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:45;a:4:{s:5:"title";s:10:"COinS Data";s:4:"hint";s:36:"This will be automatically generated";s:6:"weight";s:3:"176";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:49;a:4:{s:5:"title";s:20:"Remote Database Name";s:4:"hint";s:0:"";s:6:"weight";s:3:"176";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:50;a:4:{s:5:"title";s:24:"Remote Database Provider";s:4:"hint";s:0:"";s:6:"weight";s:3:"177";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:48;a:4:{s:5:"title";s:14:"Author Address";s:4:"hint";s:0:"";s:6:"weight";s:3:"178";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:51;a:4:{s:5:"title";s:5:"Label";s:4:"hint";s:0:"";s:6:"weight";s:3:"178";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}i:52;a:4:{s:5:"title";s:11:"Access Date";s:4:"hint";s:0:"";s:6:"weight";s:3:"179";s:10:"checkboxes";a:3:{s:6:"common";i:0;s:8:"required";i:0;s:12:"autocomplete";i:0;}}}s:2:"op";s:4:"Save";s:6:"submit";s:4:"Save";s:13:"form_build_id";s:37:"form-8e8b10346a884999bb99b9b1f34fd2a4";s:10:"form_token";s:32:"4d6475b789132c3b4092d8cf0149824e";s:7:"form_id";s:28:"biblio_admin_types_edit_form";}s:14:"clicked_button";a:18:{s:5:"#type";s:6:"submit";s:6:"#value";s:4:"Save";s:5:"#post";a:5:{s:15:"configured_flds";a:52:{i:15;a:4:{s:5:"title";s:19:"Year of Publication";s:4:"hint";s:33:"Enter YYYY, Submitted or In Press";s:10:"checkboxes";a:2:{s:6:"common";s:6:"common";s:8:"required";s:8:"required";}s:6:"weight";s:3:"-45";}i:1;a:5:{s:5:"title";s:7:"Authors";s:4:"hint";s:0:"";s:9:"auth_type";a:18:{i:0;s:1:"1";i:1;s:1:"2";i:2;s:1:"3";i:3;s:1:"4";i:4;s:1:"5";i:5;s:2:"10";i:6;s:2:"11";i:7;s:2:"12";i:8;s:2:"13";i:9;s:2:"14";i:10;s:2:"15";i:11;s:2:"16";i:12;s:2:"17";i:13;s:2:"18";i:14;s:2:"19";i:15;s:2:"20";i:16;s:2:"21";i:17;s:2:"22";}s:10:"checkboxes";a:3:{s:6:"common";s:6:"common";s:8:"required";s:8:"required";s:12:"autocomplete";s:12:"autocomplete";}s:6:"weight";s:1:"2";}i:2;a:4:{s:5:"title";s:17:"Secondary Authors";s:4:"hint";s:0:"";s:9:"auth_type";a:1:{i:0;s:1:"2";}s:6:"weight";s:1:"2";}i:3;a:4:{s:5:"title";s:16:"Tertiary Authors";s:4:"hint";s:0:"";s:9:"auth_type";a:1:{i:0;s:1:"3";}s:6:"weight";s:1:"3";}i:4;a:4:{s:5:"title";s:18:"Subsidiary Authors";s:4:"hint";s:0:"";s:9:"auth_type";a:1:{i:0;s:1:"4";}s:6:"weight";s:1:"4";}i:5;a:4:{s:5:"title";s:17:"Corporate Authors";s:4:"hint";s:0:"";s:9:"auth_type";a:1:{i:0;s:1:"5";}s:6:"weight";s:1:"5";}i:6;a:3:{s:5:"title";s:15:"Secondary Title";s:4:"hint";s:0:"";s:6:"weight";s:2:"12";}i:7;a:3:{s:5:"title";s:14:"Tertiary Title";s:4:"hint";s:0:"";s:6:"weight";s:2:"13";}i:17;a:3:{s:5:"title";s:6:"Volume";s:4:"hint";s:0:"";s:6:"weight";s:2:"14";}i:37;a:3:{s:5:"title";s:17:"Number of Volumes";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";}i:43;a:3:{s:5:"title";s:7:"Section";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";}i:28;a:3:{s:5:"title";s:5:"Issue";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";}i:16;a:3:{s:5:"title";s:7:"Edition";s:4:"hint";s:0:"";s:6:"weight";s:2:"15";}i:18;a:3:{s:5:"title";s:6:"Number";s:4:"hint";s:0:"";s:6:"weight";s:2:"16";}i:19;a:3:{s:5:"title";s:10:"Pagination";s:4:"hint";s:0:"";s:6:"weight";s:2:"17";}i:20;a:3:{s:5:"title";s:14:"Date Published";s:4:"hint";s:9:"(mm/yyyy)";s:6:"weight";s:2:"18";}i:13;a:3:{s:5:"title";s:9:"Publisher";s:4:"hint";s:0:"";s:6:"weight";s:2:"19";}i:14;a:3:{s:5:"title";s:15:"Place Published";s:4:"hint";s:0:"";s:6:"weight";s:2:"20";}i:25;a:3:{s:5:"title";s:12:"Type of Work";s:4:"hint";s:14:"Masters Thesis";s:6:"weight";s:2:"22";}i:21;a:3:{s:5:"title";s:20:"Publication Language";s:4:"hint";s:0:"";s:6:"weight";s:2:"23";}i:12;a:3:{s:5:"title";s:25:"Other Author Affiliations";s:4:"hint";s:0:"";s:6:"weight";s:2:"24";}i:46;a:3:{s:5:"title";s:11:"ISSN Number";s:4:"hint";s:0:"";s:6:"weight";s:3:"150";}i:9;a:4:{s:5:"title";s:11:"ISBN Number";s:4:"hint";s:0:"";s:10:"checkboxes";a:1:{s:6:"common";s:6:"common";}s:6:"weight";s:3:"150";}i:8;a:4:{s:5:"title";s:16:"Accession Number";s:4:"hint";s:0:"";s:10:"checkboxes";a:1:{s:6:"common";s:6:"common";}s:6:"weight";s:3:"151";}i:10;a:4:{s:5:"title";s:11:"Call Number";s:4:"hint";s:0:"";s:10:"checkboxes";a:1:{s:6:"common";s:6:"common";}s:6:"weight";s:3:"152";}i:11;a:4:{s:5:"title";s:13:"Other Numbers";s:4:"hint";s:0:"";s:10:"checkboxes";a:1:{s:6:"common";s:6:"common";}s:6:"weight";s:3:"153";}i:24;a:4:{s:5:"title";s:8:"Keywords";s:4:"hint";s:0:"";s:10:"checkboxes";a:2:{s:6:"common";s:6:"common";s:12:"autocomplete";s:12:"autocomplete";}s:6:"weight";s:3:"154";}i:22;a:4:{s:5:"title";s:8:"Abstract";s:4:"hint";s:0:"";s:10:"checkboxes";a:1:{s:6:"common";s:6:"common";}s:6:"weight";s:1:"1";}i:23;a:3:{s:5:"title";s:15:"French Abstract";s:4:"hint";s:0:"";s:6:"weight";s:3:"156";}i:27;a:3:{s:5:"title";s:5:"Notes";s:4:"hint";s:0:"";s:6:"weight";s:3:"157";}i:26;a:4:{s:5:"title";s:3:"URL";s:4:"hint";s:0:"";s:10:"checkboxes";a:1:{s:6:"common";s:6:"common";}s:6:"weight";s:3:"158";}i:47;a:4:{s:5:"title";s:3:"DOI";s:4:"hint";s:0:"";s:10:"checkboxes";a:1:{s:6:"common";s:6:"common";}s:6:"weight";s:3:"159";}i:29;a:3:{s:5:"title";s:13:"Reseach Notes";s:4:"hint";s:0:"";s:6:"weight";s:3:"160";}i:30;a:3:{s:5:"title";s:8:"Custom 1";s:4:"hint";s:0:"";s:6:"weight";s:3:"161";}i:31;a:3:{s:5:"title";s:8:"Custom 2";s:4:"hint";s:0:"";s:6:"weight";s:3:"162";}i:32;a:3:{s:5:"title";s:8:"Custom 3";s:4:"hint";s:0:"";s:6:"weight";s:3:"163";}i:33;a:3:{s:5:"title";s:8:"Custom 4";s:4:"hint";s:0:"";s:6:"weight";s:3:"164";}i:34;a:3:{s:5:"title";s:8:"Custom 5";s:4:"hint";s:0:"";s:6:"weight";s:3:"165";}i:35;a:3:{s:5:"title";s:8:"Custom 6";s:4:"hint";s:0:"";s:6:"weight";s:3:"167";}i:36;a:3:{s:5:"title";s:8:"Custom 7";s:4:"hint";s:0:"";s:6:"weight";s:3:"168";}i:38;a:3:{s:5:"title";s:11:"Short Title";s:4:"hint";s:0:"";s:6:"weight";s:3:"169";}i:39;a:3:{s:5:"title";s:15:"Alternate Title";s:4:"hint";s:0:"";s:6:"weight";s:3:"170";}i:40;a:3:{s:5:"title";s:16:"Translated Title";s:4:"hint";s:0:"";s:6:"weight";s:3:"170";}i:41;a:3:{s:5:"title";s:20:"Original Publication";s:4:"hint";s:0:"";s:6:"weight";s:3:"171";}i:42;a:3:{s:5:"title";s:15:"Reprint Edition";s:4:"hint";s:0:"";s:6:"weight";s:3:"172";}i:44;a:3:{s:5:"title";s:12:"Citation Key";s:4:"hint";s:0:"";s:6:"weight";s:3:"175";}i:45;a:3:{s:5:"title";s:10:"COinS Data";s:4:"hint";s:36:"This will be automatically generated";s:6:"weight";s:3:"176";}i:49;a:3:{s:5:"title";s:20:"Remote Database Name";s:4:"hint";s:0:"";s:6:"weight";s:3:"176";}i:50;a:3:{s:5:"title";s:24:"Remote Database Provider";s:4:"hint";s:0:"";s:6:"weight";s:3:"177";}i:48;a:3:{s:5:"title";s:14:"Author Address";s:4:"hint";s:0:"";s:6:"weight";s:3:"178";}i:51;a:3:{s:5:"title";s:5:"Label";s:4:"hint";s:0:"";s:6:"weight";s:3:"178";}i:52;a:3:{s:5:"title";s:11:"Access Date";s:4:"hint";s:0:"";s:6:"weight";s:3:"179";}}s:2:"op";s:4:"Save";s:13:"form_build_id";s:37:"form-5192a1785bde6ff797761ec41b122f5e";s:10:"form_token";s:32:"4d6475b789132c3b4092d8cf0149824e";s:7:"form_id";s:28:"biblio_admin_types_edit_form";}s:11:"#programmed";b:0;s:5:"#tree";b:0;s:8:"#parents";a:1:{i:0;s:6:"submit";}s:14:"#array_parents";a:1:{i:0;s:6:"submit";}s:7:"#weight";d:0.003000000000000000062450045135165055398829281330108642578125;s:10:"#processed";b:0;s:12:"#description";N;s:11:"#attributes";a:0:{}s:9:"#required";b:0;s:6:"#input";b:1;s:5:"#name";s:2:"op";s:12:"#button_type";s:6:"submit";s:25:"#executes_submit_callback";b:1;s:8:"#process";a:1:{i:0;s:16:"form_expand_ahah";}s:3:"#id";s:11:"edit-submit";}}  
COMMON;
   
   include_once(drupal_get_path('module','biblio')."/biblio.admin.inc");
   drupal_execute('biblio_admin_types_edit_form',unserialize(trim($s_common_string)));
   
   db_query("UPDATE `biblio_field_type` SET visible = 0 WHERE fid IN(2,3,4,5) AND visible = 1"); //Hide all the other authers
   db_query("UPDATE `biblio_field_type` SET weight = -1 WHERE fid = 22");  //Move Abstract
   db_query("UPDATE `biblio_field_type` SET required = 0 WHERE fid = 15"); //No pub date req.
}

function   _openscholar_profiles_wysiwyg_config(){
  $settings = array (
    'default' => 1,
    'user_choose' => 0,
    'show_toggle' => 1,
    'theme' => 'advanced',
    'language' => 'en',
    'buttons' => array(
      'default' => array (
         'bold' => 1,
         'italic' => 1,
         'strikethrough' => 1,
         'bullist' => 1,
         'numlist' => 1,
         'link' => 1,
         'unlink' => 1,
         'image' => 1,
         'code' => 1,
         'cut' => 1,
         'copy' => 1,
         'paste' => 1,
         'charmap' => 1,
       ),
            
       'font' => array('formatselect' => 1),
       'fullscreen' => array('fullscreen' => 1),
       'paste' => array('pastetext' => 1),
       'table' => array('tablecontrols' => 1),
       'safari' => array('safari' => 1),
       'drupal' => array ('break' => 1),
    ),

    'toolbar_loc' => 'top',
    'toolbar_align' => 'left',
    'path_loc' => 'bottom',
    'resizing' => 1,
    'verify_html' => 1,
    'preformatted' => 0, 
    'convert_fonts_to_spans' => 1,
    'remove_linebreaks' => 1,
    'apply_source_formatting' => 0,
    'paste_auto_cleanup_on_paste' => 1,
    'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6',
    'css_setting' => 'theme',
    'css_path' => '',
    'css_classes' => '',

);

$settings = serialize($settings);

  $query = "SELECT format FROM {filter_formats} WHERE name='%s'";
  $filter_name = db_result(db_query($query,'Filtered HTML'));
  $query = "INSERT INTO {wysiwyg} (format, editor, settings) VALUES ('%d', '%s', '%s')";
  db_query($query, $filter_name, 'tinymce', $settings);
}


function _openscholar_profiles_contact_config(){
  install_include(array('contact'));
  //install_contact_add_category($category, $recipients, $reply = '', $weight = 0, $selected = 0);
  install_contact_add_category('website feedback', 'scholars_dev_support@help.hmdc.harvard.edu', $reply = '', $weight = 0, $selected = 1);
  install_contact_add_category('feature request', 'scholars_dev_support@help.hmdc.harvard.edu', $reply = '', $weight = 0, $selected = 0);
  install_contact_add_category('bug report', 'scholars_dev_support@help.hmdc.harvard.edu', $reply = '', $weight = 0, $selected = 0);
}


/**
 *  Creates roles and permissions
 */
function _openscholar_profiles_create_roles(){
  install_add_role('scholar admin');
  install_add_role('scholar user');
}


/**
 * Set the project name variable
 */
function  _openscholar_profiles_project_name(){
  // set the project name
   variable_set('scholar_project_name', "OpenScholar");
}
