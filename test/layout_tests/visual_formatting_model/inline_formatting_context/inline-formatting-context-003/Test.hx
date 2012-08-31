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
 * TODO : fail because of inline div not wrapped in anonymous block.
 * Works when removing the "p" element
 * 
 * TODO : difference of one added space because of lack of white space processing
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
		test += '<div style="background-color:black; display:inline; line-height:1em;">';
		test += '<div style="background-color:white; margin-right:100px; display:inline; line-height:1em;">Filler Text </div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}