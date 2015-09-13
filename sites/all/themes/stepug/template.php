<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * stepug theme.
 */


require_once dirname(__FILE__) . '/preprocess/page.preprocess.inc';
require_once dirname(__FILE__) . '/process/page.process.inc';

/**
 * Process variables for search-result.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $result
 * - $module
 *
 * @see search-result.tpl.php
 *
 * @todo DElete?
 * for view search
 */
function stepug_preprocess_search_result(&$variables) {
  global $language;

  $result = $variables['result'];
  $variables['url'] = check_url($result['link']);
  $variables['title'] = check_plain($result['title']);
  if (isset($result['language']) && $result['language'] != $language->language && $result['language'] != LANGUAGE_NONE) {
    $variables['title_attributes_array']['xml:lang'] = $result['language'];
    $variables['content_attributes_array']['xml:lang'] = $result['language'];
  }

  $product_id = $result['node']->field_product['und'][0]['product_id'];
  $product = commerce_product_load($product_id);
  if (!empty($product)) {
    // Extract a default quantity for the Add to Cart form line item.
    $product_ids = array($product->product_id);

    // Build the line item we'll pass to the Add to Cart form.
    $line_item = commerce_product_line_item_new($product);
    $line_item->data['context']['product_ids'] = $product_ids;
    $line_item->data['context']['add_to_cart_combine'] = TRUE;

    // Generate a form ID for this add to cart form.
    $form_id = commerce_cart_add_to_cart_form_id($product_ids);

    // Build the Add to Cart form using the prepared values.
    $form = drupal_get_form($form_id, $line_item, TRUE, array());

    $variables['add_to_cart_form'] = drupal_render($form);
    $variables['product_photo'] = theme('image_style', array(
      'style_name' => 'product_image_small',
      'path' => $product->field_field_product_photo['und'][0]['uri']
    ));
    $variables['product_price'] = commerce_currency_format($product->commerce_price['und'][0]['amount'], $product->commerce_price['und'][0]['currency_code']);

  }
  $variables['theme_hook_suggestions'][] = 'search_result__' . $variables['module'];
}

/**
 * Preprocess variables for search-api-page-results.tpl.php.
 *
 * @param array $variables
 *   An associative array containing:
 *   - index: The index this search was executed on.
 *   - results: An array of search results, as returned by
 *     SearchApiQueryInterface::execute().
 *   - view_mode: The view mode to use for results. Either one of the searched
 *     entity's view modes (if applicable), or "search_api_page_result" to use
 *     the module's builtin theme function to render results.
 *   - keys: The keywords of the executed search.
 *   - page: The search page whose search results are being displayed.
 *
 * @see search-api-page-results.tpl.php
 */
