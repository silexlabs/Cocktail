/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import js.Lib;
import js.Dom;

/**
 * DOM serialise/deserialize
 */
class Main
{
	
	public function new()
	{
		Lib.document.body.innerHTML = "<h1 id='title' style='color:blue'>Inner HTML</h1><p>My page is built from HTML</p>";
		
	}

}
