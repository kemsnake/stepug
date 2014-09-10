<?php
/**
 * @file
 * feature_commerce_config.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_commerce_config_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['commerce_ajax_basket_link-commerce_ajax_basket_link'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'commerce_ajax_basket_link',
    'module' => 'commerce_ajax_basket_link',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'stepug' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'stepug',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['commerce_cart-cart'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'cart',
    'module' => 'commerce_cart',
    'node_types' => array(),
    'pages' => 'checkout*
cart*',
    'roles' => array(),
    'themes' => array(
      'omega' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'stepug' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'stepug',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
