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
 * TODO : fail because body margin are applied to absolute element
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		//should add black border
		var test = '<div><p>Test passes if the blue box below is in the bottom-left corner of the page.</p>';
		test += '<div style="margin:1in">';
		test += '<div style="margin:1in">';
		test += '<div style="background-color:blue; bottom:0; height:1in; left:0; position:absolute; width:1in;"></div>';
		test += '</div></div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}