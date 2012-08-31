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
		var test = '<div><p style="margin-top:1in;">Test passes if there is a box in the upper-left corner of the page.</p>';
		test += '<div style="position:relative;">';
		test += '<div style="top:3in; left:3in; height:1in; width:1in; position:absolute; ">';
		test += '<div style="background-color:black; height:1in; width:1in; top:0; left:0; position:fixed;"></div>';
		test += '</div></div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}