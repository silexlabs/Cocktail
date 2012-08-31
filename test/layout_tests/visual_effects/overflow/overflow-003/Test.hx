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
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if the box below can be scrolled to the green square in the bottom-right corner.</p>';
		test += 	'<div style="height: 1in; overflow: scroll; width: 1in;">';
		test += 		'<div style="height: 2in; position: relative; width: 2in;">';
		test += 			'<div style="background: green; bottom: 0; height: 20px; position: absolute; right: 0; width: 20px;"></div>';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}