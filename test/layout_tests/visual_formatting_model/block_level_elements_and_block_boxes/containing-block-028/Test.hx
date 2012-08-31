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
		var test = '<div><p>Test passes if the orange box is in the bottom right corner of the blue box.</p>';
		test += '<div style="background-color:blue; height:100px; position:absolute; width:100px;">';
		test += '<div style="background-color:orange; bottom:0; height:25px; right:0; width:25px; position:absolute;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}