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
 * TODO : work but line-height is wrong
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if there are six black boxes below and the last black box ends when the blue box ends.</p>';
		test += '<div>';
		test += '<div style="letter-spacing:1em; text-align:justify; width:6em; line-height:1em;">XXXXXX XXXXXX</div>';
		test += '<div style="background-color:blue; height:1em; width:11em;"></div>';
		test += '</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}