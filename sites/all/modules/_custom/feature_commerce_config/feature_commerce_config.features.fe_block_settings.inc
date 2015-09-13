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
        'weight' => -16,
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

  $export['search_api_page-product_search'] = array(
    'cache' => 5,
    'custom' => 0,
    'delta' => 'product_search',
    'module' => 'search_api_page',
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
        'region' => '',
        'status' => 0,
        'theme' => 'stepug',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-popular_products-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'popular_products-block_1',
    'module' => 'views',
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
        'region' => '',
        'status' => 0,
        'theme' => 'stepug',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-popular_products-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'popular_products-block_2',
    'module' => 'views',
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
        'region' => '',
        'status' => 0,
        'theme' => 'stepug',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-recently_viewed_product-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'recently_viewed_product-block_1',
    'module' => 'views',
    'node_types' => array(
      0 => 'product_display',
    ),
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'stepug',
        'weight' => -18,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-recently_viewed_product-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'recently_viewed_product-block_2',
    'module' => 'views',
    'node_types' => array(
      0 => 'article',
      1 => 'page',
      2 => 'webform',
    ),
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
        'region' => '',
        'status' => 0,
        'theme' => 'stepug',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
