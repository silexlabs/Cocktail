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
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if the orange box is to the left of the blue box and the boxes top edges are aligned.</p>';
		test += 	'<div>';
		test += 		'<div style="float:left; height: 1in; width: 1in; background-color: orange"></div>';
		test += 		'<div style="float:left; height: 1in; width: 1in; background-color: blue"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}