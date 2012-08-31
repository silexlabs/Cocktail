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
		var test = '<div><p>Test passes if there is no red visible on the page.</p>';
		test += '<div style="height:1in; position:relative; width:2in;">';
		test += '<div style="background-color:red; height:1in; width:1in;"></div>';
		test += '<div style="background-color:green; position:absolute; left:0; top:0; height:1in; width:1in;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}