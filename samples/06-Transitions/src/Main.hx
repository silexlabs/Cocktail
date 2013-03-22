/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import haxe.Timer;
import js.Lib;
import js.Dom;

/**
 * Add divs to the document and 
 * moves them randomly using CSS
 * transitions
 */
class Main
{
	public function new()
	{
		#if nme
		var fps = new nme.display.FPS();
		fps.y = 60;
		nme.Lib.current.addChild(fps);
		#end
		
		addTransitionBox();
	}
	
	/**
	 * Moves a box randomly
	 */
	function transition(transitionBox:HtmlDom)
	{
		var container = Lib.document.getElementById("container");
		
		var transWidth = transitionBox.clientWidth;
		var transHeight = transitionBox.clientHeight;
		var containerWidth = container.clientWidth;
		var containerHeight = container.clientHeight;
		
		transitionBox.style.left = Std.string(Math.round(Math.random() * (containerWidth - transWidth))) + "px";
		transitionBox.style.top = Std.string(Math.round(Math.random() * (containerHeight - transHeight))) + "px";
	}
	
	/**
	 * create a new box
	 */
	function addTransitionBox()
	{
		var transitionBox = Lib.document.createElement("div");
		transitionBox.className = "trans";
		
		var randColor = function() {return Math.floor(Math.random() * 255); };
		
		transitionBox.style.backgroundColor = "rgb(" + randColor() + "," + randColor() + "," + randColor() + ")";
		
		transitionBox.addEventListener("transitionend",
		function(e) {
			transition(transitionBox);
		},
		false);
		
		transitionBox.addEventListener("webkitTransitionEnd",
		function(e) {
			transition(transitionBox);
		},
		false);
		
		transitionBox.onclick = function(e) {
			addTransitionBox();
		}
		
		Lib.document.getElementById("container").appendChild(transitionBox);
		
		Timer.delay(function() {transition(transitionBox);}, 1000);
	}
}