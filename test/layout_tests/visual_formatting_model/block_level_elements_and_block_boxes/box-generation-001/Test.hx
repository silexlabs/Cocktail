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
		var test = '<div><p>Test passes if the orange box is below the blue box and the yellow box is directly left of the orange box.</p>';
		test += '<div id="div1">';
		test += '<div style="background-color:blue; width:1in;">Block box</div>';
		test += '<span style="background-color:orange; width:1in;" id="span1">Inline box</span>';
		test += '<span style="background-color:yellow; float:left; width:0.5in;" id="span2">Float</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}