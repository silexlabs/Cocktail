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
		var test = '<div><p>Test passes if the letters below are all on the same line and they are in alphabetical order.</p>';
		test += '<div>';
		test += '<span style="position:relative;">a </span>';
		test += '<span>b </span>';
		test += '<span style="position:relative;">c </span>';
		test += '<span>d</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}