<?php
/**
 * @file
 * feature_general_config.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_general_config_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer info';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'footer_info';
  $fe_block_boxes->body = '<p style="text-align: center;">По всем интересующим вас вопросам вы можете обратиться по адресу <a href="mailto:info@stepug.ru">info@stepug.ru</a></p>
<p style="text-align: center;"><a href="https://vk.com/stepug" target="_blank">[[{"fid":"2005","view_mode":"default","fields":{"format":"default","field_file_image_alt_text[und][0][value]":"Наша группа в Вконтакте","field_file_image_title_text[und][0][value]":"Наша группа в Вконтакте"},"type":"media","attributes":{"alt":"Наша группа в Вконтакте","title":"Наша группа в Вконтакте","height":40,"width":160,"class":"media-element file-default"},"link_text":null}]]</a>

<!-- Yandex.Metrika counter -->
<script type="text/javascript">
(function (d, w, c) {
    (w[c] = w[c] || []).push(function() {
        try {
            w.yaCounter26599461 = new Ya.Metrika({id:26599461,
                    clickmap:true,
                    trackLinks:true,
                    accurateTrackBounce:true});
        } catch(e) { }
    });

    var n = d.getElementsByTagName("script")[0],
        s = d.createElement("script"),
        f = function () { n.parentNode.insertBefore(s, n); };
    s.type = "text/javascript";
    s.async = true;
    s.src = (d.location.protocol == "https:" ? "https:" : "http:") + "//mc.yandex.ru/metrika/watch.js";

    if (w.opera == "[object Opera]") {
        d.addEventListener("DOMContentLoaded", f, false);
    } else { f(); }
})(document, window, "yandex_metrika_callbacks");
</script>
<noscript><div><img src="//mc.yandex.ru/watch/26599461" style="position:absolute; left:-9999px;" alt="" /></div></noscript>
<!-- /Yandex.Metrika counter --></p>
';

  $export['footer_info'] = $fe_block_boxes;

  return $export;
}
