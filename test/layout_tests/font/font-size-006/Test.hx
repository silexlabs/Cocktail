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
		test += 	'<p>Test passes if the two boxes below are the same size.</p>';
		test += 	'<div id="div1" style="font-family: Ahem; line-height: 1em; position: relative;">';
		test += 		'<div id="div2" style="font-family: Ahem; line-height: 1em; position: relative; font-size: 96px;">X</div>';
		test += 		'<div id="div3" style="font-family: Ahem; line-height: 1em; position: relative; border-top: 96px solid black; left: 1.1in; position: absolute; top: 0; width: 96px;"></div>';
		//test += 		'<div id="div3" style="font-family: Ahem; line-height: 1em; position: relative; left: 1.1in; position: absolute; top: 0; width: 96px;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}