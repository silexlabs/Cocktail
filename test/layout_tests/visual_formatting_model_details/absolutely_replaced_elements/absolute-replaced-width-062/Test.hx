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
		test += 	'<p>Test passes if the blue and orange boxes below are the same width, and the blue box is in the upper-left corner of the black box.</p>';
		//test += 	'<div id="div1" style="direction: rtl; border: solid black; height: 3in; width: 2in; position: relative;">';
		test += 	'<div id="div1" style="direction: rtl; line-height: 0; height: 3in; width: 2in; position: relative;">';
		test += 		'<img alt="blue 15x15" src="blue15x15.png" style="margin-left: 0.25in; margin-right: auto; position: absolute; left: 0.25in; right: 0.5in; width:50%;"/>';
		test += 		'<div style="line-height: 0; background: orange; height: 1in; margin-left: 0.5in; margin-right: 0.5in; margin-top: 1in; width: 1in;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}