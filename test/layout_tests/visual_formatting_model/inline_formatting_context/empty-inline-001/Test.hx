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
		var test = '<div><p>Test passes if there is no red on this page.</p>';
		test += '<div>';
		test += '<span style="background-color:red; display:inline;"></span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}