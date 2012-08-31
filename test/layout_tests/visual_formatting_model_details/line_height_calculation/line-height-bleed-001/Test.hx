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
		var test = '<div><p>Test passes if the "Filler Text" below is completely visible without any clipping and there is no red visible on the page.</p>';
		test += '<div style="margin-top:1in; ">';
			test += '<div style="background-color:red;  line-height:0; font-size:1in; font-family:serif;">Filler Text</div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}