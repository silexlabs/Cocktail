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

/**
 * TODO : fail because of fixed positioning relative to relative div instead of window
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if there is a blue box in the upper-right corner of the page.</p>';
		test += '<div style="position:relative; bottom:0;">';
		test += '<div style="background-color:blue; height:1in; width:1in; position:fixed; right:0; top:0;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}