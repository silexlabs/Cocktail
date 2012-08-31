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
		//test += 	'<p>There should be a complete unbroken drawing of a yin-yang (☯) symbol below, slightly on the left (⇦) inside a blue box.</p>';
		var test = 	'<div style="width:250px">';
		test +=			'<p style="margin:0; float:left; height:100px; width:100px; line-height:0">';
		test +=				'<img src="test-tl.png" />';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; height:100px; width:100px; line-height:0">';
		test +=				'<img src="test-tr.png" />';
		test +=			'</p>';
		test +=			'<p style="margin:0; float:left; height:100px; width:100px; line-height:0">';
		test +=				'<img src="test-bl.png" />';
		test +=			'</p>';
		test +=			'<img src="test-br.png"  /> ';
		test += 	'</div>';
		//test += '</div>';
		
		Lib.document.body.innerHTML = test;
		//Lib.document.body.style.marginTop = "0";
		//Lib.document.body.style.marginLeft = "0";
		//Lib.document.body.style.marginRight = "0";
		//Lib.document.body.style.marginBottom = "0";
	}
}