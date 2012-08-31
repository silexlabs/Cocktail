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
		test += 	'<div style="font-size: 1em; font-family:serif;position: absolute; z-index: 2; top: 2em; left: 2em; width: 13em; background: green; color: white; padding: 1em;" > There should be no red, nor any scroll bars, on this page. </div> ';
		test += 	'<select style="position: absolute; z-index: 1; top: 2.5em; left: 2.5em; background: red; color: yellow; height: 3em;" size="3">';
		test += 		'<option style="font-size: 1em; font-family:serif;">FAIL FAIL FAIL FAIL</option>';
		test += 		'<option style="font-size: 1em; font-family:serif;">FAIL FAIL FAIL FAIL</option>';
		test += 		'<option style="font-size: 1em; font-family:serif;">FAIL FAIL FAIL FAIL</option>';
		test += 	'</select>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}