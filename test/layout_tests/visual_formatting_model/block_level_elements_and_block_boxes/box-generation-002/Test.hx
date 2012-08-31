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
 * TODO : fail because of float support
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the orange box is to the left of the blue box and both boxes are above the yellow box.</p>';
		test += '<div>';
		test += '<span style="background-color:blue; width:1in;">Inline box</span>';
		test += '<div style="background-color:orange; float:left; width:0.5in;" id="div1">Float</div>';
		test += '<div style="background-color:yellow" id="div2">Block box</div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}