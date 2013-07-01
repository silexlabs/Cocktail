
/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import js.Browser;
import js.html.HtmlElement;

/**
 * Showcase the Selector API (a standard API, sismilar to jQuery selectors)
 * http://www.w3.org/TR/selectors-api/
 */
class Main
{
	static function main()
	{
		#if !js
		//init cocktail, and starts the load of the "index.html" file
		cocktail.api.Cocktail.boot();
		#end
		
		Browser.window.onload = function(e) new Main();
	}
	
	public function new() 
	{
		//get all the node in the document which matches the provided selector
		//and append text to them
		//
		//You can use this method on any node with any CSS selector
		for (node in Browser.document.querySelectorAll("#content p[class].visible"))
		{
			var htmlElement : HtmlElement = cast(node);
			htmlElement.innerHTML += "with the class " + htmlElement.classList[0];
		}
		
		//multiple selectors can be provided by comma-separate them
		for (node in Browser.document.querySelectorAll("#content p[class], #content .visible"))
		{
			var htmlElement : HtmlElement = cast(node);
			htmlElement.innerHTML += "!!!";
		}
		
		//this API can be used on any node. 
		//the querySelector method does the same thing but
		//return only the first match or null if no match
		var first = Browser.document.getElementById("content")
		                            .querySelector(".visible")
									.innerHTML += " And I'm the first";
	}
}
