<?php
/**
 * @file
 * feature_commerce_config.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function feature_commerce_config_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'commerce_product_importer_hooby-price-math';
  $feeds_tamper->importer = 'commerce_product_importer_hooby';
  $feeds_tamper->source = 'price';
  $feeds_tamper->plugin_id = 'math';
  $feeds_tamper->settings = array(
    'operation' => 'multiplication',
    'value' => '100',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Mathematical operation';
  $export['commerce_product_importer_hooby-price-math'] = $feeds_tamper;

  return $export;
}
