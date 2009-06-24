<?php
// $Id: iqssbook.tpl.php,v 1.1 2008/12/23 15:35:46 falimadh Exp $

/**
 * @file iqssbook-export-iqss.tpl.php
 * Default theme implementation for printed version of book outline.
 *
 * Available variables:
 * - $title: Top level node title.
 * - $content: Nodes within the current outline rendered through
 *   book-node-export-html.tpl.php.
 *
 * @see template_preprocess_iqssbook_export_iqss()
 */
?>

    <div class="topic_display">
      <div id="col1">
        <?php for ($i = 1; $i < $depth; $i++) : ?>
        <div class="section-<?php print $i; ?>">
        </div>
        <?php endfor; ?>

        <?php print $contents; ?>
        <?php print $div_close; ?>
      </div>
      <div id="col2"> </div>
    </div>
    
    
    
    


