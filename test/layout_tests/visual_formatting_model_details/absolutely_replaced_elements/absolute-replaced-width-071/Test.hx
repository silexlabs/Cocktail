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
		test += 	'<p>Test passes if the blue and orange boxes below are the same width, and the blue box is in the upper-right corner of the black box.</p>';
		//test += 	'<div id="div1" style="direction: rtl; border: solid black; height: 2in; width: 2in;">';
		test += 	'<div id="div1" style="direction: rtl; height: 2in; width: 2in; position: relative;">';
		test += 		'<img alt="blue 96x96" src="blue96x96.png" style="margin-left: 0.5in; margin-right: 0.25in; left:0.5in; position: absolute; right:0.25in;"/>';
		test += 		'<div style="background: orange; height: 96px; margin-left: 0.5in; margin-right: 0.5in; margin-top: 96px; width: 96px;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}