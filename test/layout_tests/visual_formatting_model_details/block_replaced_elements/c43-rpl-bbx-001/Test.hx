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
		test += 	'<p> Below this paragraph there should be a big blue square half the width of the window, aligned flush with the right hand side (⇨). </p>';
		test += 	'<p style="margin-left: 0; margin-right: 0; padding-left: 0; padding-right: 0; color: navy;">';
		test += 		'<img src="swatch-blue.png" alt="FAIL: Images required for this test." style="display: block; margin-right: 0; margin-left: auto; width: 50%;"/>';
		test += 	'</p>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}