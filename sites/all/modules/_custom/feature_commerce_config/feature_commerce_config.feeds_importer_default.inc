<?php
/**
 * @file
 * feature_commerce_config.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feature_commerce_config_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'commecrce_product_importer';
  $feeds_importer->config = array(
    'name' => 'Commecrce product importer',
    'description' => 'Импортруем товары из внешнего файла',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'product',
        'author' => '35',
        'tax_rate' => '',
        'mappings' => array(
          0 => array(
            'source' => 'Артикул',
            'target' => 'sku',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Наименование',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Цена',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Единица измерения фасовки',
            'target' => 'field_measurement',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Изображение',
            'target' => 'field_field_product_photo',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'product',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['commecrce_product_importer'] = $feeds_importer;

  return $export;
}
