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
		test += 	'<p>Test passes if the two boxes below are the same size.</p>';
		test += 	'<div id="div1" style="font-family: Ahem; font-size: 1in; line-height: 1em; position: relative;">';
		test += 		'<div id="div2" style="font-size: 100%; width: 1in;">X</div>';
		test += 		'<div id="div3" style="border-top: 1in solid black; left: 1.1in; position: absolute; top: 0; width: 1in;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}