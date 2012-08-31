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
		test += 	'<p>There should be no red below, just two 300&times;100 pixel green rectangles seperated by 1em of margin.</p>';
		test += 	'<div style="width: 300px; height: 100px; background: red;">';
		test += 		'<p style="width: 200%;">';
		test += 			'<img src="1x1-green.png" alt="Image support required for this test" style="width: 50%; height: 100px; vertical-align: bottom;"/>';
		test +=			'</p>';
		test += 	'</div>';
		test += 	'<div style="width: 300px; position: relative;">';
		test += 		'<p style="width: 200%;">';
		test += 			'<img src="1x1-green.png" alt="Image support required for this test" style="width: 50%; height: 100px; vertical-align: bottom;"/>';
		test += 			'<span style="position: absolute; top: 0; left: 0; background: green; width: 300px; height: 100px;"></span>';
		test +=			'</p>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}