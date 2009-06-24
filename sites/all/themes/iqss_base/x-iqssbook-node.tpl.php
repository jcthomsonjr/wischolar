<?php
// $Id: iqssbook-node.tpl.php,v 1.1 2008/12/23 15:35:46 falimadh Exp $

/**
 * @file iqssbook-node-export-iqss.tpl.php
 * Default theme implementation for rendering a single node 
 * in the iqss book display
 *
 * @see iqssbook-node-export-iqss.tpl.php
 * Where it is collected and printed out.
 *
 * Available variables:
 * - $depth: Depth of the current node inside the outline.
 * - $title: Node title.
 * - $url: node link
 * - $content: Node content.
 * - $children: All the child nodes recursively rendered through this file.
 *
 * @see template_preprocess_iqssbook_node_export_iqss()
 * 
 * NOTE: Dont change class "ddcontent" below. Javascript code depends on it
 */
?>

<dl id="node-<?php print $node->nid; ?>" class="section-<?php print $depth;?>-booktree">
 <dt class="book-heading booktree"><?php print $url; ?><span class="small-links"><?php print $addchildlink?></span></dt>
  <dd>
    <div class="ddcontent">
      <?php print $content; ?>
        </div>
      <?php print $children; ?>
      
  </dd>
</dl>
