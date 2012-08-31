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
 * TODO : fail because div should be inline and other elements are not wrapped
 * in anonymous block. Works when wrapping spans in a div
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the letter "a" is below the blue line and the letter "b" is above.</p>';
		test += '<div>';
		test += '<div style="position:relative; top:24px; width:200px; height:2px; left:0; background-color:blue;"></div>';
		test += '<span style="position:relative; top:25px;">a</span>';
		test += '<span>b</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}