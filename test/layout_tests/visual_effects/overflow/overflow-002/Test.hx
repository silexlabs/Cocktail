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
		test += 	'<p>Test passes if there is no red visible on the page.</p>';
		test += 	'<div style="border: 3px solid orange; height: 0; overflow: hidden; width: 1in;">';
		//test += 	'<div style="height: 0; overflow: hidden; width: 1in;">';
		test += 		'<div style="background: red; height: 2in; width: 2in;">';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}