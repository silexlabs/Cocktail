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
		//TODO : should be updated with a block border
		var test = '<div><p>Test passes if all the words "Filler Text" are on the same line and they are contained by a black box.</p>';
		test += '<div style="width:600px;">';
		test += '<div style="display:inline;">Filler Text </div>';
		test += '<div style="display:inline;">Filler Text </div>';
		test += '<div style="display:inline;">Filler Text </div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
		Lib.document.body.style.marginTop = "0";
	}
}