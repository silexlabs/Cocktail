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
		var test = '<div><p>Test passes if there is no vertical space between the boxes.</p>';
		test += '<div>';
			test += '<div style="background-color:blue; margin-bottom:2in; height:20px; width:50px;"></div>';
			test += '<div style="background-color:orange; margin-top:-2in; height:20px; width:50px;"></div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}