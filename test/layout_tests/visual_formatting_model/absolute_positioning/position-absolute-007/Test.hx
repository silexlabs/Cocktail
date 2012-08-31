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
 * TODO : fail text outside of orange box
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div>';
		test += '<p>Test passes if the "Filler Text" overflows below the orange box and overlaps the bottom blue box.</p>';
		test += '<div style="position:relative;">';
		test += '<div style="background-color:orange; top:0.5in; position:absolute; height:1in; width:1in;">';
		test += ' Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text ';
		test += '</div>';
		test += '<div style="background-color:blue; height:2in; width:0.5in; float:left;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}