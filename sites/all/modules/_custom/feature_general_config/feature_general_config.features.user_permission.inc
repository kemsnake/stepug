<?php
/**
 * @file
 * feature_general_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_general_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'administer Yandex.Metrics settings'.
  $permissions['administer Yandex.Metrics settings'] = array(
    'name' => 'administer Yandex.Metrics settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'yandex_metrics',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'менеджер магазина' => 'менеджер магазина',
    ),
    'module' => 'webform',
  );

  return $permissions;
}
