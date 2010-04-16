<?

function vsite_layout_render_map(){
  global $custom_theme;
  
  drupal_add_js(drupal_get_path('module','vsite_layout')."/theme/vsite_layout_gather_theme_data.js");
  drupal_add_js(array('scholarlayoutGatherThemeData' => array(
    'theme_name' => $custom_theme,
    'theme_data_path' => url('cp/vsite_layout_cache_theme_data_js',array('absolute' => true)),
  )),'setting');
  cache_clear_all("vsite_layout_{$custom_theme}_layout_data","cache");
  
  return "<h3>Gathering Layout Data</h3>";
}

function vsite_layout_cache_theme_data_js(){
  $s_theme = $_POST['theme'];
  $a_cache = cache_get("vsite_layout_{$s_theme}_layout_data");
  $a_layout_data = $a_cache->data;
  
  if(!$a_layout_data) $a_layout_data = array();
  
  $a_layout_data[$_POST['name']] = array("top" => intval($_POST['top']), "left" => intval($_POST['left']), "width" => intval($_POST['width']), "height" => intval($_POST['height']));
  
  cache_set("vsite_layout_{$s_theme}_layout_data",$a_layout_data);
  
  print json_encode($_POST['name']);
  return;
}

/**
 * A block for every region when we are calculating mapping data
 * 
 * @param $contexts
 */
function vsite_layout_alter_context_for_block_mapping(&$contexts){
	if(arg(0) != "layout_get_mapping_data") return; //Just do this when gathering mapping data
	
	$a_required_regions = array("header_left","header_main", "header_right", "navbar", "left", "right");
	
	foreach ($contexts as $context){
		foreach ($context->block as $block){
			$a_data = call_user_func($block['module']."_block",'view',$block['delta']);
			if(!strlen($a_data['content'])) continue;
			
			$a_required_regions = array_diff($a_required_regions,array($block['region']));
			if(!count($a_required_regions)) break(2);
		}
	}
	
	$delta = 10;
	foreach ($a_required_regions as $s_empty_region){
		$contexts['vsite-section-public']->block[] = array(
		  'module' => 'vsite_widgets',
		  'delta' => $delta,
		  'weight' => 0,
		  'region' => $s_empty_region,
		  'status' => 0,
		  'label' => "Default Content",
		  'type' => "context_ui"
		);
		$delta++;
	}
	
}