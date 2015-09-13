<?php

/**
 * Implements hook_preprocess_page().
 */
function stepug_preprocess_page(&$variables) {
  // You can use preprocess hooks to modify the variables before they are passed
  // to the theme function or template file.
}

function stepug_preprocess_html(&$variables) {
  drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans&subset=latin,cyrillic-ext', array('type' => 'external'));
}
