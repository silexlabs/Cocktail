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
		test += '<div style="position:relative; font-size:12pt; font-family:ahem;">';
			test += '<div style="position:relative; font-size:12pt; font-family:ahem; color:red;">';
				test += '<span style="font-size:12pt; color:red; font-family:ahem; vertical-align:96px;">X</span>';
				test += 'X';
			test += '</div>';	
			test += '<div style="position:absolute; top:0; font-family:ahem; font-size:12pt;">X</div>';
			test += '<div style="position:absolute; left:1em; top:96px; font-family:ahem; font-size:12pt;">X</div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}