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
		//test += 	'<div id="div1" style="border: solid black; direction: ltr; height: 2in; width: 2in;">';
		test += 	'<div id="div1" style="direction: ltr; height: 2in; width: 2in;">';
		test += 		'<img alt="blue 15x15" src="blue15x15.png" style="margin-left: auto; margin-right: auto; left:auto; position: absolute; right:auto;"/>';
		test += 		'<div style="background: orange; height: 15px; margin-top: 15px; width: 15px;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}