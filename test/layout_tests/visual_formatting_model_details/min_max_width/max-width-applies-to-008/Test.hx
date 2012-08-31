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
		test += 	'<p>Test passes if there is no red visible on the page.</p>';
		test += 	'<div style="background: red; display: inline; height: 1in; max-width: 1in; width: 3in;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}