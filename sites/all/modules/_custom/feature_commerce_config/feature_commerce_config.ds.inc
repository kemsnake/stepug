<?php
/**
 * @file
 * feature_commerce_config.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_commerce_config_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product_display|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product_display';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'product:field_field_product_photo',
      ),
      'right' => array(
        1 => 'field_category',
        2 => 'product:field_size',
        3 => 'product:field_color',
        4 => 'product:commerce_stock',
        5 => 'product:field_measurement',
        6 => 'product:field_country',
        7 => 'product:field_vendors',
        8 => 'field_product',
        9 => 'product:commerce_price',
      ),
      'footer' => array(
        10 => 'body',
      ),
    ),
    'fields' => array(
      'product:field_field_product_photo' => 'left',
      'field_category' => 'right',
      'product:field_size' => 'right',
      'product:field_color' => 'right',
      'product:commerce_stock' => 'right',
      'product:field_measurement' => 'right',
      'product:field_country' => 'right',
      'product:field_vendors' => 'right',
      'field_product' => 'right',
      'product:commerce_price' => 'right',
      'body' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|product_display|default'] = $ds_layout;

  return $export;
}
