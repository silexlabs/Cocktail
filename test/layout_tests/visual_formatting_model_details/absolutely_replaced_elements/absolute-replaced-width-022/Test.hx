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
		//test += 	'<div id="div1" style="border: solid black; direction: ltr; height: 2in; width: 2in;">';
		test += 	'<div id="div1" style="direction: ltr; height: 2in; width: 2in; position: relative;">';
		test += 		'<img alt="blue 96x96" src="blue96x96.png" style="margin-left: auto; margin-right: auto; left:1in; position: absolute; right:auto;"/>';
		test += 		'<div style="background: orange; height: 96px; margin-left: 1in; margin-top: 96px; width: 96px;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}