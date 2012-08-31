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

class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the line of "Filler Text" and all of the characters of the text are all in uppercase.</p>';
		test += '<div style="text-transform:uppercase">filler text Filler Text FILLER TEXT fILLER tEXT FiLlEr tExT</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}