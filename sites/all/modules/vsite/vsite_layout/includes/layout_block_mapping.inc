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


function _vsite_layout_calculate_layout($s_theme){
	$region_data_cache = cache_get("vsite_layout_".$s_theme."_layout_data");
	if(!$region_data_cache->data) return "No data found...";
	
  $a_rows = $a_columns = array();
  $n_min_width = false;
  foreach ($region_data_cache->data as $s_region => $a_loc_info){
    $a_rows[ floor($a_loc_info['top']/25) ][] = $s_region;
    $n_min_width = ($a_loc_info['width'] < $n_min_width || $n_min_width == false)? $a_loc_info['width']:$n_min_width;
  }
  
  foreach ($region_data_cache->data as $s_region => $a_loc_info){
    $a_columns[ floor($a_loc_info['left'] / ($n_min_width-1)) ][] = $s_region;
  }
  
  $a_new_columns; $a_prev; $n_prev;
  foreach ($a_columns as $n_offset => $a_regions){
    $b_add = true;
    if(count($a_new_columns) && ($n_offset - $n_prev)<=3 ){
      $n_left_offset = false;
      foreach(array_merge($a_regions,$a_prev) as $s_region){
        $n_curr_left_offset = floor(($region_data_cache->data[$s_region]['left']+$region_data_cache->data[$s_region]['width']) / ($n_min_width-1));
        if($n_left_offset === false) $n_left_offset = $n_curr_left_offset;
        if($n_left_offset != $n_curr_left_offset){
          $n_left_offset = false;
          break;
        }
      }
      if($n_left_offset){
        $a_new_columns[$n_prev] = array_merge($a_regions,$a_prev);
        $b_add = false;
      }
    }
    
    if($b_add) $a_new_columns[$n_offset] = $a_prev = $a_regions;
    $n_prev = $n_offset;
  }//Consolidate similar columns
  $a_columns = $a_new_columns;
  
  ksort($a_rows); ksort($a_columns);
  
  $a_col_widths = array_keys($a_columns);
  $a_row_height = array();
  $a_rows = array_values($a_rows);
  $a_columns = array_values($a_columns);
  
  $a_blocks = array();
  for ($i=0;$i<count($a_rows);$i++){
  	$a_row_height[$i] = 100;
    for ($j=0;$j<count($a_columns);$j++){
      $s_content = array_shift(array_intersect($a_rows[$i],$a_columns[$j]));
      if(!$s_content){
        $n_cols_left = 0;
        $s_left = false;
        while(($j - ++$n_cols_left) >=0 && !$s_left) $s_left = array_shift(array_intersect($a_rows[$i],$a_columns[$j-$n_cols_left]));
        
        if($s_left && floor(($region_data_cache->data[$s_left]['left'] + $region_data_cache->data[$s_left]['width'] - 10)/($n_min_width-1)) > $a_col_widths[$j] ){
          $a_blocks[$s_left]['width'] = $n_cols_left;
        }else{
          $n_rows_up = 0;
          while(($i - ++$n_rows_up) >=0 && !$s_content) $s_content = array_shift(array_intersect($a_rows[$i-$n_rows_up],$a_columns[$j]));
          
          if($s_content){
          	$a_blocks[$s_content]['height'] = $n_rows_up;
          }else{
          	$a_blocks["blank_$i_$j"] = array('width'=>1,'height'=>1);
          	$a_rows[$i][] = "blank_$i_$j";
          	$a_columns[$j][] = "blank_$i_$j";
          }
        }       
      }else{
        $a_blocks[$s_content] = array('width'=>1,'height'=>1);
        $n_curr_height = $region_data_cache->data[$s_content]['height'];
        $a_row_height[$i] = ($a_row_height[$i] < $n_curr_height)?$n_curr_height:$a_row_height[$i];
      }
    }
  }
  
  $a_widgets = _vsite_layout_get_current_widgets();
  $s_out = "<table id='vsite_layout_table'>";
  for ($i=0;$i<count($a_rows);$i++){
  	$n_height = min($a_row_height[$i],220);
    $s_out .= "<tr style='height:{$n_height}px'>";
    for ($j=0;$j<count($a_columns);$j++){
      $s_content = array_shift(array_intersect($a_rows[$i],$a_columns[$j]));
      if($s_content){
        $a_dim = $a_blocks[$s_content];
        $s_widgets = ($s_content == 'content_main')?"<p>Main Content Area</p>":$a_widgets[$s_content];
        if(!strlen($s_widgets)) $s_widgets = "<p>Unused</p>";
        $s_out .= "<td style='width:".(660/count($a_columns))."px' colspan=".$a_dim['width']." rowspan=".$a_dim['height'].">".$s_widgets."</td>";
      }
    }
    $s_out .= "</tr>";
  }
  $s_out .= "</table>";
  
  return $s_out;
	
}

/**
 * Get the themed widgets for each region
 * @return array
 */
function _vsite_layout_get_current_widgets(){
	$vars = array();
  $regions = array_keys(system_region_list('scholar_base'));

  $s_page_type =  (isset($_GET['page_type']))? $_GET['page_type']:'all';
  $a_feature_contexts = drupal_map_assoc(spaces_features_items('context', $s_page_type));
  
  $vsite_layout_widgets = vsite_layout_region_widgets(false,$s_page_type);

  foreach($regions as $region){
    $wgts_id = 'scholarlayout-' . str_replace('_','-', $region);
    $wgts = array_key_exists($region,$vsite_layout_widgets)?$vsite_layout_widgets[$region]:array();
    if($s_page_type == 'all') _check_for_overrides($wgts,$region);
    
    _check_for_disabled_widgets($wgts,$a_feature_contexts);
    $vars[$region] = theme('vsite_layout_layout_widgets',$wgts, $wgts_id, 'scholarlayout-widgets-list');
  }
  
  return $vars;
}