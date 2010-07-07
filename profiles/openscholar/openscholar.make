; $Id: openscholar.make,v 1.1.2.23 2010/07/07 17:18:25 rbrandon Exp $

;Core Version
core = "6.x"
   
;Drupal Core
projects[drupal][version] = "6.17" 

; Contrib projects 

projects[addthis][subdir] = "contrib"
projects[addthis][version] = "2.9"

projects[advanced_help][subdir] = "contrib"
projects[advanced_help][version] = "1.2"

projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = "1.2"

projects[calendar][subdir] = "contrib"
projects[calendar][version] = "2.2"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.7"

projects[content_profile][subdir] = "contrib"
projects[content_profile][version] = "1.0"

projects[context][subdir] = "contrib"
projects[context][version] = "2.0"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.6"

projects[data][subdir] = "contrib"
projects[data][version] = "1.0-alpha11"

projects[date][subdir] = "contrib"
projects[date][version] = "2.4"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.0"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0-beta8"

projects[filefield][subdir] = "contrib"
projects[filefield][version] = "3.5"

projects[filefield_paths][subdir] = "contrib"
projects[filefield_paths][version] = "1.4"

projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0-beta3"

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = "1.8"

projects[imagefield][subdir] = "contrib"
projects[imagefield][version] = "3.3"

projects[imagefield_crop][subdir] = "contrib"
projects[imagefield_crop][version] = "1.0-rc2"

projects[install_profile_api][subdir] = "contrib"
projects[install_profile_api][version] = "2.1"

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = "1.3"

projects[link][subdir] = "contrib"
projects[link][version] = "2.9"

;projects[lightbox2][subdir] = "contrib"
;projects[lightbox2][version] = "1.9"

projects[luceneapi][subdir] = "contrib"
projects[luceneapi][version] = "2.2"

projects[luceneapi_dym][subdir] = "contrib"
projects[luceneapi_dym][version] = "1.0-beta4"

projects[menu_node][subdir] = "contrib"
projects[menu_node][version] = "1.3"

projects[mollom][subdir] = "contrib"
projects[mollom][version] = "1.13"

projects[nodereference_url][subdir] = "contrib"
projects[nodereference_url][version] = "1.6"

projects[og][subdir] = "contrib"
projects[og][version] = "2.1"

projects[og_vocab][subdir] = "contrib"
projects[og_vocab][version] = "1.1"

projects[override_node_options][subdir] = "contrib"
projects[override_node_options][version] = "1.10"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.3"

projects[schema][subdir] = "contrib"
projects[schema][version] = "1.7"

projects[stringoverrides][subdir] = "contrib"
projects[stringoverrides][version] = "1.7"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "1.1"

projects[token][subdir] = "contrib"
projects[token][version] = "1.13"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "2.1"

projects[twitter_pull][subdir] = "contrib"
projects[twitter_pull][version] = "1.1"

projects[ucreate][subdir] = "contrib"
projects[ucreate][version] = "1.0-beta3"

projects[views][subdir] = "contrib"
projects[views][version] = "2.11"

projects[views_attach][subdir] = "contrib"
projects[views_attach][version] = "2.2"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "1.9"

projects[wysiwyg][subdir]="contrib"
projects[wysiwyg][version]= "2.1"



;Contrib (Drupal Modules without official Releases - Pulling from stable tested revision)

