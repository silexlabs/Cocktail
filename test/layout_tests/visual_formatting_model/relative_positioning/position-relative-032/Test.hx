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
		var test = '<div><p>Test passes if "Filler Text1" and "Filler Text3" are on the first line and "Filler Text2" is on the second line and the space has been reserved where "Filler Text2" would have been if it were on the first line.</p>';
		test += '<div>';
		test += '<span>';
		test += 'Filler Text1';
		test += '<span style="position:relative; top:25px; left:0;"> Filler Text2 </span>';
		test += 'Filler Text3';
		test += '</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}