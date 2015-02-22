var prepare = function() {
	$('#centerCol').animate({
		width : "59%"
	}, 600);
	$('#searchresultsheading').show(600);
	$('#cse').show(600);
	if ($("#rightCol").is(":hidden")) {
		$('#rightCol').css({width: "35%"});
		$('#rightCol').delay(100).show(600);
	}
	else {
		$('#rightCol').animate({
			width : "35%"
		}, 600);
	}
	return false;
};

var show = function() {
	$('#searchresultsheading h2').css('color', '#900');
	$('#searchresultsheading h2').html(
			lang == 'sv' ? 'S&ouml;kresultat' : 'Search result');
	$('#hide-button').show();
	return false;
};

var blur = function() {
	if (!$('.gsc-results').is(':visible'))
		hide();
	return false;
};

var hide = function() {
	if ($('#rightColBox').length < 1) {
		$('#rightCol').hide(400);
		$('#centerCol').delay(100).animate({
			width : "98%"
		}, 400);
	} else if ($('#rightColBox').length >= 1) {
		$('#rightCol').animate({
			width : "25%"
		}, 400);
		$('#centerCol').delay(100).animate({
			width : "69%"
		}, 400);
		$('#hide-button').hide();
		$('#cse').hide(600);
		$('#searchresultsheading').hide(600);
	} 
};

google.load('search', '1', {
	language : lang
});
google.setOnLoadCallback(function() {

	var customSearchControl = new google.search.CustomSearchControl(
			lang == 'sv' ? "002540261265754236040:_qhngrdmmhy"
					: "002540261265754236040:dqwulcwc1xa");
	customSearchControl
			.setResultSetSize(google.search.Search.FILTERED_CSE_RESULTSET);
	customSearchControl.setLinkTarget(google.search.Search.LINK_TARGET_TOP);
	var options = new google.search.DrawOptions();
	options.setSearchFormRoot('cse-search-form');
	customSearchControl.draw('cse', options);
	$('#cse-search-form .gsc-input').focusin(prepare);
	$('#cse-search-form .gsc-input').focusout(blur);
	$('#cse-search-form .gsc-search-button').focusin(prepare);
	$('#cse-search-form .gsc-search-button').click(show);
	$('#cse-search-form .gsc-search-button').focusout(blur);
	$('#gsc-i-id1').keydown(function(e) {
		if (e.keyCode == 13) {
			show();
			return true;
		}
	});
}, true);

$('#hide-button').click(function() {
	hide();
});

jQuery(document).ready(function() {
	$('.accordion .header').click(function() {
		$(this).next().toggle('slow');
		return false;
	}).next().hide();
});