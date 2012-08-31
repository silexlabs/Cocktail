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
		test += '<div style="height:100px; width:100px; background-color:red;">';
		test += '<div style="height:100px; width:100px; background-color:green;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}