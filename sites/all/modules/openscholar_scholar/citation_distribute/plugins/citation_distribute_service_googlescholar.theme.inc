<?php

/**
 * Themable function to generate message after user submits
 *  cite_distribute widget selections
 *
 * @param unknown_type $modules
 * @return unknown
 */
function theme_googlescholar($metadata){
	$output = "";
	foreach($metadata as $key => $value) {
		if ($value) {
			$output .= '<meta name="' . $key . '" content="' . $value . '" />' . "\n";
		}
	}
  return $output;
}