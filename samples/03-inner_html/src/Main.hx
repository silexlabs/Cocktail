/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import js.Lib;

/**
 * Use innerHTML to set html content of the body
 * after the document is created
 */
class Main
{
	static function main()
	{
		#if !js
		//init cocktail, and starts the load of the "index.html" file
		cocktail.api.Cocktail.boot();
		#end
		
		//when document is loaded, set the content of the body
		Lib.window.onload = function(e) Lib.document.body.innerHTML = "<h1 id='title' style='color:blue'>Inner HTML</h1><p>My page is built from HTML</p>";
	}
}

