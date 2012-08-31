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
		// TODO border to add
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if the box below can be scrolled to the words "Filler Text".</p>';
		//test += 	'<div style="border: solid; overflow: scroll; width: 200px;">';
		test += 	'<div style="overflow: scroll; width: 200px;">';
		test += 		'<span style="position: relative; left: 200px;">Filler Text</span>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}