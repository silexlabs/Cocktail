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
		var test = '<div><p>Test passes if the blue box is to the right of the orange box.</p>';
		test += '<div style="position:absolute; background-color:orange; height:1in; width:1in;"></div>';
		test += '<div style="position:relative; left:1in; background-color:blue; height:1in; width:1in;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}