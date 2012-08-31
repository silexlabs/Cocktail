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
		// TO DO: borders to add
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if after scrolling down, all four edges of the blue box are visible.</p>';
		test += 	'<div id="div1" style="height: 1.5in; position: relative; overflow: auto; width: 1.5in;">';
		//test += 		'<div style="background-color:blue; border: solid blue 5px; height: 1in; position: relative; top: 1in; width: 1in;"></div>';
		test += 		'<div style="background-color:blue; height: 1in; position: relative; top: 1in; width: 1in;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}