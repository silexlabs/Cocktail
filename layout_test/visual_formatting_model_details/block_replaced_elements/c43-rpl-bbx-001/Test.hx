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
		test += 	'<p> Below this paragraph there should be a big blue square half the width of the window, aligned flush with the right hand side (⇨). </p>';
		test += 	'<p style="margin-left: 0; margin-right: 0; padding-left: 0; padding-right: 0; color: navy;">';
		test += 		'<img src="swatch-blue.png" alt="FAIL: Images required for this test." style="display: block; margin-right: 0; margin-left: auto; width: 50%;"/>';
		test += 	'</p>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}