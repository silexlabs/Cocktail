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
		test += 	'<p>Test passes if the blue box is larger than the black box.</p>';
		test += 	'<div style="font-size: 1in; font-family: Ahem; line-height: 1em;">X</div>';
		test += 	'<div id="test" style="font-size: 1in; font-family: Ahem; line-height: 1em; color: blue; font-weight: bold;">X</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}