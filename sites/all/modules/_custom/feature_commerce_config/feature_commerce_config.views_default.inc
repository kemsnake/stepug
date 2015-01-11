<?php
/**
 * @file
 * feature_commerce_config.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_commerce_config_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Отчет о товарах';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Отчет о товарах';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_field_product_photo' => 'field_field_product_photo',
    'sku' => 'sku',
    'field_category' => 'field_category',
    'commerce_price' => 'commerce_price',
    'commerce_price_1' => 'commerce_price_1',
    'commerce_stock' => 'commerce_stock',
    'expression' => 'expression',
    'operations' => 'operations',
    'product_id' => 'product_id',
  );
  $handler->display->display_options['style_options']['default'] = 'sku';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_field_product_photo' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'sku' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'COUNT' => 'COUNT',
      ),
    ),
    'field_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'commerce_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(
        'AVG' => 'AVG',
      ),
    ),
    'commerce_price_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(
        'AVG' => 'AVG',
      ),
    ),
    'commerce_stock' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'product_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* Relationship: Commerce Товар: Referencing Содержимое */
  $handler->display->display_options['relationships']['field_product']['id'] = 'field_product';
  $handler->display->display_options['relationships']['field_product']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_product']['field'] = 'field_product';
  $handler->display->display_options['relationships']['field_product']['required'] = TRUE;
  /* Поле: Commerce Товар: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Поле: Commerce Товар: Фото */
  $handler->display->display_options['fields']['field_field_product_photo']['id'] = 'field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['table'] = 'field_data_field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['field'] = 'field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_field_product_photo']['settings'] = array(
    'image_style' => 'product_image_small',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_field_product_photo']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_field_product_photo']['delta_offset'] = '0';
  /* Поле: Commerce Товар: Артикул */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Поле: Содержимое: Категория */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['relationship'] = 'field_product';
  /* Поле: Commerce Товар: Цена */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['alter']['text'] = '[commerce_price-data]/100';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  $handler->display->display_options['fields']['commerce_price']['group_column'] = 'data';
  /* Поле: Commerce Товар: Цена */
  $handler->display->display_options['fields']['commerce_price_1']['id'] = 'commerce_price_1';
  $handler->display->display_options['fields']['commerce_price_1']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price_1']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price_1']['label'] = 'Цена для расчета';
  $handler->display->display_options['fields']['commerce_price_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_price_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price_1']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price_1']['type'] = 'commerce_price_raw_amount';
  $handler->display->display_options['fields']['commerce_price_1']['settings'] = array(
    'calculation' => '0',
  );
  /* Поле: Commerce Товар: В наличии */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_stock']['label'] = 'Количество';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['expression']['label'] = 'Стоимость товара';
  $handler->display->display_options['fields']['expression']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = ' ';
  $handler->display->display_options['fields']['expression']['expression'] = '[commerce_stock]*[commerce_price_1]/100';
  /* Поле: Commerce Товар: Ссылки операций */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Операции';
  $handler->display->display_options['fields']['operations']['add_destination'] = 0;
  /* Поле: Commerce Товар: ID товара */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['label'] = '';
  $handler->display->display_options['fields']['product_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['product_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['product_id']['link_to_product'] = 0;
  /* Filter criterion: Commerce Товар: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/product-report';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Отчет о товарах';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: XLS Export */
  $handler = $view->new_display('views_data_export', 'XLS Export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['style_options']['encoding'] = 'windows-1251';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Commerce Товар: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Поле: Commerce Товар: Артикул */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Поле: Содержимое: Категория */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['relationship'] = 'field_product';
  /* Поле: Commerce Товар: Цена */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['alter']['text'] = '[commerce_price-data]/100';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  $handler->display->display_options['fields']['commerce_price']['group_column'] = 'data';
  /* Поле: Commerce Товар: Цена */
  $handler->display->display_options['fields']['commerce_price_1']['id'] = 'commerce_price_1';
  $handler->display->display_options['fields']['commerce_price_1']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price_1']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price_1']['label'] = 'Цена для расчета';
  $handler->display->display_options['fields']['commerce_price_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_price_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price_1']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price_1']['type'] = 'commerce_price_raw_amount';
  $handler->display->display_options['fields']['commerce_price_1']['settings'] = array(
    'calculation' => '0',
  );
  /* Поле: Commerce Товар: В наличии */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_stock']['label'] = 'Количество';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: Глобальный: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['expression']['label'] = 'Стоимость товара';
  $handler->display->display_options['fields']['expression']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = ' ';
  $handler->display->display_options['fields']['expression']['expression'] = '[commerce_stock]*[commerce_price_1]/100';
  /* Поле: Commerce Товар: ID товара */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['label'] = '';
  $handler->display->display_options['fields']['product_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['product_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['product_id']['link_to_product'] = 0;
  $handler->display->display_options['path'] = 'admin/reports/product-report/xls';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $translatables['product_report'] = array(
    t('Master'),
    t('Отчет о товарах'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Содержимое referencing products from field_product'),
    t('Заголовок'),
    t('Фото'),
    t('Артикул'),
    t('Категория'),
    t('Цена'),
    t('[commerce_price-data]/100'),
    t('Цена для расчета'),
    t('Количество'),
    t('Стоимость товара'),
    t('.'),
    t(' '),
    t('Операции'),
    t('Page'),
    t('XLS Export'),
  );
  $export['product_report'] = $view;

  $view = new view();
  $view->name = 'recently_viewed_product';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recently viewed product';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Недавно просмотренные';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Recently Read: Recently Read */
  $handler->display->display_options['relationships']['node_rr_nid']['id'] = 'node_rr_nid';
  $handler->display->display_options['relationships']['node_rr_nid']['table'] = 'node';
  $handler->display->display_options['relationships']['node_rr_nid']['field'] = 'node_rr_nid';
  $handler->display->display_options['relationships']['node_rr_nid']['required'] = TRUE;
  /* Relationship: Содержимое: Referenced products */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['required'] = TRUE;
  /* Поле: Commerce Товар: Фото */
  $handler->display->display_options['fields']['field_field_product_photo']['id'] = 'field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['table'] = 'field_data_field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['field'] = 'field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_field_product_photo']['label'] = '';
  $handler->display->display_options['fields']['field_field_product_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_field_product_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_field_product_photo']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_field_product_photo']['settings'] = array(
    'colorbox_node_style' => 'product_image_small',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => 'product_image_big',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $handler->display->display_options['fields']['field_field_product_photo']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_field_product_photo']['delta_offset'] = '0';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Recently Read: Recently Read Date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'recently_read';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'node_rr_nid';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_display' => 'product_display',
  );
  /* Filter criterion: Recently Read: Текущий */
  $handler->display->display_options['filters']['current']['id'] = 'current';
  $handler->display->display_options['filters']['current']['table'] = 'recently_read';
  $handler->display->display_options['filters']['current']['field'] = 'current';
  $handler->display->display_options['filters']['current']['relationship'] = 'node_rr_nid';
  $handler->display->display_options['filters']['current']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Block products */
  $handler = $view->new_display('block', 'Block products', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '1';

  /* Display: Block - node */
  $handler = $view->new_display('block', 'Block - node', 'block_2');
  $translatables['recently_viewed_product'] = array(
    t('Master'),
    t('Недавно просмотренные'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Recently Read'),
    t('Products referenced by field_product'),
    t('Block'),
    t('Block products'),
    t('Block - node'),
  );
  $export['recently_viewed_product'] = $view;

  return $export;
}
