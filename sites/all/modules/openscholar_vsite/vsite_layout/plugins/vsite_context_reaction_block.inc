<?php

/**
 * Expose blocks as context reactions.
 */
class vsite_context_reaction_block extends context_reaction_block {

  /**
   * Determine whether inline editing requirements are met and that the current
   * user may edit.
   */
  protected function is_editable($reset = FALSE) {
  	//Hardcoded to flase for now
    return (parent::is_editable($reset) && user_access('vsite_edit_contex_blocks') && false);
  }

}
