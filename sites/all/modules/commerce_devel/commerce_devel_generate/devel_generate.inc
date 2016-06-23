<?php

/**
 * @file
 * Contains devel generate information.
 */

/**
 * The main API function for creating products.
 *
 * @param array $form_state
 *   Form state array of values.
 *
 * @see commerce_devel_generate_products_form()
 */
function commerce_devel_generate_products($form_state) {
  if (!empty($form_state['values']['kill_products'])) {
    commerce_devel_generate_products_kill($form_state['values']);
  }

  if (count($form_state['values']['product_types'])) {
    commerce_devel_generate_products_pre_product($form_state['values']);
    $start = time();
    for ($i = 1; $i <= $form_state['values']['num_products']; $i++) {
      // Get list of users we will use.
      commerce_devel_generate_product_add_product($form_state['values']);
      if (function_exists('drush_log') && $i % drush_get_option('feedback', 1000) == 0) {
        $now = time();
        drush_log(dt('Completed !feedback products (!rate products/min)', array(
          '!feedback' => drush_get_option('feedback', 1000),
          '!rate' => (drush_get_option('feedback', 1000) * 60) / ($now - $start),
          )), 'ok');
        $start = $now;
      }
    }
  }

  devel_generate_set_message(format_plural($form_state['values']['num_products'], '1 product created.', 'Finished creating @count products'));
}

/**
 * Removes existing commerce products.
 *
 * This is used by both the batch and non-batch branches of the code.
 *
 * @param array $values
 *   An array of options obtained from commerce_devel_generate_products_form.
 */
function commerce_devel_generate_products_kill($values) {
  $results = db_select('commerce_product', 'p')
              ->fields('p', array('product_id'))
              ->condition('type', $values['product_types'], 'IN')
              ->execute();
  foreach ($results as $result) {
    $product_ids[] = $result->product_id;
  }

  if (!empty($product_ids)) {
    commerce_product_delete_multiple($product_ids);
    drupal_set_message(t('Deleted %count products.', array('%count' => count($product_ids))));
  }
}

/**
 * Create one product. Used by both batch and non-batch code branches.
 *
 * @param array $results
 *   An array of options obtained from commerce_devel_generate_products_form.
 */
function commerce_devel_generate_product_add_product(&$results) {
  $type = array_rand($results['product_types']);
  $product = commerce_product_new($type);

  // Insert new data:
  $product->title = devel_create_greeking(mt_rand(2, $results['title_length']), TRUE);

  // Save default parameters back into the $product object.
  $product->sku = commerce_devel_generate_generate_sku();
  $product->status = TRUE;
  devel_generate_set_language($results, $product);

  $users = $results['users'];
  $product->uid = $users[array_rand($users)];
  $product->commerce_devel_generate = $results;

  // Populate fields on behalf of field.module.
  $modules = array('commerce_price');
  foreach ($modules as $module) {
    module_load_include('inc', 'commerce_devel_generate', $module . '.devel_generate');
  }
  module_load_include('inc', 'devel_generate', 'devel_generate.fields');
  devel_generate_fields($product, 'commerce_product', $product->type);

  commerce_product_save($product);
}

/**
 * Generates a random SKU.
 *
 * @return string
 *   Generated SKU
 */
function commerce_devel_generate_generate_sku() {
  return uniqid('sku');
}
