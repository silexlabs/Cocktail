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
 * TODO : test is incomplete
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if below the yellow box is on the left-hand side of the blue box and the orange box is on the right-hand side fo the blue box.</p>';
		test += '<div>';
		test += '<span id="span1" style="color: orange; font-size: 16px; font-family: Ahem;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
		test += '<span id="span2" style="font-size: 16px; font-family: Ahem;color: yellow;position: relative;left: -6em;"> XXXXXX </span>XXXXXX</span > ';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}