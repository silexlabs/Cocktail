(function () { "use strict";
var Main = function() {
	var _g = 0, _g1 = js.Browser.document.querySelectorAll("#content p[class].visible");
	while(_g < _g1.length) {
		var node = _g1[_g];
		++_g;
		var htmlElement = node;
		htmlElement.innerHTML += "with the class " + htmlElement.classList[0];
	}
	var _g = 0, _g1 = js.Browser.document.querySelectorAll("#content p[class], #content .visible");
	while(_g < _g1.length) {
		var node = _g1[_g];
		++_g;
		var htmlElement = node;
		htmlElement.innerHTML += "!!!";
	}
	var first = js.Browser.document.getElementById("content").querySelector(".visible").innerHTML += " And I'm the first";
};
Main.main = function() {
	js.Browser.window.onload = function(e) {
		new Main();
	};
}
var js = {}
js.Browser = function() { }
js.Browser.window = typeof window != "undefined" ? window : null;
js.Browser.document = typeof window != "undefined" ? window.document : null;
Main.main();
})();
