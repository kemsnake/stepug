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
  $items['commerce_checkout_custom_create_user_from_order'] = entity_import('rules_config', '{ "commerce_checkout_custom_create_user_from_order" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u043d\\u043e\\u0432\\u043e\\u0439 \\u0443\\u0447\\u0451\\u0442\\u043d\\u043e\\u0439 \\u0437\\u0430\\u043f\\u0438\\u0441\\u0438 \\u0434\\u043b\\u044f \\u0430\\u043d\\u043e\\u043d\\u0438\\u043c\\u043d\\u043e\\u0433\\u043e \\u0437\\u0430\\u043a\\u0430\\u0437\\u0430 (cloned)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "2",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce", "commerce_checkout", "entity" ],
      "ON" : { "commerce_order_presave" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "checkout_payment" } },
        { "NOT data_is" : {
            "data" : [ "commerce-order-unchanged:status" ],
            "value" : "checkout_payment"
          }
        },
        { "data_is" : { "data" : [ "commerce-order:uid" ], "value" : "0" } },
        { "NOT entity_exists" : {
            "type" : "user",
            "property" : "mail",
            "value" : [ "commerce-order:mail" ]
          }
        },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_name" : [ "commerce-order:mail-username" ],
              "param_mail" : [ "commerce-order:mail" ]
            },
            "PROVIDE" : { "entity_created" : { "account_created" : "Created account" } }
          }
        },
        { "data_set" : { "data" : [ "account-created:status" ], "value" : 1 } },
        { "entity_save" : { "data" : [ "account-created" ], "immediate" : 1 } },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "commerce-order:mail" ],
              "limit" : 1
            },
            "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched account" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "account-fetched" ] },
            "ITEM" : { "list_item" : "\\u0422\\u0435\\u043a\\u0443\\u0449\\u0438\\u0439 \\u044d\\u043b\\u0435\\u043c\\u0435\\u043d\\u0442 \\u0441\\u043f\\u0438\\u0441\\u043a\\u0430" },
            "DO" : [
              { "send_account_email" : {
                  "account" : [ "list-item" ],
                  "email_type" : "register_no_approval_required"
                }
              },
              { "data_set" : { "data" : [ "commerce-order:uid" ], "value" : [ "list-item:uid" ] } },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-billing:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-shipping:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_custom_set_user_for_order'] = entity_import('rules_config', '{ "commerce_checkout_custom_set_user_for_order" : {
      "LABEL" : "\\u0421\\u0432\\u044f\\u0437\\u0430\\u0442\\u044c \\u0430\\u043d\\u043e\\u043d\\u0438\\u043c\\u043d\\u044b\\u0439 \\u0437\\u0430\\u043a\\u0430\\u0437 \\u0441 \\u0441\\u0443\\u0449\\u0435\\u0441\\u0442\\u0432\\u0443\\u044e\\u0449\\u0438\\u043c \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u0435\\u043c (custom)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:uid" ], "value" : "0" } },
        { "entity_exists" : {
            "type" : "user",
            "property" : "mail",
            "value" : [ "commerce-order:mail" ]
          }
        },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } },
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "checkout_payment" } },
        { "NOT data_is" : {
            "data" : [ "commerce-order-unchanged:status" ],
            "value" : "checkout_payment"
          }
        }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "commerce-order:mail" ],
              "limit" : 1
            },
            "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched account" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "account-fetched" ] },
            "ITEM" : { "list_item" : "\\u0422\\u0435\\u043a\\u0443\\u0449\\u0438\\u0439 \\u044d\\u043b\\u0435\\u043c\\u0435\\u043d\\u0442 \\u0441\\u043f\\u0438\\u0441\\u043a\\u0430" },
            "DO" : [
              { "data_set" : { "data" : [ "commerce-order:uid" ], "value" : [ "list-item:uid" ] } },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-billing:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-shipping:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['feature_commerce_config_order_ready_for_pickup'] = entity_import('rules_config', '{ "feature_commerce_config_order_ready_for_pickup" : {
      "LABEL" : "\\u0417\\u0430\\u043a\\u0430\\u0437 \\u0433\\u043e\\u0442\\u043e\\u0432 \\u043a \\u0441\\u0430\\u043c\\u043e\\u0432\\u044b\\u0432\\u043e\\u0437\\u0443",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "redy_for_pickup" } },
        { "NOT data_is" : {
            "data" : [ "commerce-order-unchanged:status" ],
            "value" : "redy_for_pickup"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[commerce-order:mail]",
            "subject" : "\\u0417\\u0430\\u043a\\u0430\\u0437 \\u043d\\u043e\\u043c\\u0435\\u0440 [commerce-order:order-number] \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 [site:name]",
            "message" : "\\u0412\\u0430\\u0448 \\u0437\\u0430\\u043a\\u0430\\u0437 \\u2116[commerce-order:order-number] \\u0433\\u043e\\u0442\\u043e\\u0432 \\u043a \\u0441\\u0430\\u043c\\u043e\\u0432\\u044b\\u0432\\u043e\\u0437\\u0443.\\r\\n\\r\\n\\u0414\\u043b\\u044f \\u0443\\u0442\\u043e\\u0447\\u043d\\u0435\\u043d\\u0438\\u044f \\u0432\\u0440\\u0435\\u043c\\u0435\\u043d\\u0438 \\u0438 \\u043c\\u0435\\u0441\\u0442\\u0430 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d\\u0438\\u044f \\u0437\\u0430\\u043a\\u0430\\u0437\\u0430 \\u0441\\u0432\\u044f\\u0436\\u0438\\u0442\\u0435\\u0441\\u044c \\u0441 \\u043d\\u0430\\u043c\\u0438 \\u043e\\u0434\\u043d\\u0438\\u043c \\u0438\\u0437 \\u043b\\u044e\\u0431\\u044b\\u0445 \\u0443\\u0434\\u043e\\u0431\\u043d\\u044b\\u0445 \\u0434\\u043b\\u044f \\u0432\\u0430\\u0441 \\u0441\\u043f\\u043e\\u0441\\u043e\\u0431\\u043e\\u0432\\r\\n1. \\u0422\\u0435\\u043b\\u0435\\u0444\\u043e\\u043d +7 951 189 76 00\\r\\n2. Email info@stepug.ru\\r\\n3. \\u041b\\u0438\\u0447\\u043d\\u043e\\u0435 \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u0432 \\u0412\\u043a\\u043e\\u043d\\u0442\\u0430\\u043a\\u0442\\u0435 \\u0434\\u043b\\u044f \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044f https:\\/\\/vk.com\\/stepug\\r\\n\\r\\n\\u0421\\u0442\\u0430\\u0442\\u0443\\u0441 \\u0412\\u0430\\u0448\\u0435\\u0433\\u043e \\u0442\\u0435\\u043a\\u0443\\u0449\\u0435\\u0433\\u043e \\u0437\\u0430\\u043a\\u0430\\u0437\\u0430 \\u043c\\u043e\\u0436\\u043d\\u043e \\u043f\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u043f\\u043e \\u0441\\u0441\\u044b\\u043b\\u043a\\u0435:\\r\\n[commerce-order:customer-url]\\r\\n\\r\\n\\u041c\\u0430\\u0433\\u0430\\u0437\\u0438\\u043d \\u0421\\u0442\\u0435\\u0436\\u043a\\u043e\\u0432 \\u0438 \\u041f\\u0443\\u0433\\u043e\\u0432\\u043a\\u0438\\u043d.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
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
      "LABEL" : "\\u0417\\u0430\\u043a\\u0430\\u0437 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d \\u043f\\u043e\\u043b\\u0443\\u0447\\u0430\\u0442\\u0435\\u043b\\u044e",
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
            "subject" : "\\u0417\\u0430\\u043a\\u0430\\u0437 \\u043d\\u043e\\u043c\\u0435\\u0440 [commerce-order:order-number] \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 [site:name]",
            "message" : "\\u0412\\u0430\\u0448 \\u0437\\u0430\\u043a\\u0430\\u0437 \\u2116[commerce-order:order-number] \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d.\\r\\n\\r\\n\\u041f\\u043e\\u0447\\u0442\\u043e\\u0432\\u044b\\u0439 \\u0438\\u0434\\u0435\\u043d\\u0442\\u0438\\u0444\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440 \\u0432\\u0430\\u0448\\u0435\\u0433\\u043e \\u0442\\u043e\\u0432\\u0430\\u0440\\u0430 [commerce-order:field_track_code]\\r\\n\\r\\n\\u0421\\u0442\\u0430\\u0442\\u0443\\u0441 \\u0412\\u0430\\u0448\\u0435\\u0433\\u043e \\u0442\\u0435\\u043a\\u0443\\u0449\\u0435\\u0433\\u043e \\u0437\\u0430\\u043a\\u0430\\u0437\\u0430 \\u043c\\u043e\\u0436\\u043d\\u043e \\u043f\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u043f\\u043e \\u0441\\u0441\\u044b\\u043b\\u043a\\u0435:\\r\\n[commerce-order:customer-url]\\r\\n\\r\\n\\u041c\\u0430\\u0433\\u0430\\u0437\\u0438\\u043d \\u0421\\u0442\\u0435\\u0436\\u043a\\u043e\\u0432 \\u0438 \\u041f\\u0443\\u0433\\u043e\\u0432\\u043a\\u0438\\u043d.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
