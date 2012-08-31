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
		//var test = '';
		//test += '<div>';
		//test += 	'<p>There should be five numbers, in numerical order, below: on the first line 1, 2 and 3, on the second, 4 and 5.</p>';
		var test = 	'<div style="margin:10px; padding:1em; width:14em;">';
		test +=			'<p style="margin:0; float:left; width:5em;">';
		test +=				'1';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; width:5em;">';
		test +=				'2';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; width:5em;">';
		test +=				'4';
		test +=			'</p>';
		test +=			'3 5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
		test += 	'</div>';
		//test += '</div>';
		
		Lib.document.body.innerHTML = test;
		//Lib.document.body.style.marginTop = "0";
		//Lib.document.body.style.marginLeft = "0";
		//Lib.document.body.style.marginRight = "0";
		//Lib.document.body.style.marginBottom = "0";
	}
}