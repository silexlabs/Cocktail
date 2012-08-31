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
		var test = '<div><p>Test passes if there is a large orange box that covers the bottom-right corner of the blue box and continues to the right side and the bottom of the page.</p>';
		test += '<div style="position:relative; background-color:blue; height:2in; width:2in;">';
		test += '<div style="background-color:orange; position:fixed; bottom:0; right:0; top:1in; left:1in;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}