(function($){
  var $wrapper = null;

  Drupal.ajax = Drupal.ajax || {};

  /**
   * Ajax command: on cart form submitted.
   */
  Drupal.ajax.prototype.commands.dc_cart_ajax = function(ajax, response, status) {
    $wrapper = $wrapper || $('#' + response['form-id']).parents('.view:eq(0)').parent();

    $wrapper
      .find('div.messages').remove().end()
      .prepend(response['message']);

    if (response.output != '') {
      $wrapper.find('#dc-cart-ajax-form-wrapper').html(response.output);
      return;
    }

    var fake_link = '#dc-cart-ajax-' + response['form-id'];
    $(fake_link).trigger('click');
  };

  /**
   * Ajax command: on add-to-cart-form submited.
   */
  Drupal.ajax.prototype.commands.dc_cart_ajax_add_to_cart_form = function(ajax, response, status) {
    $('a.dc-cart-ajax-fake-link').each(function(){
      $(this).trigger('click');
    });
  };

  /**
   * If there's no cart block, disable ajax feature on add-to-cart forms.
   */
  Drupal.behaviors.dc_cart_ajax = {
    attach: function(context) {
      if ($('a.dc-cart-ajax-fake-link').size() == 0) {
        for (var i in Drupal.settings.ajax) {
          a = Drupal.settings.ajax[i];
          $(a.selector).unbind(a.event).unbind(a.prevent);
        }
      }
    }
  };

})(jQuery);