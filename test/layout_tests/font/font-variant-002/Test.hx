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
		test += 	'<p>Test passes if the words below are rendered in small sized, uppercase characters.</p>';
		test += 	'<div style="font-variant: small-caps;">filler text</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}