function stepug_preprocess_search_api_page_results(array &$variables) {
  $results = $variables['results'];

  if (!empty($variables['results']['results'])) {
    $variables['items'] = $variables['index']->loadItems(array_keys($variables['results']['results']));
  }
  $variables['result_count'] = $results['result count'];
  $variables['sec'] = 0;
  if (isset($results['performance']['complete'])) {
    $variables['sec'] = round($results['performance']['complete'], 3);
  }
  $variables['search_performance'] = array(
    '#theme' => 'search_api_page_search_performance',
    '#markup' => format_plural(
      $results['result count'],
      'The search found 1 result in @sec seconds.',
      'The search found @count results in @sec seconds.',
      array('@sec' => $variables['sec'])
    ),
    '#prefix' => '<p class="search-performance">',
    '#suffix' => '</p>',
  );

  // Make the help text depend on the parse mode used.
  switch ($variables['page']->options['mode']) {
    case 'direct':
      if ($variables['index']->server()->class == 'search_api_solr') {
        $variables['no_results_help'] = t('<ul>
<li>Check if your spelling is correct.</li>
<li>Remove quotes around phrases to search for each word individually. <em>bike shed</em> will often show more results than <em>&quot;bike shed&quot;</em>.</li>
<li>Consider loosening your query with <em>OR</em>. <em>bike OR shed</em> will often show more results than <em>bike shed</em>.</li>
</ul>');
      }
      else {
        $variables['no_results_help'] = t('<ul>
<li>Check if your spelling is correct.</li>
<li>Use fewer keywords to increase the number of results.</li>
</ul>');
      }
      break;
    case 'single':
      $variables['no_results_help'] = t('<ul>
<li>Check if your spelling is correct.</li>
<li>Use fewer keywords to increase the number of results.</li>
</ul>');
      break;
    case 'terms':
      $variables['no_results_help'] = t('<ul>
<li>Check if your spelling is correct.</li>
<li>Remove quotes around phrases to search for each word individually. <em>bike shed</em> will often show more results than <em>&quot;bike shed&quot;</em>.</li>
<li>Use fewer keywords to increase the number of results.</li>
</ul>');
      break;
  }

  // Prepare CSS classes.
  $classes_array = array(
    'search-api-page',
    'search-api-page-' . drupal_clean_css_identifier($variables['page']->machine_name),
    'view-mode-' . drupal_clean_css_identifier($variables['view_mode']),
  );
  $variables['classes'] = implode(' ', $classes_array);

  // Distinguish between the native search_api_page_result "view mode" and
  // proper entity view modes (e.g., Teaser, Full content, RSS and so forth).
  $variables['search_results'] = array();
  if ($variables['view_mode'] != 'search_api_page_result') {
    // Check if we have any entities to show and, if yes, show them.
    if (!empty($variables['items'])) {
      $variables['search_results'] = entity_view($variables['index']->getEntityType(), $variables['items'], $variables['view_mode']);
    }
  }
  else {
    foreach ($results['results'] as $item) {
      if(!empty($variables['items'][$item['id']])) {
        $variables['search_results'][] = array(
          '#theme' => 'search_api_page_result',
          '#index' => $variables['index'],
          '#result' => $item,
          '#item' => $variables['items'][$item['id']],
        );
      }
    }
  }
  // Load CSS.
  $base_path = drupal_get_path('module', 'search_api_page') . '/';
  drupal_add_css($base_path . 'search_api_page.css');
}

function stepug_preprocess_search_api_page_result(array &$variables) {
  global $language;
  $result = $variables['item'];
  $variables['url'] = '/' . check_url(drupal_get_path_alias('node/' . $result->nid));
  $variables['title'] = check_plain($result->title);
  if (isset($result->language) && $result->language != $language->language && $result->language != LANGUAGE_NONE) {
    $variables['title_attributes_array']['xml:lang'] = $result['language'];
    $variables['content_attributes_array']['xml:lang'] = $result['language'];
  }

  $product_id = $result->field_product['und'][0]['product_id'];
  $product = commerce_product_load($product_id);
  if (!empty($product)) {
    // Extract a default quantity for the Add to Cart form line item.
    $product_ids = array($product->product_id);

    // Build the line item we'll pass to the Add to Cart form.
    $line_item = commerce_product_line_item_new($product);
    $line_item->data['context']['product_ids'] = $product_ids;
    $line_item->data['context']['add_to_cart_combine'] = TRUE;

    // Generate a form ID for this add to cart form.
    $form_id = commerce_cart_add_to_cart_form_id($product_ids);

    // Build the Add to Cart form using the prepared values.
    $form = drupal_get_form($form_id, $line_item, TRUE, array());

    $variables['add_to_cart_form'] = drupal_render($form);
    $variables['product_photo'] = theme('image_style', array(
      'style_name' => 'product_image_small',
      'path' => $product->field_field_product_photo['und'][0]['uri']
    ));
    $variables['product_price'] = commerce_currency_format($product->commerce_price['und'][0]['amount'], $product->commerce_price['und'][0]['currency_code']);

  }
  //$variables['theme_hook_suggestions'][] = 'search_result__' . $variables['module'];
}
/**
 * Themes a price components table.
 *
 * @param $variables
 *   Array contains the 'components' array and original 'price' array.
 *
 * @return string
 *   The formatted price components.
 */
function stepug_price_formatted_components(&$variables) {
  // Add the CSS styling to the table.
  drupal_add_css(drupal_get_path('module', 'commerce_price') . '/theme/commerce_price.theme.css');

  // Build table rows out of the components.
  $rows = array();
  $variables['components']['commerce_price_formatted_amount']['title'] = t('Order total');
  foreach ($variables['components'] as $name => $component) {
    $rows[] = array(
      'data' => array(
        array(
          'data' => $component['title'],
          'class' => array('component-title'),
        ),
        array(
          'data' => $component['formatted_price'],
          'class' => array('component-total'),
        ),
      ),
      'class' => array(drupal_html_class('component-type-' . $name)),
    );
  }

  return theme('table', array('rows' => $rows, 'attributes' => array('class' => array('commerce-price-formatted-components'))));
}

/*
 * Добавлеяем пункт "показать все" в пэйджер товаров
 */
function stepug_process_item_list(&$variables){
  if (isset($variables['attributes']['class'][0]) && $variables['attributes']['class'][0] == 'pager') {
    $display_all_item['class'][] = 'pager__item';
    $display_all_item['class'][] = 'pager-display-all';
    $display_all_item['class'][] = 'hidden-xs';
    $display_all_item['class'][] = 'hidden-sm';
    $path = current_path();
    $display_all_item['data'] = l(t('показать все'), $path . '/all');
    $variables['items'][] = $display_all_item;
  }
}

function stepug_menu_tree__main_menu($variables) {
  $output = '
<div class="navbar navbar-default">
<div class="container-fluid">
<div class="navbar-header">
    <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#top-naviagation-menu">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
    <a class="navbar-brand hidden-sm hidden-md hidden-lg" href="#">Меню</a>
</div>
      <!-- Everything you want hidden at 940px or less, place within here -->';

  $block = block_load('search_api_page', 'product_search');
  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
  $search_block = '<li class="leaf search-block-item">' . render($render_array) . '</li>';

  $output .= '<div class="navbar-collapse collapse" id="top-naviagation-menu">
  <ul class="nav navbar-nav col-xs-12 col-sm-12 col-md-12 col-lg-12">' . $variables['tree'] . $search_block . '</ul>
  </div>';
  $output .= '</div></div>';
  return $output;
}

function stepug_breadcrumb($variables) {
  // показываем крошки только на странице продуктов
  if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == '' && ($node = node_load(arg(1))) && $node->type == 'product_display') {
    return theme_breadcrumb($variables);
  }
}

function stepug_form_views_exposed_form_alter(&$form, &$form_state) {
  if (strpos($form['#id'], 'search-api-page-search-form-product-search') === 0) {
    // 'col-xs-12', 'col-sm-12', 'col-md-12', 'col-lg-12'
    $form['#attributes']['class'] = array_merge($form['#attributes']['class'], array('navbar-search'));
    $form['title']['#attributes']['class'][] = 'search-query';
    $form['submit']['#attributes']['class'] = array('btn', 'btn-default', 'btn-sm', 'hidden-xs', 'hidden-sm');
  }
}

/**
 * Themes a price components table.
 *
 * @param $variables
 *   Includes the 'components' array and original 'price' array as well as display options.
 */
function stepug_commerce_price_rrp_your_price($variables) {
  $web_price = $variables['components']['commerce_price_rrp_your_price']['formatted_price'];
  $rrp = $variables['components']['base_price']['formatted_price'];
  $rrp = $variables['components']['base_price']['price']['amount'];

  if ($variables['options']['include_tax_in_rrp'] == TRUE) {
    foreach ($variables['components'] as $component_name => $component_value) {
      if (substr($component_name, 0, 3) == 'tax') {
        $rrp += $component_value['price']['amount'];
      }
    }
  }
  $rrp = commerce_currency_format($rrp, $variables['components']['base_price']['price']['currency_code']);
/*  if (isset($variables['components']['discount'])) {
    $saving = $variables['components']['discount']['formatted_price'];
  }*/

  $check_for_same_price = $variables['options']['check_for_same_price'];
  $discount_percent = FALSE;
  if ($check_for_same_price == 1 && $web_price != $rrp) {
    $price_output = '<div class="base-price"><s>' . $rrp . '</s></div>';
    $price_output .= '<div class="discount-price"><strong>' . $web_price . '</strong></div>';
    // отображаем блок с процентами скидки
    $discount_percent = FALSE;
    foreach ($variables['components'] as $key => $compoent) {
      if (strpos($key, 'discount|') === 0) {
        $component_parts = explode('|', $key);
        $discounts = entity_load('commerce_discount', array($component_parts[1]));
        $discount = array_shift($discounts);
        $discount_wrapper = entity_metadata_wrapper('commerce_discount', $discount);
        $offer = $discount_wrapper->commerce_discount_offer->value();
        $discount_offer_wrapper = entity_metadata_wrapper('commerce_discount_offer', $offer);
        $discount_percent = round($discount_offer_wrapper->commerce_percentage->value());
      }
    }
    if ($discount_percent) {
      $price_output .= '<div class="discount-info">-' . $discount_percent . '%</div>';
    }
    /*if ($variables['options']['show_saving'] == 1 && isset($saving)) {
      $rows[] = array(
        'data' => array(
          array(
            'data' => check_plain($variables['options']['saving_label']),
            'class' => array('saving-title'),
          ),
          array(
            'data' => $saving,
            'class' => array('saving-total'),
          ),
        )
      );
    }*/
  }
  else {
    $price_output = '<div class="base-price">' . $rrp . '</div>';
  }
  return  $price_output;
}