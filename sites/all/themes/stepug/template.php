<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * stepug theme.
 */

/**
 * Themes a select drop-down as a collection of links.
 * Overrided contrib function - added child and top class.
 *
 * @see http://api.drupal.org/api/function/theme_select/7
 *
 * @param array $vars
 *   An array of arrays, the 'element' item holds the properties of the element.
 *
 * @return string
 *   HTML representing the form element.
 */
function stepug_select_as_links($vars) {
  $element = $vars['element'];

  $output = '';
  $name = $element['#name'];

  // Collect selected values so we can properly style the links later.
  $selected_options = array();
  if (empty($element['#value'])) {
    if (!empty($element['#default_values'])) {
      $selected_options[] = $element['#default_values'];
    }
  }
  else {
    $selected_options[] = $element['#value'];
  }

  // Add to the selected options specified by Views whatever options are in the
  // URL query string, but only for this filter.
  $urllist = parse_url(request_uri());
  if (isset($urllist['query'])) {
    $query = array();
    parse_str(urldecode($urllist['query']), $query);
    foreach ($query as $key => $value) {
      if ($key != $name) {
        continue;
      }
      if (is_array($value)) {
        // This filter allows multiple selections, so put each one on the
        // selected_options array.
        foreach ($value as $option) {
          $selected_options[] = $option;
        }
      }
      else {
        $selected_options[] = $value;
      }
    }
  }

  // Clean incoming values to prevent XSS attacks.
  if (is_array($element['#value'])) {
    foreach ($element['#value'] as $index => $item) {
      unset($element['#value'][$index]);
      $element['#value'][filter_xss($index)] = filter_xss($item);
    }
  }
  elseif (is_string($element['#value'])) {
    $element['#value'] = filter_xss($element['#value']);
  }

  // Go through each filter option and build the appropriate link or plain text.
  foreach ($element['#options'] as $option => $elem) {
    if (!empty($element['#hidden_options'][$option])) {
      continue;
    }
    // Check for Taxonomy-based filters.
    if (is_object($elem)) {
      $slice = array_slice($elem->option, 0, 1, TRUE);
      list($option, $elem) = each($slice);
    }

    // Check for optgroups.  Put subelements in the $element_set array and add
    // a group heading. Otherwise, just add the element to the set.
    $element_set = array();
    if (is_array($elem)) {
      $element_set = $elem;
    }
    else {
      $element_set[$option] = $elem;
    }

    $links = array();
    $multiple = !empty($element['#multiple']);

    // If we're in an exposed block, we'll get passed a path to use for the
    // Views results page.
    $path = '';
    if (!empty($element['#bef_path'])) {
      $path = $element['#bef_path'];
    }

    foreach ($element_set as $key => $value) {
      $element_output = '';

      $parent = taxonomy_get_parents($key);
      if (count($parent) > 0) {
        $class = 'bef-link-child';
      }
      else {
        $class = 'bef-link-top';
      }
      // Custom ID for each link based on the <select>'s original ID.
      $id = drupal_html_id($element['#id'] . '-' . $key);
      $elem = array(
        '#id' => $id,
        '#markup' => '',
        '#type' => $class,
        '#name' => $id,
      );

      if (array_search($key, $selected_options) === FALSE) {
        $elem['#children'] = l($value, bef_replace_query_string_arg($name, $key, $multiple, FALSE, $path));
        //$output .= theme('form_element', array('element' => $elem));
        $element_output = theme('form_element', array('element' => $elem));

        if ($element['#name'] == 'sort_bef_combine' && !empty($element['#settings']['toggle_links'])) {
          $sort_pair = explode(' ', $key);
          if (count($sort_pair) == 2) {
            // Highlight the link if it is the selected sort_by (can be either
            // asc or desc, it doesn't matter).
            if (strpos($selected_options[0], $sort_pair[0]) === 0) {
              $element_output = str_replace('form-item', 'form-item selected', $element_output);
            }
          }
        }
      } else {
        $elem['#children'] = l($value, bef_replace_query_string_arg($name, $key, $multiple, TRUE, $path));
        _form_set_class($elem, array('bef-select-as-links-selected'));
        //$output .= str_replace('form-item', 'form-item selected', theme('form_element', array('element' => $elem)));
        $element_output = str_replace('form-item', 'form-item selected', theme('form_element', array('element' => $elem)));
      }

      $output .= $element_output;

    }
  }

  $properties = array(
    '#description' => isset($element['#bef_description']) ? $element['#bef_description'] : '',
    '#children' => $output,
  );

  $output = '<div class="bef-select-as-links">';
  $output .= theme('form_element', array('element' => $properties));
  if (!empty($element['#value'])) {
    if (is_array($element['#value'])) {
      foreach ($element['#value'] as $value) {
        $output .= '<input type="hidden" name="' . $name . '[]" value="' . $value . '" />';
      }
    }
    else {
      $output .= '<input type="hidden" name="' . $name . '" value="' . $element['#value'] . '" />';
    }
  }
  $output .= '</div>';

  return $output;
}
