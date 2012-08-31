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
		var test = '<div><p>Test passes if a background starts and ends where the content starts and ends below.</p>';
		test += '<div>';
		test += '<span style="background-color:orange;">Filler Text Filler Text</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}