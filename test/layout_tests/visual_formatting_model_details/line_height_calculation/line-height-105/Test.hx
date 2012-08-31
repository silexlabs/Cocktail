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
		var test = '<div><p>Test passes if the two boxes below are the same height.</p>';
		test += '<div style="position:relative; width:1em;">';
			test += '<div style="position:relative; width:1em; background-color:black;  font-size:12pt; line-height:96px; font-family:ahem;">X</div>';
			test += '<div style="position:absolute; left:1.2em; top:0; font-size:12pt; width:1em; background-color:black; font-family:ahem; height:96px;"></div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}