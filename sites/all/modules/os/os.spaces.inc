<?php

/**
 * Implementation of hook_spaces_presets().
 */
function os_spaces_presets() {
  $export = array();
  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'scholar';
  $spaces_presets->title = 'OS personal';
  $spaces_presets->description = 'OpenScholar personal site';
  $spaces_presets->space_type = 'og';
  $spaces_presets->value = array(
    'variable' => array(
      'spaces_features' => array(
        'scholar_announcements' => 0,
        'scholar_publications' => 2,
        'scholar_front' => 2,
        'scholar_biocv' => 2,
        'scholar_classes' => 2,
        'scholar_pages' => 2,
        'scholar_image_gallery' => 0,
        'scholar_reader' => 0,
        'scholar_announcements' => 0,
        'scholar_blog' => 0,
        'scholar_dvn' => 0,
        'scholar_links' => 0,
        'scholar_software' => 0
      ),
      'spaces_og_selective' => 0,
      'spaces_og_register' => 1,
      'spaces_og_directory' => 1,
      'spaces_og_private' => 0,
      'site_frontpage' => 'home',
      'site_frontpage_path' => 'home',
      'default_theme' => 'scholar_airstream',
    ),
    'vsite_menu' => array(
      'features' => array(
        'features:presentations' => array(
          'menu_name' => 'features',
          'link_path' => 'presentations',
          'router_path' => 'presentations',
          'link_title' => 'Presentations',
          'options' => array(
            'attributes' => array(
              'title' => 'List of presentations on my site',
            ),
          ),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '10',
        ),
        'features:software' => array(
          'menu_name' => 'features',
          'link_path' => 'software',
          'router_path' => 'software',
          'link_title' => 'Software',
          'options' => array(),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '12',
        ),
        'features:publications' => array(
          'menu_name' => 'features',
          'link_path' => 'publications',
          'router_path' => 'publications',
          'link_title' => 'Publications',
          'options' => array(),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '1',
          'expanded' => '0',
          'weight' => '11',
        ),
        'features:links' => array(
          'menu_name' => 'features',
          'link_path' => 'links',
          'router_path' => 'links',
          'link_title' => 'Links',
          'options' => array(
            'attributes' => array(
              'title' => 'List of links in my site',
            ),
          ),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '8',
        ),
        'features:classes' => array(
          'menu_name' => 'features',
          'link_path' => 'classes',
          'router_path' => 'classes',
          'link_title' => 'Classes',
          'options' => array(
            'attributes' => array(
              'title' => 'my images',
            ),
          ),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '4',
        ),
        'features:data' => array(
          'menu_name' => 'features',
          'link_path' => 'data',
          'router_path' => 'data',
          'link_title' => 'Dataverse',
          'options' => array(),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '1',
        ),
        'features:people' => array(
          'menu_name' => 'features',
          'link_path' => 'people',
          'router_path' => 'people',
          'link_title' => 'People',
          'options' => array(
            'attributes' => array(
              'title' => 'List of profiles',
            ),
          ),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '9',
        ),
        'features:images' => array(
          'menu_name' => 'features',
          'link_path' => 'images',
          'router_path' => 'images',
          'link_title' => 'Images',
          'options' => array(
            'attributes' => array(
              'title' => 'my images',
            ),
          ),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '7',
        ),
        'features:documents' => array(
          'menu_name' => 'features',
          'link_path' => 'documents',
          'router_path' => 'documents',
          'link_title' => 'Documents',
          'options' => array(
            'attributes' => array(
              'title' => 'list of documents',
            ),
          ),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '5',
        ),
        'features:blog' => array(
          'menu_name' => 'features',
          'link_path' => 'blog',
          'router_path' => 'blog',
          'link_title' => 'Blog',
          'options' => array(),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '3',
        ),
        'features:biocv' => array(
          'menu_name' => 'features',
          'link_path' => 'biocv',
          'router_path' => 'biocv',
          'link_title' => 'Bio',
          'options' => array(),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '2',
        ),
        'features:announcements' => array(
          'menu_name' => 'features',
          'link_path' => 'announcements',
          'router_path' => 'announcements',
          'link_title' => 'Announcements',
          'options' => array(
            'attributes' => array(
              'title' => 'List of announcements in my site',
            ),
          ),
          'module' => 'system',
          'hidden' => '0',
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '0',
        ),
        'features:reader' => array(
          'menu_name' => 'features',
          'link_path' => 'reader',
          'router_path' => 'reader',
          'link_title' => 'Feeds',
          'options' => array(
            'attributes' => array(
              'title' => 'Feed reader',
            ),
          ),
          'module' => 'system',
          'hidden' => 0,
          'external' => '0',
          'has_children' => '0',
          'expanded' => '0',
          'weight' => '6',
        ),
      ),
      'none' => array(),
      'scholar_secondary_menu' => array(),
    )
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('OS personal');
  t('OpenScholar personal site');

  $export['scholar'] = $spaces_presets;
  return $export;
}
