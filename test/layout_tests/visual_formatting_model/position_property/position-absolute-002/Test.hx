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
		var test = '<div><p>Test passes if the bottom-right quarter of the blue box is orange.</p>';
		test += '<div style="position:relative; background-color:blue; height:2in; width:2in;">';
		test += '<div style="background-color:orange; position:absolute; bottom:0; right:0; top:1in; left:1in;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}