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
		test += 	'<p>There must be a green box below and no red.</p>';
		test += 	'<div style="position: absolute; height: 150px; width: 400px; background: green; z-index: auto;"></div>';
		test += 	'<div style="position: absolute; height: 100px; width: 300px; background: red; z-index: -1;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}