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
		var test = '<div>';
		test += '	<p>Test passes if the "Filler Text" below is aligned to the right side of the box.</p>';
		//test += '	<div id="parent" style="border: solid; text-align: right; width: 500px;">';
		test += '	<div id="parent" style="text-align: right; width: 500px;">';
        test += '		<div id="test" style="display: inline; text-align: left;">Filler Text Filler Text Filler Text Filler Text</div>';
		test += '	</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}