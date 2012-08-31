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
		var test = '<div><p>Test passes if the orange box is within or overflows outside of the blue box.</p>';
		test += '<div style="height:1in; width:1in; padding-top:5px; background-color:blue;">';
		test += '<div style="height:0.5in; padding-top:5px; width:2in; background-color:orange;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}