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
		test += 	'<p>Test passes if the blue and orange boxes below are the same width, and the blue box is in the upper-left corner of the black box.</p>';
		//test += 	'<div id="div1" style="border: solid black; height: 3in; width: 2in;">';
		test += 	'<div id="div1" style="height: 3in; width: 2in; line-height: 0;">';
		test += 		'<img alt="blue 96x96" src="blue96x96.png" style="margin-left: auto; margin-right: auto;"/>';
		test += 		'<div style="background: orange; height: 96px; width: 96px; line-height: 0;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}