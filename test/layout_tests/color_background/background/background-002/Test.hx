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
		test += 	'<p>Test passes if there is a green box below.</p>';
		//test += 	'<div style="background: url(\'http://test.csswg.org/suites/css2.1/20110323/xhtml1/support/green_box.png\'); height: 50px;"></div>';
		test += 	'<div style="background: url(\'green_box.png\'); height: 50px;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}