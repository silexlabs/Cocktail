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
		var test = '<div><p>Test passes if the box below contains three lines of "Filler Text".</p>';
		test += '<div id="div1">';
		test += '<div>Filler Text</div>';
		test += '<div>Filler Text</div>';
		test += '<div>Filler Text</div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}