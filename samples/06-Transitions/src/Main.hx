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
	/**
	 * width/height of each box and
	 * of the container fro the boxes
	 */
	var boxWidth:Int;
	var boxHeight:Int;
	var containerWidth:Int;
	var containerHeight:Int;
	
	public function new()
	{
		#if nme
		var fps = new nme.display.FPS();
		fps.y = 60;
		nme.Lib.current.addChild(fps);
		#end
		
		//match width and height of css stylsheet
		boxWidth = 50;
		boxHeight = 50;
		
		containerHeight = Lib.window.innerHeight;
		containerWidth = Lib.window.innerWidth;
		
		//add a stylesheet and wait for it to be loaded before start
		//
		//note : added here instead of html because in NME, loading is synchronous
		//because it is local, so we need to add load listener before starting loading
		var link = Lib.document.createElement("link");
		link.addEventListener("load",
		function(e) {
			start();
			
		}, false);
		
		link.setAttribute("href", "app.css");
		link.setAttribute("type", "text/css");
		link.setAttribute("rel", "stylesheet");
		
		Lib.document.getElementsByTagName("head")[0].appendChild(link);
	}
	
	/**
	 * add a bunch of boxes
	 */
	function start() 
	{
		for (i in 0...1000)
		{
			addTransitionBox();
		}
	}
	
	/**
	 * Moves a box randomly
	 */
	function transition(transitionBox:HtmlDom)
	{
		transitionBox.style.left = Std.string(Math.round(Math.random() * (containerWidth - boxWidth))) + "px";
		transitionBox.style.top = Std.string(Math.round(Math.random() * (containerHeight - boxHeight))) + "px";
	}
	
	/**
	 * create a new box
	 */
	function addTransitionBox()
	{
		var transitionBox = Lib.document.createElement("div");
		transitionBox.className = "trans";
		
		//random background color
		var randColor = function() {return Math.floor(Math.random() * 255); };
		transitionBox.style.backgroundColor = "rgb(" + randColor() + "," + randColor() + "," + randColor() + ")";
		
		//restart transition after end of current 
		//transition
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
		
		//add more boxes when one is clicked
		transitionBox.onclick = function(e) {
			addTransitionBox();
		}
		
		Lib.document.getElementById("container").appendChild(transitionBox);
		
		Timer.delay(function() {transition(transitionBox);}, 1000);
	}
}