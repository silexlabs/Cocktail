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
		//TODO : should add border
		var test = '<div><p>Test passes if the words "Filler Text" below are aligned to the right, inside the blue box.</p>';
		test += '<div style="text-align:right">Filler Text</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}