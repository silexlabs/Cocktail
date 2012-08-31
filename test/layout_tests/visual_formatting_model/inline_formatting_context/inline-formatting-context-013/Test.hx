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
		test += 	'<p>Test passes if there is no vertical space between the green and blue boxes.</p>';
		test += 	'<div style="background: red; font: 20px/1em Ahem; height: 5em; width: 5em;">';
		test += 		'<span class="color1" style="color: green;">XXXXX</span>';
		test += 		'<span class="color2" style="color: blue;">XXXXX</span>';
		test += 		'<span class="color1" style="color: green;">XXXXX</span>';
		test += 		'<span class="color2" style="color: blue;">XXXXX</span>';
		test += 		'<span class="color1" style="color: green;">XXXXX</span>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}