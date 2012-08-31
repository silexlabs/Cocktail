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
		test += '<div style="width:2in;">';
		test += '<span style="background-color:orange; display:block; height:1in; width:1in;"></span>';
		test += '<span style="background-color:blue; display:block; height:1in; width:1in; position:relative; right:-1in; top:-1in;"></span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}