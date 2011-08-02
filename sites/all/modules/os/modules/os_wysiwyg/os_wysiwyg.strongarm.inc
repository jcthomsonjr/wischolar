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
  $strongarm->value = '6';

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
  $strongarm->name = 'wysiwyg_filter_styles_box_1';
  $strongarm->value = array(
    'padding-left' => 'padding-left',
    'margin' => 0,
    'margin-top' => 0,
    'margin-right' => 0,
    'margin-bottom' => 0,
    'margin-left' => 0,
    'padding' => 0,
    'padding-top' => 0,
    'padding-right' => 0,
    'padding-bottom' => 0,
  );

  $export['wysiwyg_filter_styles_box_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_box_5';
  $strongarm->value = array(
    'padding-left' => 'padding-left',
    'margin' => 0,
    'margin-top' => 0,
    'margin-right' => 0,
    'margin-bottom' => 0,
    'margin-left' => 0,
    'padding' => 0,
    'padding-top' => 0,
    'padding-right' => 0,
    'padding-bottom' => 0,
  );

  $export['wysiwyg_filter_styles_box_5'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_box_6';
  $strongarm->value = array(
    'margin' => 0,
    'margin-top' => 0,
    'margin-right' => 0,
    'margin-bottom' => 0,
    'margin-left' => 0,
    'padding' => 0,
    'padding-top' => 0,
    'padding-right' => 0,
    'padding-bottom' => 0,
    'padding-left' => 0,
  );

  $export['wysiwyg_filter_styles_box_6'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_dimension_1';
  $strongarm->value = array(
    'width' => 'width',
    'height' => 0,
    'line-height' => 0,
    'max-height' => 0,
    'max-width' => 0,
    'min-height' => 0,
    'min-width' => 0,
  );

  $export['wysiwyg_filter_styles_dimension_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_dimension_5';
  $strongarm->value = array(
    'width' => 'width',
    'height' => 0,
    'line-height' => 0,
    'max-height' => 0,
    'max-width' => 0,
    'min-height' => 0,
    'min-width' => 0,
  );

  $export['wysiwyg_filter_styles_dimension_5'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_dimension_6';
  $strongarm->value = array(
    'width' => 'width',
    'height' => 0,
    'line-height' => 0,
    'max-height' => 0,
    'max-width' => 0,
    'min-height' => 0,
    'min-width' => 0,
  );

  $export['wysiwyg_filter_styles_dimension_6'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_font_1';
  $strongarm->value = array(
    'font' => 'font',
    'font-family' => 'font-family',
    'font-size' => 'font-size',
    'font-size-adjust' => 0,
    'font-stretch' => 0,
    'font-style' => 0,
    'font-variant' => 0,
    'font-weight' => 0,
  );

  $export['wysiwyg_filter_styles_font_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_font_5';
  $strongarm->value = array(
    'font' => 'font',
    'font-family' => 'font-family',
    'font-size' => 'font-size',
    'font-weight' => 'font-weight',
    'font-size-adjust' => 0,
    'font-stretch' => 0,
    'font-style' => 0,
    'font-variant' => 0,
  );

  $export['wysiwyg_filter_styles_font_5'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_font_6';
  $strongarm->value = array(
    'font' => 'font',
    'font-family' => 'font-family',
    'font-size' => 'font-size',
    'font-style' => 'font-style',
    'font-size-adjust' => 0,
    'font-stretch' => 0,
    'font-variant' => 0,
    'font-weight' => 0,
  );

  $export['wysiwyg_filter_styles_font_6'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_text_1';
  $strongarm->value = array(
    'text-align' => 'text-align',
    'text-decoration' => 'text-decoration',
    'text-indent' => 'text-indent',
    'text-transform' => 0,
    'letter-spacing' => 0,
    'word-spacing' => 0,
    'white-space' => 0,
    'direction' => 0,
    'unicode-bidi' => 0,
  );

  $export['wysiwyg_filter_styles_text_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_text_5';
  $strongarm->value = array(
    'text-align' => 'text-align',
    'text-decoration' => 'text-decoration',
    'text-indent' => 'text-indent',
    'text-transform' => 0,
    'letter-spacing' => 0,
    'word-spacing' => 0,
    'white-space' => 0,
    'direction' => 0,
    'unicode-bidi' => 0,
  );

  $export['wysiwyg_filter_styles_text_5'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_text_6';
  $strongarm->value = array(
    'text-align' => 'text-align',
    'text-decoration' => 'text-decoration',
    'text-indent' => 0,
    'text-transform' => 0,
    'letter-spacing' => 0,
    'word-spacing' => 0,
    'white-space' => 0,
    'direction' => 0,
    'unicode-bidi' => 0,
  );

  $export['wysiwyg_filter_styles_text_6'] = $strongarm;
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
    'caption' => array(
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
      'style' => array(),
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
      'style' => array(),
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
      'style' => array(),
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
    'sub' => array(
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
    'sup' => array(
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
    'table' => array(
      'style' => array(),
      'border' => array(),
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'left',
          2 => 'right',
        ),
      ),
      'cellpadding' => array(),
      'cellspacing' => array(),
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
    'td' => array(
      'colspan' => array(),
      'rowspan' => array(),
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
    'tr' => array(
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
  $strongarm->name = 'wysiwyg_filter_valid_elements_parsed_5';
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
      'style' => array(),
    ),
    'dl' => array(),
    'dt' => array(),
    'em' => array(),
    'li' => array(),
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
      'style' => array(),
    ),
    'span' => array(
      'id' => array(),
      'style' => array(),
    ),
    'strong' => array(),
    'ul' => array(),
  );

  $export['wysiwyg_filter_valid_elements_parsed_5'] = $strongarm;
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
    'address' => array(),
    'blockquote' => array(),
    'br' => array(),
    'caption' => array(),
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
      'style' => array(),
    ),
    'dl' => array(),
    'dt' => array(),
    'em' => array(),
    'embed' => array(
      '*' => array(),
    ),
    'h2' => array(),
    'h3' => array(),
    'h4' => array(),
    'h5' => array(),
    'h6' => array(),
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
      'style' => array(),
    ),
    'param' => array(
      '*' => array(),
    ),
    'pre' => array(),
    'script' => array(
      'src' => array(),
      'type' => array(),
    ),
    'span' => array(
      'id' => array(),
      'style' => array(),
    ),
    'strong' => array(),
    'sub' => array(),
    'sup' => array(),
    'table' => array(
      'style' => array(),
      'border' => array(),
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'left',
          2 => 'right',
        ),
      ),
      'cellpadding' => array(),
      'cellspacing' => array(),
    ),
    'td' => array(
      'colspan' => array(),
      'rowspan' => array(),
    ),
    'tr' => array(),
    'ul' => array(),
  );

  $export['wysiwyg_filter_valid_elements_parsed_6'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_1';
  $strongarm->value = '@[id|class|title|dir<ltr?rtl|lang],
a[!href|target<_blank|title],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
br,span[id|style],cite,code,blockquote,ul,ol,li,dl,dt,dd,img[!src],embed[*],object[*],param[*],script[src|type],
sup,sub,
table[style|border|align<center?left?right|cellpadding|cellspacing],tr,td[colspan|rowspan],caption,
strong/b,em/i,strike,u';

  $export['wysiwyg_filter_valid_elements_raw_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_5';
  $strongarm->value = 'a[!href|target<_blank|title],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
br,span[id|style],em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd';

  $export['wysiwyg_filter_valid_elements_raw_5'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_6';
  $strongarm->value = 'a[!href|target<_blank|title],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
br,span[id|style],em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,img[!src],embed[*],object[*],param[*],script[src|type],
sup,sub,
table[style|border|align<center?left?right|cellpadding|cellspacing],tr,td[colspan|rowspan],caption,
address,h2,h3,h4,h5,h6,pre';

  $export['wysiwyg_filter_valid_elements_raw_6'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_ids_1';
  $strongarm->value = array(
    0 => 'mce*',
  );

  $export['wysiwyg_filter_valid_ids_1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_ids_5';
  $strongarm->value = array();

  $export['wysiwyg_filter_valid_ids_5'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_ids_6';
  $strongarm->value = array(
    0 => 'mce*',
  );

  $export['wysiwyg_filter_valid_ids_6'] = $strongarm;
  return $export;
}
