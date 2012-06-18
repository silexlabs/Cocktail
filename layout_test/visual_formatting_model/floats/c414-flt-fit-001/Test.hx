/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
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