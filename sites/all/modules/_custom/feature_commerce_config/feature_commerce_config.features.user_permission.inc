<?php
/**
 * @file
 * feature_commerce_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_commerce_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access checkout'.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'administer checkout'.
  $permissions['administer checkout'] = array(
    'name' => 'administer checkout',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'administer commerce_customer_profile entities'.
  $permissions['administer commerce_customer_profile entities'] = array(
    'name' => 'administer commerce_customer_profile entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'administer commerce_order entities'.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'administer commerce_product entities'.
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'administer commerce_stock settings'.
  $permissions['administer commerce_stock settings'] = array(
    'name' => 'administer commerce_stock settings',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_stock',
  );

  // Exported permission: 'administer customer profile types'.
  $permissions['administer customer profile types'] = array(
    'name' => 'administer customer profile types',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'administer flat rate services'.
  $permissions['administer flat rate services'] = array(
    'name' => 'administer flat rate services',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_flat_rate',
  );

  // Exported permission: 'administer line item types'.
  $permissions['administer line item types'] = array(
    'name' => 'administer line item types',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_line_item',
  );

  // Exported permission: 'administer line items'.
  $permissions['administer line items'] = array(
    'name' => 'administer line items',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_line_item',
  );

  // Exported permission: 'administer payment methods'.
  $permissions['administer payment methods'] = array(
    'name' => 'administer payment methods',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'administer payments'.
  $permissions['administer payments'] = array(
    'name' => 'administer payments',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'administer product pricing'.
  $permissions['administer product pricing'] = array(
    'name' => 'administer product pricing',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product_pricing_ui',
  );

  // Exported permission: 'administer product types'.
  $permissions['administer product types'] = array(
    'name' => 'administer product types',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'administer shipping'.
  $permissions['administer shipping'] = array(
    'name' => 'administer shipping',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_shipping',
  );

  // Exported permission: 'configure auto product display'.
  $permissions['configure auto product display'] = array(
    'name' => 'configure auto product display',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_apd',
  );

  // Exported permission: 'configure order settings'.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'configure store'.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce',
  );

  // Exported permission: 'create commerce_customer_profile entities'.
  $permissions['create commerce_customer_profile entities'] = array(
    'name' => 'create commerce_customer_profile entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_customer_profile entities of bundle billing'.
  $permissions['create commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'create commerce_customer_profile entities of bundle billing',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_customer_profile entities of bundle shipping'.
  $permissions['create commerce_customer_profile entities of bundle shipping'] = array(
    'name' => 'create commerce_customer_profile entities of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_order entities'.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle commerce_order'.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_product entities'.
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle product'.
  $permissions['create commerce_product entities of bundle product'] = array(
    'name' => 'create commerce_product entities of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create payments'.
  $permissions['create payments'] = array(
    'name' => 'create payments',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'delete payments'.
  $permissions['delete payments'] = array(
    'name' => 'delete payments',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'edit any commerce_customer_profile entity'.
  $permissions['edit any commerce_customer_profile entity'] = array(
    'name' => 'edit any commerce_customer_profile entity',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_customer_profile entity of bundle billing'.
  $permissions['edit any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_customer_profile entity of bundle shipping'.
  $permissions['edit any commerce_customer_profile entity of bundle shipping'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_order entity'.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle commerce_order'.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_product entity'.
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle product'.
  $permissions['edit any commerce_product entity of bundle product'] = array(
    'name' => 'edit any commerce_product entity of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_customer_profile entities'.
  $permissions['edit own commerce_customer_profile entities'] = array(
    'name' => 'edit own commerce_customer_profile entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_customer_profile entities of bundle billing'.
  $permissions['edit own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_customer_profile entities of bundle shipping'.
  $permissions['edit own commerce_customer_profile entities of bundle shipping'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_order entities'.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle commerce_order'.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_product entities'.
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle product'.
  $permissions['edit own commerce_product entities of bundle product'] = array(
    'name' => 'edit own commerce_product entities of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'make rule based changes to commerce_stock'.
  $permissions['make rule based changes to commerce_stock'] = array(
    'name' => 'make rule based changes to commerce_stock',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_stock',
  );

  // Exported permission: 'update payments'.
  $permissions['update payments'] = array(
    'name' => 'update payments',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'view any commerce_customer_profile entity'.
  $permissions['view any commerce_customer_profile entity'] = array(
    'name' => 'view any commerce_customer_profile entity',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_customer_profile entity of bundle billing'.
  $permissions['view any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_customer_profile entity of bundle shipping'.
  $permissions['view any commerce_customer_profile entity of bundle shipping'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_order entity'.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle commerce_order'.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_product entity'.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle product'.
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_customer_profile entities'.
  $permissions['view own commerce_customer_profile entities'] = array(
    'name' => 'view own commerce_customer_profile entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_customer_profile entities of bundle billing'.
  $permissions['view own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_customer_profile entities of bundle shipping'.
  $permissions['view own commerce_customer_profile entities of bundle shipping'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle commerce_order'.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_product entities'.
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle product'.
  $permissions['view own commerce_product entities of bundle product'] = array(
    'name' => 'view own commerce_product entities of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view payments'.
  $permissions['view payments'] = array(
    'name' => 'view payments',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'commerce_payment',
  );

  return $permissions;
}
