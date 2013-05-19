/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import js.Browser;

class Main
{
	static function main()
	{
		//init cocktail with the content of the index.html file,
		//no need for js, the browser takes care of it !
		#if !js
		cocktail.api.Cocktail.boot();
		#end
		
		//document and window now accessible
		Browser.window.onload = function(e) {
			 
			//document is now loaded
			var document = Browser.document;
		};
	}
}
