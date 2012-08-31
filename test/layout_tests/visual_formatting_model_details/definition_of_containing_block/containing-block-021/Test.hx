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
		var test = '<div><p>Test passes if the blue box is in the lower-right corner of the black box.</p>';
		test += '<div style="position:fixed; width:0; padding:1in;">';
		test += '<span style="display:block;">';
		test += '<span style="background-color:blue; height:1in; width:1in; position:absolute; display:block;"></span>';
		test += '</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}