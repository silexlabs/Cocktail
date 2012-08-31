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
		var test = '<div><p>Test passes if there is no red visible on the page.</p>';
		test += '<div style="font-size:20px; width:5em; background-image:url(\'margin-collapse-2em-space.png\'); height:4em;">';
			test += '<div style="width:5em; margin-bottom:2em; background-color:green; height:1em; font-size:20px;"></div>';
			test += '<div style="width:5em; margin-top:1em; background-color:green; height:1em; font-size:20px;"></div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}