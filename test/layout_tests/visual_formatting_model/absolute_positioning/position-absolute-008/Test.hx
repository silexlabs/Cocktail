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
		test += '<div style="position:relative; ">';
		test += '<div style="background-color:red; height:1in; width:1in;"></div>';
		test += '<div style="background-color:green; height:1in; width:1in; top:0; left:0; float:right; position:absolute;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}