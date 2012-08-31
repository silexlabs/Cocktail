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
 * TODO : fail because blue box not below orange box, because of body margin
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the blue box is directly below the orange box.</p>';
		test += '<div style="height:2in; position:relative; width:2in;">';
		test += '<div style="background-color:blue; height:2in; width:1in; position:absolute; left:1in;">';
		test += '<div style="background-color:orange; height:1in; width:1in;"></div>';
		test += '</div></div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}