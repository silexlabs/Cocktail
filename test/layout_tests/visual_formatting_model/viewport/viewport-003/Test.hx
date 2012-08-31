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
		test += '<div style="direction: rtl;">';
		test += 	'<p>Test passes if this page can be scrolled to the words "Bottom of page".&lrm;</p>';
		test += 	'<div style="margin-top: 2000px;">Bottom of page</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}