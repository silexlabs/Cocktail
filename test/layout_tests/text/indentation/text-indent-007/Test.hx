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
 * TODO : doesn't work because text indent not implemented in inline formatting context
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if there is one black box on this page (with no jagged edges).</p>';
		test += '<div>';
		test += '<div style="margin-left:96px; font-size:16px;">xx</div>';
		test += '<div style="text-indent:96px; font-size:16px;">xx</div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}