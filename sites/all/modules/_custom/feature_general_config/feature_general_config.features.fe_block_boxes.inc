<?php
/**
 * @file
 * feature_general_config.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_general_config_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer info';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_info';
  $fe_block_boxes->body = '<p style="text-align: center;">По всем интересующим вас вопросам вы можете обратиться по адресу</p><p style="text-align: center;">info@stepug.ru</p>';

  $export['footer_info'] = $fe_block_boxes;

  return $export;
}
