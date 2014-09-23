<?php
/**
 * @file
 * feature_commerce_config.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_commerce_config_default_rules_configuration() {
  $items = array();
  $items['rules_order_return'] = entity_import('rules_config', '{ "rules_order_return" : {
      "LABEL" : "\\u0412\\u043e\\u0437\\u0432\\u0440\\u0430\\u0442 \\u0437\\u0430\\u043a\\u0430\\u0437\\u0430",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "stock_control" ],
      "REQUIRES" : [ "rules", "commerce_ss", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "canceled" } },
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "canceled" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "\\u0422\\u0435\\u043a\\u0443\\u0449\\u0438\\u0439 \\u044d\\u043b\\u0435\\u043c\\u0435\\u043d\\u0442 \\u0441\\u043f\\u0438\\u0441\\u043a\\u0430" },
            "DO" : [
              { "commerce_ss_increase_by_line_item" : { "commerce_line_item" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_order_sent'] = entity_import('rules_config', '{ "rules_order_sent" : {
      "LABEL" : "Order sent",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "sent" } },
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "sent" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[commerce-order:mail]",
            "subject" : "\\u0412\\u0430\\u0448 \\u0437\\u0430\\u043a\\u0430\\u0437 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d",
            "message" : "\\u0412\\u0430\\u0448 \\u0437\\u0430\\u043a\\u0430\\u0437 \\u2116[commerce-order:order-number] \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d.\\r\\n\\r\\n\\u041c\\u0430\\u0433\\u0430\\u0437\\u0438\\u043d \\u0421\\u0442\\u0435\\u0436\\u043a\\u043e\\u0444 \\u0438 \\u041f\\u0443\\u0433\\u043e\\u0432\\u043a\\u0438\\u043d.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
