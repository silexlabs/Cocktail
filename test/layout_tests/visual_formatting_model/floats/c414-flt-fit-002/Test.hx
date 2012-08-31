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
		//test += 	'<p>The blue boxes below should be in numeric order and form a "D". (Boxes labelled "A" should be in the first column; boxes labelled "B" should be in the second; arrows indicate the correct alignment.)</p>';
		var test = 	'<div style="width:200px; margin:10px;">';
		test +=			'<p style="margin:0; float:left; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' A 1 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' B 2 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' A 3 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:right; text-align:right; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' B 4 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' A 5 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:right; text-align:right; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' B 6 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:right; text-align:right; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' B 8 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' A 7 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' A 9 ';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; margin:5px; padding:5px; width:50px; background-color:navy;">';
		test +=				' B 10 ';
		test +=			'</p>';
		test += 	'</div>';
		//test += '</div>';
		
		Lib.document.body.innerHTML = test;
		Lib.document.body.style.marginTop = "0";
		Lib.document.body.style.marginLeft = "0";
		Lib.document.body.style.marginRight = "0";
		Lib.document.body.style.marginBottom = "0";
	}
}