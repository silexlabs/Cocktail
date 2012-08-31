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
 * TODO : slightly false
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the orange box is vertically centered inside the blue box.</p>';
		test += '<div style="width:2in; background-color:blue; font-size:1in; ">';
		test += '<span style="color:orange; line-height:5in; font-size:1in; font-family:ahem;">X</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}