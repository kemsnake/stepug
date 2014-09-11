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
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Commerce Товар: Фото */
  $handler->display->display_options['fields']['field_field_product_photo']['id'] = 'field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['table'] = 'field_data_field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['field'] = 'field_field_product_photo';
  $handler->display->display_options['fields']['field_field_product_photo']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_field_product_photo']['label'] = '';
  $handler->display->display_options['fields']['field_field_product_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_field_product_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_field_product_photo']['settings'] = array(
    'image_style' => 'product_image_small',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_field_product_photo']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_field_product_photo']['delta_offset'] = '0';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
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
  );
  $export['recently_viewed_product'] = $view;

  return $export;
}
