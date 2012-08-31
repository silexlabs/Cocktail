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
 * TODO : fail blue box is not right under orange box, because of body margin
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
		test += '<div style="position:relative; width:2in; height:2in;">';
		test += '<div style="background-color:orange; left:1in; position:absolute; height:1in; width:1in;">';
		test += '<div style="background-color:blue; height:1in; width:1in; top:1in; position:relative;"></div>';
		test += '</div></div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}