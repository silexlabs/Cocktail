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
 * TODO : fail, content not on the same lines
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div>';
		test += '<div>';
		test += 'Filler Text';
		test += '<div style="display:inline-block; height:50px; width:150px;">Filler Text Filler Text</div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}