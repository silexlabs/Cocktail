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
		//should add black border
		var test = '<div><p>Test passes if the blue box is in the upper-right corner of the black box.</p>';
		test += '<div style="position:fixed; top:0; margin:50px;">';
		test += '<div style="height:1in; width:1in; margin:50px;">';
		test += '<div style="background-color:blue; height:1in; width:1in; position:absolute; right:0; top:0;"></div>';
		test += '</div></div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}