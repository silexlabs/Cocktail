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
		// TODO borders to add
		var test = '';
		test += '<div>';
		test += 	'<p>Below, there should be 2 orange boxes horizontally centered within their respective green bars.</p>';
		test += 	'<div style="background-color: green; margin: 1em;">';
		test += 		'<input type="button" value="         " style="background-color: orange; display: block; margin-left: auto; margin-right: auto; width: auto;"/>';
		test += 	'</div>';
		test += 	'<form action="">';
		test += 		'<div style="background-color: green; margin: 1em;">';
		test += 			'<input type="submit" value="         " style="background-color: orange; display: block; margin-left: auto; margin-right: auto; width: auto;"/>';
		test += 		'</div>';
		test += 	'</form>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}