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
		var test = '<div>';
		test += 	'<p>Test passes if the two boxes below are the same size.</p>';
		test += 	'<div id="div1" style="font-family: Ahem; font-size: 1in; line-height: 1em; position: relative;">';
		test += 		'<div id="div2" style="font-size: 100%; width: 1in;">X</div>';
		test += 		'<div id="div3" style="border-top: 1in solid black; left: 1.1in; position: absolute; top: 0; width: 1in;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}