<?php
/**
 * @file
 * feature_commerce_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_commerce_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_commerce_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_commerce_config_image_default_styles() {
  $styles = array();

  // Exported image style: product_image_big.
  $styles['product_image_big'] = array(
    'label' => 'Product image big',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1024,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: product_image_small.
  $styles['product_image_small'] = array(
    'label' => 'Product image small',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 180,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_search_api_index().
 */
function feature_commerce_config_default_search_api_index() {
  $items = array();
  $items['products'] = entity_import('search_api_index', '{
    "name" : "Products",
    "machine_name" : "products",
    "description" : null,
    "server" : "main_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "product_display" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_category:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_category:parent:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_product:field_color:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_product:field_country:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_product:field_size" : { "type" : "list\\u003Ctext\\u003E" },
        "field_product:field_vendors:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_product:sku" : { "type" : "list\\u003Ctext\\u003E" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "3.0" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_category:parent" : "field_category:parent" } }
        },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : {
              "title" : true,
              "field_product:sku" : true,
              "field_product:field_size" : true,
              "field_category:name" : true,
              "field_product:field_color:name" : true,
              "field_product:field_country:name" : true,
              "field_product:field_vendors:name" : true,
              "field_category:parent:name" : true
            }
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "-49",
          "settings" : { "fields" : {
              "title" : true,
              "field_product:sku" : true,
              "field_product:field_size" : true,
              "field_category:name" : true,
              "field_product:field_color:name" : true,
              "field_product:field_country:name" : true,
              "field_product:field_vendors:name" : true,
              "field_category:parent:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "-48",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_product:sku" : true,
              "field_product:field_size" : true,
              "field_category:name" : true,
              "field_product:field_color:name" : true,
              "field_product:field_country:name" : true,
              "field_product:field_vendors:name" : true,
              "field_category:parent:name" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "-47",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_product:sku" : true,
              "field_product:field_size" : true,
              "field_category:name" : true,
              "field_product:field_color:name" : true,
              "field_product:field_country:name" : true,
              "field_product:field_vendors:name" : true,
              "field_category:parent:name" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "-46",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_product:sku" : true,
              "field_product:field_size" : true,
              "field_category:name" : true,
              "field_product:field_color:name" : true,
              "field_product:field_country:name" : true,
              "field_product:field_vendors:name" : true,
              "field_category:parent:name" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "-45",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        },
        "search_api_russian_stemmer" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_product:sku" : true,
              "field_product:field_size" : true,
              "field_category:name" : true,
              "field_product:field_color:name" : true,
              "field_product:field_country:name" : true,
              "field_product:field_vendors:name" : true,
              "field_category:parent:name" : true
            }
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function feature_commerce_config_default_search_api_page() {
  $items = array();
  $items['product_search'] = entity_import('search_api_page', '{
    "index_id" : "products",
    "path" : "search",
    "name" : "Product search",
    "machine_name" : "product_search",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : 16,
      "result_page_search_form" : 0,
      "get_per_page" : 1,
      "view_mode" : "search_api_page_result",
      "language_filter" : [],
      "empty_behavior" : ""
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function feature_commerce_config_default_search_api_server() {
  $items = array();
  $items['main_server'] = entity_import('search_api_server', '{
    "name" : "Main server",
    "machine_name" : "main_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 1,
      "autocomplete" : { "suggest_suffix" : 1, "suggest_words" : 1 },
      "indexes" : { "products" : {
          "nid" : {
            "table" : "search_api_db_products",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_products_text",
            "type" : "text",
            "boost" : "3.0"
          },
          "url" : {
            "table" : "search_api_db_products",
            "column" : "url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_products",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product:sku" : {
            "table" : "search_api_db_products_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_size" : {
            "table" : "search_api_db_products_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_category:name" : {
            "table" : "search_api_db_products_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "2.0"
          },
          "field_product:field_color:name" : {
            "table" : "search_api_db_products_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_country:name" : {
            "table" : "search_api_db_products_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_vendors:name" : {
            "table" : "search_api_db_products_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_category:parent:name" : {
            "table" : "search_api_db_products_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
