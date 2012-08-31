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
		// TODO borders to add
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if the blue background overlaps the orange border on the bottom and right sides.</p>';
		test += 	'<div style="border: 3px solid orange; height: 1in; overflow: visible; width: 1in;">';
		//test += 	'<div style="height: 1in; overflow: visible; width: 1in;">';
		test += 		'<div style="background: blue; height: 2in; width: 2in;">';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}