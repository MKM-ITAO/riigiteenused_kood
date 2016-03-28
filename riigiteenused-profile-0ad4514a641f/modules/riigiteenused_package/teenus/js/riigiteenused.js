(function ($) {
  Drupal.behaviors.betterExposedFilters = {
    attach: function(context, settings) { 

    
    // Table Colors  

    var yellow = $('.stat-yellow');
    var green = $('.stat-green');
    var red = $('.stat-red');

    yellow.parent().addClass('yellow-td');
    green.parent().addClass('green-td');
    red.parent().addClass('red-td');

   
    // Allasutuse omad

    var hideSerivcesSubAll = $(".page-statistika-allasutus .content > .view-teenuste-statistika > .view-content > table > tbody > tr > td > .view-kanaalite-statistika tbody");
    var hideTitles = $(".page-statistika-allasutus .content > .view-teenuste-statistika > .view-content > table > tbody > tr > td > .view-kanaalite-statistika thead tr:first-of-type");
    var klickSub = $(".page-statistika-allasutus .statistic-sevice-name");
    klickSub.addClass("subclick")
    hideSerivcesSubAll.hide();
    hideTitles.hide();
    $(".subclick", context).click(function(){
      $(this).next().find("tbody").toggle();
      $(this).next().find("table thead tr:first-of-type").toggle().toggleClass("show-titles").next().toggleClass("padding-adjustment");
      $(this).toggleClass("collapsed");
    });

    var hideKanalid = $("#channel-stat-title").parent().next();
    $("#channel-stat-title").addClass('collapsed');
    $("#channel-stat-title", context).click(function(){
      hideKanalid.toggle();
      $(this).toggleClass("collapsed");
    });

    var hideServicesAll = $(".page-statistika-allasutus .content > .view-teenuste-statistika > .view-content");
    var hideServicesFooter = $(".page-statistika-allasutus .content > .view-teenuste-statistika > .view-footer");
    hideServicesAll.hide();
    hideServicesFooter.hide();
    $("#serv-stat-title", context).click(function(){
      hideServicesAll.toggle();
      hideServicesFooter.toggle();
      $(this).toggleClass("collapsed");
    }); 


    // Valitsuse omad

    var hideServicesGov = $(".content > .view-valitsuse-teenuste-statistika  > .view-content > .views-row > .views-field-view > span > .view-ministeeriumi-teenuste-statistika > .view-content > div > div:last-of-type > span > .view-teenuste-statistika > .view-content");
    var klickTitle = $ (".content > .view-valitsuse-teenuste-statistika  > .view-content > .views-row > .views-field-view > span > .view-ministeeriumi-teenuste-statistika > .view-content > div > div:first-of-type");
    klickTitle.addClass('klicktitle')
    var hideStatsFooter = $ (".content > .view-valitsuse-teenuste-statistika  > .view-content > .views-row > .views-field-view > span > .view-ministeeriumi-teenuste-statistika > .view-footer");
    hideServicesGov.hide();
    $(".klicktitle", context).click(function(){
      $(this).next().next().children().children().children("div:last").toggle();
      $(this).toggleClass("collapsed");
    });

    var hideSubGov = $(".content > .view-valitsuse-teenuste-statistika  > .view-content > .views-row > .views-field-view > span > .view-ministeeriumi-teenuste-statistika > .view-content > div > div:last-of-type > span > .view-teenuste-statistika > .view-content > table > tbody > tr .view-kanaalite-statistika tbody");
    var hideLabels = $(".content > .view-valitsuse-teenuste-statistika  > .view-content > .views-row > .views-field-view > span > .view-ministeeriumi-teenuste-statistika > .view-content > div > div:last-of-type > span > .view-teenuste-statistika > .view-content > table > tbody > tr .view-kanaalite-statistika thead tr:first-of-type");
    var klickTitleGov = $(".page-statistika-valitsus .statistic-sevice-name");
    klickTitleGov.addClass("govclick");
    hideSubGov.hide();
    hideLabels.hide();
    $(".govclick", context).click(function(){
      $(this).next().find("tbody").toggle();
      $(this).next().find("table thead tr:first-of-type").toggle().toggleClass("show-titles").next().toggleClass("padding-adjustment");
      $(this).toggleClass("collapsed");
    });

    var hideServices = $(".content > .view-valitsuse-teenuste-statistika > .view-header > .view-kanaalite-statistika, .view-teenuste-statistika .view-footer");
    var clickTitleServ = $(".page-statistika-valitsus .statistic-page-channels-block h3");
    clickTitleServ.addClass("collapsed").addClass("servclick");
    $(".servclick", context).click(function(){
      hideServices.toggle();
      $(this).toggleClass("collapsed");
    });

    
    // Ministeeriumi omad

    var hideServicesMinkan = $(".page-statistika-ministeerium .content > .view-ministeeriumi-teenuste-statistika > .view-header > .view-kanaalite-statistika, .view-teenuste-statistika .view-footer");
    var clickServMain = $(".page-statistika-ministeerium .statistic-page-channels-block h3");
    clickServMain.addClass("collapsed").addClass("servmainclick");
    $(".servmainclick", context).click(function(){
      hideServicesMinkan.toggle();
      $(this).toggleClass("collapsed");
    });

    var hideServicesMin = $(".page-statistika-ministeerium .content > .view-ministeeriumi-teenuste-statistika  > .view-content > .views-row > div:last-of-type > span > .view-teenuste-statistika > .view-content");
    var klickTitleMin = $ (".page-statistika-ministeerium .content > .view-ministeeriumi-teenuste-statistika div.views-field-name-i18n");
    klickTitleMin.addClass('minclick')
    hideServicesMin.hide();
    $(".minclick", context).click(function(){
      $(this).next().next().children().children().children("div:last").toggle();
      $(this).toggleClass("collapsed");
    });

    var hideSubMin = $(".page-statistika-ministeerium .content > .view-ministeeriumi-teenuste-statistika > .view-content > .views-row > div:last-of-type  > span > .view-teenuste-statistika > .view-content .view-kanaalite-statistika table tbody");
    var hideLabelsMin = $(".page-statistika-ministeerium .content > .view-ministeeriumi-teenuste-statistika > .view-content > .views-row > div:last-of-type  > span > .view-teenuste-statistika > .view-content .view-kanaalite-statistika table thead tr:first-of-type");
    var klickSubMin =  $(".page-statistika-ministeerium .statistic-sevice-name");
    klickSubMin.addClass("minclicksub");
    hideSubMin.hide();
    hideLabelsMin.hide();
    $(".minclicksub", context).click(function(){
      $(this).next().find("tbody").toggle();
      $(this).next().find("table thead tr:first-of-type").toggle().toggleClass("show-titles").next().toggleClass("padding-adjustment");
      $(this).toggleClass("collapsed");
    });

    
    // Add class to titles that are too long and need some adjustment
    var XX = 70;
    $('.statistic-sevice-name').filter(function() {
    return $(this).text().length > XX;
    }).addClass('tworows');

    var YY = 110;
    $('.statistic-sevice-name').filter(function() {
    return $(this).text().length > YY;
    }).addClass('threerows');


    // Handling search
    // Check for empty container
    jQuery.expr[':'].space = function(elem) {
    var $elem = jQuery(elem);
    return !$elem.children().length && !$elem.text().match(/\S/);
    }
   
    $('.page-teenuste-otsing .field-content:space, .page-teenuste-otsing .view-kanaalite-statistika:space').parent().addClass("empty");

    // The little extra info toggle containers
    var searchClick = $('.views-field-field-t-regulatsioon, .views-field-field-t-eeltingimused, .service-statistic').not('.empty');
    var searchClickHide = $('.views-field-field-t-regulatsioon > .field-content, .views-field-field-t-eeltingimused > .field-content, .service-statistic > .field-content');

    searchClick.find(".field-content .field-content").show();//make the inner fields show up, that originally have display:none

    $('body').click(function() {
      $('.container-open .field-content').hide();
      $('.views-field').removeClass('container-open');
    });

    $(searchClick, context).click(function(event) {
      event.stopPropagation();
      $(this).toggleClass('container-open');
      var theContainer = $(this).children(".field-content");
      searchClickHide.not(theContainer).hide().parent().removeClass('container-open');
      theContainer.toggle();
    });

    // Add class to the last span element to clear float
    var spanCount = $('.page-teenuste-otsing .search-container > .view-content > .views-row > span:last-of-type')
    spanCount.next().addClass('clear-me');

  }}
})(jQuery);