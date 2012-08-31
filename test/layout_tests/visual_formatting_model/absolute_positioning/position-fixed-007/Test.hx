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
 * TODO : doesnt work because of fixed
 */
class Test 
{
	
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p style="margin-top:1in">Test passes if there is a box in the upper-left corner of the page.</p>';
		test += '<div style="position:relative; ">';
		test += '<div style="background-color:black; left:0; top:0; float:right; position:fixed; height:1in; width:1in;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}