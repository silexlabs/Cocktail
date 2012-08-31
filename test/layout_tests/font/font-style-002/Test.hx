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
		var test = '<div>';
		test += 	'<p>Test passes if there is a box below that appears to be slanted to one side.</p>';
		test += 	'<div style="font-style: italic; font-family: Ahem;">X</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}