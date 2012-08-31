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
		var test = '<div><p>Test passes if the blue and orange boxes below are the same height.</p>';
		test += '<div style="position:relative;">';
			test += '<img style="display:inline; line-height:2in;" src="blue96x96.png" />';
			test += '<div style="background-color:orange; height:96px; width:96px; left:1in; top:0; position:absolute;"></div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}