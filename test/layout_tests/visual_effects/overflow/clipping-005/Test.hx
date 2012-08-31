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
		test += 	'<div style="overflow: hidden; width: 100px; height: 100px; background-color: green; position: relative;">';
		test += 		'<div style="width: 100px; height: 100px; margin-top: 100px; margin-left: 100px; background-color: red;"></div>';
		test += 		'<div style="width: 100px; height: 100px; margin-top: 100px; margin-left: 100px; background-color: red; position: relative;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}