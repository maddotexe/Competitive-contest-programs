
var enableEditor = function(id) {
    $(id).markItUp(mySettings);
};

var enable_cb = function() {
    l = invalid[$(this).val()];
    disable_match(l, "input.attr");
};

var disable_match = function(name_list, match) {
    $(match).each(function () {
    	if ($.inArray(this.name, name_list) == -1) {
    	    $(this).removeAttr("disabled");
	    $(this).parent().toggleClass("gray", false);
    	} else {
    	    $(this).attr("disabled", true);
	    $(this).parent().toggleClass("gray", true);
    	}
    });
}
