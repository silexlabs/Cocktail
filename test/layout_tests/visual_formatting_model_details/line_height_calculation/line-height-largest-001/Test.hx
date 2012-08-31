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
 * TODO : fail because text not align to baseline
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
		test += '<div style="background-color:blue;">';
			test += '<span style="font-size:0.5in; font-family:ahem;">Filler</span>';
			test += '<span style="font-size:2in;font-family:ahem; ">Text</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}