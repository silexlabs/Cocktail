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
		test += 	'<p>Test passes if there is a square below.</p>';
		test += 	'<div id="div1" style="background: black; display: inline-block; height: 1in; min-width: 1in;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}