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

/**
 * TODO : doesn't work
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the black box below has an orange line below it.</p>';
		test += '<div style="height:3em; width:5em;">';
		test += '<div style="position:relative; top:16px; background-color:black;">Filler Text Filler Text Filler Text</div>';
		test += '<div style="background-color:orange;">Filler Text</div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}