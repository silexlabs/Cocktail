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
 * an HTML form sample
 * 
 * note : form elements (buttons, checkboxes...) have by default no style in cocktail,
 * in this sample they are skinned using the "sober" CSS theme, which you can find in 
 * the themes folder
 */
class Main
{
	static function main()
	{
		//init cocktail with the content of the index.html file
		cocktail.api.Cocktail.boot("res/index.html");
	}
}
