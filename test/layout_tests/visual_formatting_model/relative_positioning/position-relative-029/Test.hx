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
		var test = '<div><p>Test passes if the "Filler Text" below is all on the same line.</p>';
		test += '<div style="width:5in">';
		test += '<span style="position:relative">Filler Text</span>';
		test += '<span> Filler Text</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}