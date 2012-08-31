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
		var test = '<div><p>Test passes if the upper-half of the box below is blue.</p>';
		test += '<div style="width:200px; height:200px; position:absolute;" id="div1">';
		test += '<div style="position:absolute; background-color:blue; display:inline; height:50%; width:100%;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}