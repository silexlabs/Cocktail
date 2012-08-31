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
		var test = '<div>';
		test += 	'<p>Test passes if the boxes below are the same color.</p>';
		//test += 	'<div id="test" style="height: 1in; width: 1in; color: purple; font: 1in Ahem;">X</div>';
		test += 	'<div id="test" style="height: 1in; width: 1in; color: purple; font-size: 1in; font-family: Ahem;">X</div>';
		test += 	'<div id="reference" style="height: 1in; width: 1in; background-color: purple; margin-top: 10px;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}