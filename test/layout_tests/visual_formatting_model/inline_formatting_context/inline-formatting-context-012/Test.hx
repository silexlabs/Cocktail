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
 * TODO : fail because whitespace is not supported by the parser
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if there are two separate lines of "Filler Text" below.</p>';
		test += '<div style="width:50px">';
		test += '<span style="white-space:nowrap"> Filler Text </span>';
		test += '<span style="white-space:nowrap"> Filler Text </span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}