projects[luceneapi_biblio][subdir] = "contrib"
projects[luceneapi_biblio][type] = "module"
projects[luceneapi_biblio][download][type] = "svn"
projects[luceneapi_biblio][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/branches/SCHOLAR-2-0-BETA5/sites/all/modules/contrib/luceneapi_biblio/"

; To be released
projects[dialog][subdir] = "contrib"
projects[dialog][type] = "module"
projects[dialog][download][type] = "cvs"
projects[dialog][download][module] = "contributions/modules/dialog"
projects[dialog][download][revision] = "DRUPAL-6--1:2010-02-24"

projects[activity][subdir] = "contrib"
projects[activity][type] = "module"
projects[activity][download][type] = "cvs"
projects[activity][download][module] = "contributions/modules/activity"
projects[activity][download][revision] = "DRUPAL-6--2:2010-06-30"

projects[imagecache][subdir] = "contrib"
projects[imagecache][type] = "module"
projects[imagecache][download][type] = "cvs"
projects[imagecache][download][module] = "contributions/modules/imagecache"
projects[imagecache][download][revision] = "DRUPAL-6--1:2010-05-26"


;Contrib (Non-Patched Included but not enabled by default in the profile)
projects[devel][subdir] = "contrib"
projects[devel][version] = "1.20"

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "1.5"




; Contrib (patched modules)
projects[apachesolr][subdir] = "contrib"
projects[apachesolr][version] = "2.0-beta2"
projects[apachesolr][patch][] = "http://drupal.org/files/issues/804700-apachesolr_search.module.patch"

projects[apachesolr_attachments][subdir] = "contrib"
projects[apachesolr_attachments][version] = "1.0-beta1"
projects[apachesolr_attachments][patch][] = "http://drupal.org/files/issues/812038-missing-argument.patch"
projects[apachesolr_attachments][patch][] = "http://drupal.org/files/issues/815104-reindex-failed-files.patch"
projects[apachesolr_attachments][patch][] = "http://drupal.org/files/issues/817066-fatal-error.patch"
projects[apachesolr_attachments][patch][] = "http://drupal.org/files/issues/apachesolr_attachments.admin_.inc-823854.patch"

projects[apachesolr_biblio][subdir] = "contrib"
projects[apachesolr_biblio][version] = "1"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/785370_features_integration.patch"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/apachesolr_biblio-821660_1.patch"

; @todo do we have some any uncommitted patches for biblio left?
projects[biblio][subdir] = "contrib"
projects[biblio][version] = "1.13"
projects[biblio][patch][] = "http://drupal.org/files/issues/biblio.access_patch.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/endnote8_export.escape_urls.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/biblio_filefield_paths.patch"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "1.0-alpha13"
projects[feeds][patch][] = "http://drupal.org/files/issues/FeedsDataProcessor.ExpireFix_0.patch"

projects[file_aliases][subdir] = "contrib"
projects[file_aliases][version] = "1.1"
projects[file_aliases][patch][] = "http://drupal.org/files/issues/file_alias_nodeFormDescription.patch"

projects[itweak_upload][subdir] = "contrib"
projects[itweak_upload][version] = "2.3"
projects[itweak_upload][patch][] = "http://scholar.svn.sourceforge.net/viewvc/scholar/trunk/sites/all/modules/contrib/itweak_upload/itweak_upload_dataPersistance.patch?revision=3654&content-type=text/plain"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.0-alpha1"
projects[jquery_update][patch][] = "http://drupal.org/files/issues/draggable-329797-3.patch"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.0-beta12"
projects[purl][patch][] = "http://drupal.org/files/issues/dynamic_modifier.Beta12.patch"

projects[spaces][subdir] = "contrib"
projects[spaces][version] = "2.0-beta6"
projects[spaces][patch][] = "http://drupal.org/files/issues/hook_spaces_types_alter.patch"
projects[spaces][patch][] = "http://drupal.org/files/issues/spaces.alter_customizers.patch"
projects[spaces][patch][] = "http://drupal.org/files/issues/spaces.saving_blk_customizer_as_default.patch"
projects[spaces][patch][] = "http://drupal.org/files/issues/spaces.static_call_fix_1.patch"

; Custom modules
projects[openscholar_features][location] = "http://openscholar.harvard.edu/scholar_software"
projects[openscholar_features][version] = "2.0-dev"

projects[openscholar_vsite][location] = "http://openscholar.harvard.edu/scholar_software"
projects[openscholar_vsite][version] = "2.0-dev"

projects[openscholar_scholar][location] = "http://openscholar.harvard.edu/scholar_software"
projects[openscholar_scholar][version] = "2.0-dev"

projects[openscholar_sitewide][location] = "http://openscholar.harvard.edu/scholar_software"
projects[openscholar_sitewide][version] = "2.0-dev"

; Open Atrium modules
projects[litecal][subdir] = "contrib"
projects[litecal][location] = "http://code.developmentseed.org/fserver"
projects[litecal][version] = "1.0-alpha2"


; Themes
projects[zen][version] = "1.0"
projects[zen][subdir] = "contrib"

projects[openscholar_themes][location] = "http://openscholar.harvard.edu/scholar_software"
projects[openscholar_themes][version] = "2.0-beta5"

; Libraries
projects[libraries][subdir] = "libraries"

; TinyMCE 3.2.7
libraries[tinymce][download][type] = "get"
libraries[tinymce][download][url] = "http://downloads.sourceforge.net/project/tinymce/TinyMCE/3.2.7/tinymce_3_2_7.zip"
libraries[tinymce][directory_name] = "tinymce"

; jQuery UI
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery-ui-1.7.2.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"
