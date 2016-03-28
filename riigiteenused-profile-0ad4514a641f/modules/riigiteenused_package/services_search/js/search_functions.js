(function ($) {
  var $source_container = $('div.view-header');
  var $destination_container = $('div.search-container > div.attachment-before');
  var $element = $('div.view-header > div.view-description-text');

  $destination_container.prepend($element);
  $source_container.remove($element);
})(jQuery);