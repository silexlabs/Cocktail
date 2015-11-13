package src;
/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import cocktail.html.HtmlElement;
import haxe.Timer;
import cocktail.Browser;

/**
 * Add divs to the document and 
 * moves them randomly using CSS
 * transitions
 */
class Main
{
	static function main()
	{
		//init cocktail with the content of the index.html file
		cocktail.api.Cocktail.boot("res/index.html");
		
		Browser.window.onload = function(e) new Main();
	}
	
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
		#if openfl
		var fps = new openfl.display.FPS();
		fps.y = 50;
		fps.x = 170;
		openfl.Lib.current.addChild(fps);
		#end
		
		//helps on mobile to know wether app uses openfl or air
		var target = Browser.document.getElementById("target");
		#if air
		target.innerHTML = "AIR";
		#elseif flash
		target.innerHTML = "Flash";
		#elseif nme
		target.innerHTML = "NME";
		#elseif js
		target.innerHTML = "JS";
		#end
		
		//match width and height of css stylsheet
		boxWidth = 50;
		boxHeight = 50;
		
		containerHeight = Browser.window.innerHeight;
		containerWidth = Browser.window.innerWidth;
		
		//add a stylesheet and wait for it to be loaded before start
		//
		//note : added here instead of html because in NME, loading is synchronous
		//because it is local, so we need to add load listener before starting loading
		var link = Browser.document.createElement("link");
		link.addEventListener("load",
		function(e) {
			start();
			
		}, false);
		
		link.setAttribute("href", "style.css");
		link.setAttribute("type", "text/css");
		link.setAttribute("rel", "stylesheet");
		
		Browser.document.getElementsByTagName("head")[0].appendChild(link);
	}
	
	/**
	 * add a bunch of boxes
	 */
	function start() 
	{
		for (i in 0...500)
		{
			addTransitionBox();
		}
	}
	
	/**
	 * Moves a box randomly
	 */
	function transition(transitionBox:HtmlElement)
	{
		transitionBox.style.left = Std.string(Math.round(Math.random() * (containerWidth - boxWidth))) + "px";
		transitionBox.style.top = Std.string(Math.round(Math.random() * (containerHeight - boxHeight))) + "px";
	}
	
	/**
	 * create a new box
	 */
	function addTransitionBox()
	{
		var transitionBox = Browser.document.createElement("div");
		transitionBox.className = "trans";
		
		//random background color
		var randColor = function() {return Math.floor(Math.random() * 255); };
		transitionBox.style.backgroundColor = "rgb(" + randColor() + "," + randColor() + "," + randColor() + ")";
		
		//restart transition after end of current 
		//transition
		transitionBox.addEventListener("transitionend",
		function(e) {
			transition(cast transitionBox);
		},
		false);
		
		transitionBox.addEventListener("webkitTransitionEnd",
		function(e) {
			transition(cast transitionBox);
		},
		false);
		
		//add more boxes when one is clicked
		transitionBox.onclick = function(e) {
			addTransitionBox();
		}
		
		Browser.document.getElementById("container").appendChild(transitionBox);
		
		Timer.delay(function() {transition(cast transitionBox);}, 1000);
	}
}
