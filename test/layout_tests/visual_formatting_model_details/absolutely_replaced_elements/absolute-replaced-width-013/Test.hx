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
		//test += 	'<div id="div1" style="border: solid black; height: 3in; width: 2in; position: relative;">';
		test += 	'<div id="div1" style="direction: ltr; line-height: 0; height: 3in; width: 2in; position: relative;">';
		test += 		'<img alt="blue 15x15" src="blue15x15.png" style="margin-left: auto; margin-right: auto; position: absolute; width:50%;"/>';
		test += 		'<div style="line-height: 0; background: orange; height: 1in; margin-top: 1in; width: 1in;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}