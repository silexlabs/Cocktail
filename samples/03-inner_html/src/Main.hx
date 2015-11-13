package src;
/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

/**
 * Use innerHTML to set html content of the body
 * after the document is created
 */
class Main
{
	static function main()
	{
		//init cocktail, and starts the load of the "index.html" file
		cocktail.api.Cocktail.boot("res/index.html");
		
		//when document is loaded, set the content of the body
        cocktail.Browser.window.onload = function(e) {
            cocktail.Browser.document.body.innerHTML = "<h1 id='title' style='color:blue'>Inner HTML</h1><p>My page is built from HTML</p>";
        }
            
	}
}

