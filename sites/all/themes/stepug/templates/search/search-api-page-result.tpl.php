<?php
/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-api-page-results.tpl.php. This and the parent template are dependent
 * on one another, sharing the markup for definition lists.
 *
 * View mode is set in the Search page settings. If you select
 * "Themed as search results", then this template will be used for theming the
 * individual results. Any other view mode will bypass this template.
 *
 * Available variables:
 * - $index: The search index this search is based on.
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result.
 * - $info: String of all the meta information ready for print. Applies
 *   only if the result is a node.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $classes: CSS classes for this list element.
 *
 * Default keys within $info_split:
 * - $info_split['user']: Author of the entity, where an author exists.
 *   Depends on permission.
 * - $info_split['date']: Last update of the entity, if the 'updated'
 *   field exists. Short formatted.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array applies where the search result is a node, so it is
 * recommended to check for its existence before printing.
 * Where the result is a node, the default keys of 'user' and 'date'
 * will always exist.
 *
 * To check for all available data within $info_split, use the code below.
 * @code
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 * @endcode
 *
 * @see template_preprocess_search_api_page_result()
 */
?>
<div class="search-result col-xs-12 col-sm-6 col-md-4 col-lg-3 <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="product-row-wrapper">
    <?php if ($product_photo): ?>
      <div class="field-product-photo"><a href="<?php print $url; ?>"><?php print $product_photo; ?></a></div>
    <?php endif; ?>

    <?php print render($title_prefix); ?>
    <div class="field-title" <?php print $title_attributes; ?>><a href="<?php print $url; ?>"><?php print $title; ?></a></div>
    <?php print render($title_suffix); ?>

    <?php if ($product_price): ?>
      <div class="field-product-price"><?php print $product_price; ?></div>
    <?php endif; ?>

    <?php if ($add_to_cart_form): ?>
      <div class="field-add-to-cart-form"><?php print $add_to_cart_form; ?></div>
    <?php endif; ?>
  </div>
</div>
