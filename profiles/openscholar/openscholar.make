core = "6.x"

; Contrib projects (non-Patched) 

projects[activity][subdir] = "contrib"
projects[activity][version] = "2.0-dev"

projects[addthis][subdir] = "contrib"
projects[addthis][version] = "2.9"

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "1"

projects[advanced_help][subdir] = "contrib"
projects[advanced_help][version] = "1.2"

projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = "1.2"

projects[calendar][subdir] = "contrib"
projects[calendar][version] = "2.2"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.6"

projects[content_profile][subdir] = "contrib"
projects[content_profile][version] = "1.0"

projects[context][subdir] = "contrib"
projects[context][version] = "2"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.3"

projects[data][subdir] = "contrib"
projects[data][version] = "1.0-alpha10"

projects[date][subdir] = "contrib"
projects[date][version] = "2.4"

projects[devel][subdir] = "contrib"
projects[devel][version] = "1"

projects[dialog][subdir] = "contrib"
projects[dialog][version] = "1"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.0"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0-beta5"

projects[filefield][subdir] = "contrib"
projects[filefield][version] = "3.2"

projects[filefield_paths][subdir] = "contrib"
projects[filefield_paths][version] = "1.4"

projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0-beta3"

projects[image_api][subdir] = "contrib"
projects[image_api][version] = "1.8"

projects[imagecache][subdir] = "contrib"
projects[imagecache][version] = "2.0-beta10"

projects[imagefield][subdir] = "contrib"
projects[imagefield][version] = "3.3"

projects[imagefield_crop][subdir] = "contrib"
projects[imagefield_crop][version] = "1.0-rc1"

projects[install_profile_api][subdir] = "contrib"
projects[install_profile_api][version] = "2"

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = "1"

projects[lightbox2][subdir] = "contrib"
projects[lightbox2][version] = "1"

projects[link][subdir] = "contrib"
projects[link][version] = "2.8"

projects[luceneapi][subdir] = "contrib"
projects[luceneapi][version] = "2.2"

projects[luceneapi_biblio][subdir] = "contrib"
projects[luceneapi_biblio][version] = "1"

projects[luceneapi_dym][subdir] = "contrib"
projects[luceneapi_dym][version] = "1.0-beta4"

projects[menu_node][subdir] = "contrib"
projects[menu_node][version] = "1.3"

projects[mollom][subdir] = "contrib"
projects[mollom][version] = "1.10"

projects[nodereference_url][subdir] = "contrib"
projects[nodereference_url][version] = "1.3"

projects[og][subdir] = "contrib"
projects[og][version] = "2.0"

projects[og_vocab][subdir] = "contrib"
projects[og_vocab][version] = "1.1"

projects[override_node_options][subdir] = "contrib"
projects[override_node_options][version] = "1"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.2"

projects[schema][subdir] = "contrib"
projects[schema][version] = "1.6"

projects[stringoverrides][subdir] = "contrib"
projects[stringoverrides][version] = "1.7"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "1.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "2.1"

projects[twitter_pull][subdir] = "contrib"
projects[twitter_pull][version] = "1.1"

projects[ucreate][subdir] = "contrib"
projects[ucreate][version] = "1.0-beta2"

projects[vertical_tabs][subdir] = "contrib"
projects[vertical_tabs][version] = "1.0-rc1"

projects[views][subdir] = "contrib"
projects[views][version] = "2.8"

projects[views_attach][subdir] = "contrib"
projects[views_attach][version] = "2.1"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "1.9"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.0"





; Contrib Modules Patched

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
projects[apachesolr_biblio][version] = "1.0-dev"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/785370_features_integration.patch"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/apachesolr_biblio-821660_1.patch"

projects[biblio][subdir] = "contrib"
projects[biblio][version] = "1.13"
projects[biblio][patch][] = ""

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "1.0-alpha13"
projects[feeds][patch][] = ""

projects[file_aliases][subdir] = "contrib"
projects[file_aliases][version] = "1.1"


projects[itweak_upload][subdir] = "contrib"
projects[itweak_upload][version] = "2"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.0-alpha1"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.0-beta4"

projects[spaces][subdir] = "contrib"
projects[spaces][version] = "2.0-beta6"

; http://drupal.org/node/694094
;projects[views][patch][] = "http://drupal.org/files/issues/694094_views_default_reset_2010-05-25.patch"
; original issue: http://drupal.org/node/357529
;projects[views][patch][] = "http://cloud.github.com/downloads/developmentseed/atrium_features/views2_simple_translatables.patch"



; Custom modules


; Open Atrium modules
projects[litecal][subdir] = "contrib"
projects[litecal][location] = "http://code.developmentseed.org/fserver"
projects[litecal][version] = "1.0-alpha2"


; Features
; projects[atrium_features][location] = "http://code.developmentseed.org/fserver"
; projects[atrium_features][version] = "1.0-alpha4"
projects[atrium_features][type] = "module"
projects[atrium_features][download][type] = "git"
projects[atrium_features][download][url] = "git://github.com/developmentseed/atrium_features.git"



; Themes
projects[tao][location] = "http://code.developmentseed.org/fserver"
projects[tao][version] = "1.9"

projects[rubik][location] = "http://code.developmentseed.org/fserver"
projects[rubik][version] = "1.0-beta6"

projects[ginkgo][location] = "http://code.developmentseed.org/fserver"
projects[ginkgo][version] = "1.0-alpha4"

; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

; Translations for openscholar install profile
