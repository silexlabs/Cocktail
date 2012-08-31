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
		test += 	'<p>There should be no red below.</p>';
		test += 	'<div style="width: 600px; height: 200px; background: red;">';
		test += 		'<p style="height: 100px; background: green;">';
		test += 			'<img src="swatch-green.png" height="100" alt="" style="vertical-align: bottom; float: left;"/>';
		test += 			'<img src="swatch-green.png" alt="Image support required for this test" style="vertical-align: bottom; width: 100%; height: 100px;"/>';
		test +=			'</p>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}