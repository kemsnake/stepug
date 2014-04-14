<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * stepug theme.
 */

/**
 * Process variables for search-result.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $result
 * - $module
 *
 * @see search-result.tpl.php
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

    // Add the display path to the line item's context data array if specified.
    /*if ($this->options['display_path']) {
      if ($this->view->display[$this->view->current_display]->display_plugin == 'page') {
        $line_item->data['context']['display_path'] = $this->view->display[$this->view->current_display]->display_options['path'];
      }
      else {
        $line_item->data['context']['display_path'] = current_path();
      }
    }

    // Store the View data in the context data array as well.
    $line_item->data['context']['view'] = array(
      'view_name' => $this->view->name,
      'display_name' => $this->view->current_display,
      'human_name' => $this->view->human_name,
      'page' => $this->view->current_page,
    );*/

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

/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param $variables
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function stepug_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '</div>';
    return $output;
  }
}