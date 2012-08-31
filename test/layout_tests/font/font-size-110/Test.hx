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
		test += 	'<p>Test passes if the blue box is larger than the orange box.</p>';
		test += 	'<div style="color: orange; font-family: Ahem; line-height: 1em;">';
		test += 		'<span id="span1" style="color: blue; font-size: larger;">X</span>';
		//test += 		'<span id="span1" style="color: blue;">X</span>';
		test += 		'<span>X</span>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}