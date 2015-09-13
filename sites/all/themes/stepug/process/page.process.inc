<?php

/**
 * Implements hook_process_page().
 */
function stepug_process_page(&$variables) {
  if (arg(0) == 'search' ) {
    $variables['title'] = 'Результаты поиска по запросу "' . arg(1) . '"';
  }
}
