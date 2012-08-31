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
		var test = '<div><p>Test passes if there are only two boxes below (with no jagged edges).</p>';
		test += '<div>';
		test += '<div>';
		test += '<span style="font-size:12pt;">x</span>';
		test += '<span style="margin-left:84pt;">x</span>';
		test += '</div>';
		test += '<div style="word-spacing:96px; font-size:12pt;">x x</div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}