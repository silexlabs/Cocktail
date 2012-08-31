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
		var test = '<div><p>Test passes if the two lines of "Filler Text" below have the same (upper/lower) case for each letter.</p>';
		test += '<div>filler text Filler Text FILLER TEXT fILLER tEXT FiLlEr tExT</div>';
		test += '<div style="text-transform:none">filler text Filler Text FILLER TEXT fILLER tEXT FiLlEr tExT</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}