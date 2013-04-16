/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import cocktail.api.Cocktail;
import js.Lib;

class Main
{
	static function main()
	{
		//init cocktail with the content of the index.html file
		Cocktail.boot();
		
		//document and window now accessible
		Lib.window.onload = function(e) {
			 
			//document is now loaded
			var document = Lib.document;
			
		};
	}
}
