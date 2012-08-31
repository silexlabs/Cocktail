/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package ;
import js.Lib;

/**
 * TODO : justified space width doesn't seem right
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		//TODO : should add border
		var test = '<div><p>Test passes if the words "Filler Text" are justified and spaced out on the first two lines of text inside the blue box. The final line of text does not have to be justified but can be based on user agent implementation.</p>';
		test += '<div style="text-align:justify; width:150px;">Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}