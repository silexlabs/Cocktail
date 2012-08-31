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
		test += 	'<p>Test passes if there is <strong>a green square</strong> and <strong>no red</strong>.</p>';
		test += 	'<div style="width: 100px; height: 100px; overflow: hidden; position: absolute;">';
		test += 		'<div style="width: 100px; height: 100px; position: fixed; left: 100px; top: 100px;">';
		test += 			'<div style="width: 100px; height: 100px; left: 100px; top: 100px; background-color: green; position: absolute;"></div>';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}