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
		test += 	'<div id="div1" style="font: 20px/1 Ahem; background: black; height: 1in; min-width: 6em; width: 0;"></div>';
		test += 	'<div id="div2" style="font: 20px/1 Ahem; border-left: 6em solid black; height: 1in; margin-top: 10px;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}