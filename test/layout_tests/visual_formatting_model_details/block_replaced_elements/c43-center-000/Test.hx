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
		test += 	'<p>There should be a single small column of blue below with no red:</p>';
		test += 	'<div class="a" style="margin: 0; background: url(swatch-red.png) center repeat-y; font-size: 10px;">';
		test += 		'<img src="swatch-blue.png" alt="FAIL: Replaced content did not get replaced." style="display: block; margin-right: auto; margin-left: auto; width: auto;"/>';
		test += 	'</div>';
		test += 	'<div class="b" style="margin: 0; background: url(swatch-red.png) center repeat-y; font-size: 10px; text-align: center;">';
		test += 		'<img src="swatch-blue.png" alt="FAIL: Replaced content did not get replaced." style="vertical-align: top;"/>';
		test += 	'</div>';
		test += 	'<div class="c" style="margin: 0; background: url(swatch-red.png) center repeat-y; font-size: 10px; text-align: center; font: 15px/1 Ahem; color: blue;">X</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}