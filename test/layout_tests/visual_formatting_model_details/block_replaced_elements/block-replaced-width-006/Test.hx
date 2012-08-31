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
		test += 	'<p>Test passes if the blue and orange boxes below are the same width, and they are horizontally centered inside the black box.</p>';
		//test += 	'<div id="div1" style="line-height: 0; border: solid black; height: 3in; width: 2in;">';
		test += 	'<div id="div1" style="line-height: 0; height: 3in; width: 2in;">';
		test += 		'<img alt="blue 15x15" src="blue15x15.png"  width="50%" style="display: block; margin-left: auto; margin-right: auto;"/>';
		test += 		'<div style="line-height: 0; color: orange; font: 1in/1em Ahem; text-align: center;">X</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}