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
		test += '<div style="display:block; background-color:red; width:100px; height:100px;">';
		test += '<div style="background-color:green; height:100%; width:100%; position:relative;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}