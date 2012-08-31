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
		var test = '<div><p>Test passes if there are two lines of "Filler Text" below.</p>';
		test += '<div style="display:block;">Filler Text</div>';
		test += '<div style="display:block;">Filler Text</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}