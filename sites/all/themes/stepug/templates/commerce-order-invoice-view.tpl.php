<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <style>
      .view-commerce-line-item-table {
        width:100%;
        table-layout: fixed;
      }
      .view-commerce-line-item-table td{
        word-wrap: break-word;
      }
    </style>
  </head>
  <body>
    <table width="100%" border="0" cellspacing="0" cellpadding="1" align="center" bgcolor="#CCC">
      <tr>
        <td>
          <table width="100%" border="0" cellspacing="0" cellpadding="5" align="center" bgcolor="#FFF" style="font-family: verdana, arial, helvetica; font-size: 10px;">
            <tr>
              <td>
                <table width="100%" border="0" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: 11px;">
                  <tr>
                    <th colspan="2"><?php print 'Информация о заказе'; ?></th>
                  </tr>
                  <tr>
                    <td colspan="2">

                      <table class="details" width="100%" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: 1em;">
                        <tr>
                          <td valign="top" width="50%">
                            <br/>
                            <?php
                              global $base_url;
                              $account = user_load($info['order_uid']);
                              $user_link = $base_url . '/user/' . $info['order_uid'];
                            ?>
                            <b><?php print t('Пользователь:'); ?></b> <a href="<?php print $user_link; ?>">
                              <?php print format_username($account); ?></a><br/>
                            <br/>
                            <b><?php print t('Дата заказа:'); ?></b> <?php print date('j.m.Y', $info['order_created']); ?><br/>
                            <br/>
                          </td>
                          <td valign="top" width="50%">
                            <br/>
                            <?php
                            $order_link = $base_url . '/admin/commerce/orders/' . $info['order_number'];
                            ?>
                            <b><?php print t('Номер заказа:'); ?></b> <a href="<?php print $order_link; ?>">
                              <?php print $info['order_number']; ?></a><br/>
                            <br/>
                            <b><?php print t('Электронный адрес:'); ?></b> <?php print $info['order_mail']; ?><br/>
                            <br/>
                            <b><?php print t('Информация о доставке:'); ?></b><br />
                            <?php print isset($info['customer_shipping']) ? $info['customer_shipping'] : ''; ?><br />
                          </td>
                        </tr>
                      </table>

                    </td>
                  </tr>
                </table>
              </td>
            </tr>
            <tr>
              <td>
                <table class="products" width="100%" border="0" cellspacing="0" cellpadding="0" align="center" style="font-family: verdana, arial, helvetica; font-size: 11px;">
                  <tbody>
                    <tr>
                      <td class="line-items"><?php print isset($info['line_items']) ? $info['line_items'] : ''; ?></td>
                    </tr>
                    <?php
                    $total = FALSE;
                    if (isset($info['order_total'])) $total = $info['order_total'];
                    if ($total) {?>
                      <tr style="text-align: right;">
                        <td><b><?php print t('Общая сумма заказа:'); ?></b> <?php print $total; ?><br/></td>
                      </tr>
                    <?php } ?>
                  </tbody>
                </table>
              </td>
            </tr>
          </table>
        </td>
      </tr>
    </table>
  </body>
</html>
