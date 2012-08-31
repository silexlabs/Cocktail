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
		var test = '<div><p>Test passes if the orange box is above the blue box and both boxes are the same width.</p>';
		test += '<div style="background-color:blue; height:2in; position:relative; width:2in;">';
		test += '<div style="background-color:orange; bottom:0; top:0; right:0; left:0; position:static;">Filler Text</div>';
		test += '</div></div>';
		
		
		Lib.document.body.innerHTML = test;
	}
}