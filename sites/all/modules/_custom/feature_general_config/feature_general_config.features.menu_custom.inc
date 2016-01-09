<?php
/**
 * @file
 * feature_general_config.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_general_config_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-categories.
  $menus['menu-categories'] = array(
    'menu_name' => 'menu-categories',
    'title' => 'Категории',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Категории');

  return $menus;
}
