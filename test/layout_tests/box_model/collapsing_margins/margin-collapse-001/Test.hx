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
		var test = '<div><p>Test passes if the blue and orange boxes have the same horizontal spacing between them.</p>';
		test += '<div>';
			test += '<span style="color:blue; margin:5em; font-size:20px;">XXXXX</span>';
			test += '<span style="color:blue; margin:5em; font-size:20px;">XXXXX</span>';
		test += '</div>';
		test += '<div>';
			test += '<span style="color:white; font-size:20px;">XXXXX</span>';
			test += '<span style="color:orange; font-size:20px;">XXXXX</span>';
			test += '<span style="color:white; font-size:20px;">XXXXXXXXXX</span>';
			test += '<span style="color:orange; font-size:20px;">XXXXX</span>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}