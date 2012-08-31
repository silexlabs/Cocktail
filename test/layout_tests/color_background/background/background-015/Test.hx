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
		test += 	'<p>Test passes if the box below has a cat image repeated across the screen, but not down the screen (there is not a cat on top of a cat).</p>';
		//test += 	'<div style="background: repeat-x url(\'http://test.csswg.org/suites/css2.1/20110323/xhtml1/support/cat.png\'); border: 1px solid black; height: 200px;"></div>';
		test += 	'<div style="background: repeat-x url(\'cat.png\'); border: 1px solid black; height: 200px;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}