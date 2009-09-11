/**
 * Provide the HTML to create the modal dialog.
 */
Drupal.theme.CToolsModalDialog = function () {
  var html = ''
  html += '  <div id="ctools-modal">'
  html += '    <div class="ctools-modal-content">' // panels-modal-content
  html += '      <div class="modal-header">';
  html += '        <h3 id="modal-title" class="modal-title">&nbsp;</h3>';
  html += '      </div>';
  html += '      <div id="modal-content" class="modal-content">';
  html += '      </div>';
  html += '    </div>';
  html += '    <div id="ctools-left"></div>';
  html += '    <div id="ctools-bottom"></div>';
  html += '    <div id="ctools-right"></div>';
  html += '        <a class="close" href="#">';
  html +=            Drupal.settings.CToolsModal.closeText + Drupal.settings.CToolsModal.closeImage;
  html += '        </a>';
  html += '  </div>';

  return html;
}