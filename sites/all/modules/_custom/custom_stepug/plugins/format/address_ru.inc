<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Address form (Russia)'),
  'format callback' => 'custom_stepug_format_address_generate',
  'type' => 'address',
  'weight' => -100,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function custom_stepug_format_address_generate(&$format, $address, $context = array()) {
  // We start with a reasonable default: a simple block format suitable
  // for international shipping. We extend it with country-specific heuristics
  // below.

  // The street block.
  $format['street_block'] = array(
    '#type' => 'addressfield_container',
    '#attributes' => array(
      'class' => array('street-block'),
    ),
    '#weight' => 10,
  );
  $format['street_block']['thoroughfare'] = array(
    '#title' => t('Address 1'),
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array('thoroughfare'),
      'x-autocompletetype' => 'address-line1',
      'autocomplete' => 'address-line1',
    ),
    '#size' => 30,
    // The #required will be automatically set to FALSE when processing.
    '#required' => TRUE,
  );

  $format['locality_block'] = array(
    '#type' => 'addressfield_container',
    '#attributes' => array(
      'class' => array('addressfield-container-inline', 'locality-block', 'country-' . $address['country']),
    ),
    '#weight' => 0,
  );
  $format['locality_block']['#attached']['css'][] = drupal_get_path('module', 'addressfield') . '/addressfield.css';
  $format['locality_block']['postal_code'] = array(
    '#title' => t('Postal code'),
    '#size' => 10,
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('postal-code'),
      'x-autocompletetype' => 'postal-code',
      'autocomplete' => 'postal-code',
    ),
    '#weight' => 0,
  );
  $format['locality_block']['administrative_area'] = array(
    '#title' => t('State', array(), array('context' => 'Territory of a country')),
    '#size' => 30,
    '#required' => TRUE,
    '#prefix' => ' ',
    '#attributes' => array(
      'class' => array('state'),
      'x-autocompletetype' => 'region',
      'autocomplete' => 'region',
    ),
    '#weight' => 1,
  );
  $format['locality_block']['locality'] = array(
    '#title' => t('City'),
    '#size' => 30,
    '#required' => TRUE,
    '#prefix' => ' ',
    '#attributes' => array(
      'class' => array('locality'),
      'x-autocompletetype' => 'locality',
      'autocomplete' => 'locality',
    ),
    '#weight' => 2,
  );

  $format['country'] = array(
    '#access' => FALSE,
    '#title' => t('Country'),
    '#options' => _addressfield_country_options_list(),
    '#render_option_value' => TRUE,
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('country'),
      'x-autocompletetype' => 'country',
      'autocomplete' => 'country',
    ),
    '#weight' => 100,
  );

  if ($context['mode'] == 'form') {
    // Provide a wrapper ID for AJAX replacement based on country selection.
    if (!isset($format['#wrapper_id'])) {
      $format['#wrapper_id'] = drupal_html_id('addressfield-wrapper');
      $format['#prefix'] = '<div id="' . $format['#wrapper_id'] . '">';
      $format['#suffix'] = '</div>';
    }
  }
}
