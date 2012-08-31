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
		test += 	'<p>Test passes if the two boxes below are the same width.</p>';
		test += 	'<div id="div1" style="width: 1in;">';
		test += 		'<div id="div2" style="background: black; height: 1in; max-width: 100%;"></div>';
		test += 		'<div id="div3" style="border-left: 1in solid black; height: 1in; margin-top: 10px;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}