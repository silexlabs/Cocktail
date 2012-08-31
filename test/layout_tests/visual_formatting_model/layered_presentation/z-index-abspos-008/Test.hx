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
		var test = '';
		test += '<div style="position: absolute; width: 4em; height: 4em;">';
		test += 	'<div style="position: absolute; width: 4em; height: 4em; top: 1em; left: 1em; width: 12em; height: 12em; background: gray;">';
		test += 		'<div style="position: absolute; width: 4em; height: 4em; top: 1em; left: 4em; background: blue;">';
		test += 			'<div class="c" style="position: absolute; width: 4em; height: 4em; top: 3em; left: -3em; background: lime; z-index: 2;">';
		test += 			'</div>';
		test += 		'</div>';
		test += 		'<div class="d" style="position: absolute; width: 4em; height: 4em; top: 4em; left: 7em; background: orange;">';
		test += 			'<div class="e" style="position: absolute; width: 4em; height: 4em; top: 3em; left: -3em; background: yellow; z-index: 1;">';
		test += 			'</div>';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}
