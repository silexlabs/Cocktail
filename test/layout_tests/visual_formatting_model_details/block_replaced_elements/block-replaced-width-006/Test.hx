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
		// TODO borders to add
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if the blue and orange boxes below are the same width, and they are horizontally centered inside the black box.</p>';
		//test += 	'<div id="div1" style="line-height: 0; border: solid black; height: 3in; width: 2in;">';
		test += 	'<div id="div1" style="line-height: 0; height: 3in; width: 2in;">';
		test += 		'<img alt="blue 15x15" src="blue15x15.png"  width="50%" style="display: block; margin-left: auto; margin-right: auto;"/>';
		test += 		'<div style="line-height: 0; color: orange; font: 1in/1em Ahem; text-align: center;">X</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}