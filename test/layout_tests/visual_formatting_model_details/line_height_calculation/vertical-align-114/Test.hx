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
		var test = '<div>';
		test += '<div style="position:relative; font-size:0.5in;">';
			test += '<div style="position:relative; font-size:4.5in;">';
				test += '<span style="font-size:0.5in; color:red; vertical-align:middle; font-family:ahem;">X</span>';
				test += '<span style="font-size:3.5in; font-family:ahem;">X</span>';
			test += '</div>';	
			//test += '<div style="position:absolute; top:0.75in; font-size:0.5in; font-family:ahem;">X</div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}