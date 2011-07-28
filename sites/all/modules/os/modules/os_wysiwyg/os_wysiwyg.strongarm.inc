<?php

/**
 * Implementation of hook_strongarm().
 */
function os_wysiwyg_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_per_node_type';
  $strongarm->value = 1;

  $export['better_formats_per_node_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embedfilter_filtertip';
  $strongarm->value = 'You can use &lt;object>, &lt;embed> and &lt;script> tags from the following sites to add media to your posts. You must disable the rich text editor for this to work.';

  $export['embedfilter_filtertip'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embedfilter_host_whitelist';
  $strongarm->value = 'localhost
youtube.com
flicker.com
twitter.com
facebook.com
google.com
yahoo.com
thedailyshow.com
mtvnservices.com';

  $export['embedfilter_host_whitelist'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_default_format';
  $strongarm->value = '1';

  $export['filter_default_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_html_1';
  $strongarm->value = '1';

  $export['filter_html_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_html_help_1';
  $strongarm->value = 1;

  $export['filter_html_help_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_html_nofollow_1';
  $strongarm->value = 0;

  $export['filter_html_nofollow_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'format';
  $strongarm->value = '1';

  $export['format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxheight_1';
  $strongarm->value = '';

  $export['oembed_maxheight_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxheight_2';
  $strongarm->value = '';

  $export['oembed_maxheight_2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxwidth_1';
  $strongarm->value = '440';

  $export['oembed_maxwidth_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxwidth_2';
  $strongarm->value = '440';

  $export['oembed_maxwidth_2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_parsed_1';
  $strongarm->value = array(
    'a' => array(
      'href' => array(
        'required' => TRUE,
      ),
      'target' => array(
        'values' => array(
          0 => '_blank',
        ),
      ),
      'title' => array(),
      'id' => array(),
      'class' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'b' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'blockquote' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'br' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'cite' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'code' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'dd' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'div' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'dl' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'dt' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'em' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'embed' => array(
      '*' => array(),
    ),
    'i' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'img' => array(
      'src' => array(
        'required' => TRUE,
      ),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'li' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'object' => array(
      '*' => array(),
    ),
    'ol' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'p' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'param' => array(
      '*' => array(),
    ),
    'script' => array(
      'src' => array(),
      'type' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'span' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'strike' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'strong' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'u' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'ul' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
  );

  $export['wysiwyg_filter_valid_elements_parsed_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_parsed_6';
  $strongarm->value = array(
    'a' => array(
      'href' => array(
        'required' => TRUE,
      ),
      'target' => array(
        'values' => array(
          0 => '_blank',
        ),
      ),
      'title' => array(),
    ),
    'blockquote' => array(),
    'br' => array(),
    'cite' => array(),
    'code' => array(),
    'dd' => array(),
    'div' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
    ),
    'dl' => array(),
    'dt' => array(),
    'em' => array(),
    'embed' => array(
      '*' => array(),
    ),
    'img' => array(
      'src' => array(
        'required' => TRUE,
      ),
    ),
    'li' => array(),
    'object' => array(
      '*' => array(),
    ),
    'ol' => array(),
    'p' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
    ),
    'param' => array(
      '*' => array(),
    ),
    'script' => array(
      'src' => array(),
      'type' => array(),
    ),
    'span' => array(),
    'strong' => array(),
    'ul' => array(),
  );

  $export['wysiwyg_filter_valid_elements_parsed_6'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_1';
  $strongarm->value = '@[id|class|title|dir<ltr?rtl|lang],
a[!href|target<_blank|title],
div[align<center?justify?left?right],
p[align<center?justify?left?right],
br,span,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,img[!src],embed[*],object[*],param[*],script[src|type],
strong/b,em/i,strike,u';

  $export['wysiwyg_filter_valid_elements_raw_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_6';
  $strongarm->value = 'a[!href|target<_blank|title],
div[align<center?justify?left?right],
p[align<center?justify?left?right],
br,span,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,img[!src],embed[*],object[*],param[*],script[src|type]';

  $export['wysiwyg_filter_valid_elements_raw_6'] = $strongarm;
  return $export;
}
