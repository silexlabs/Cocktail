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
		// TO DO: borders to add
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if after scrolling down, all four edges of the blue box are visible.</p>';
		test += 	'<div id="div1" style="height: 1.5in; position: relative; overflow: scroll; width: 1.5in;">';
		//test += 		'<div style="background-color:blue; border: solid blue 5px; height: 1in; position: relative; top: 1in; width: 1in;"></div>';
		test += 		'<div style="background-color:blue; height: 1in; position: relative; top: 1in; width: 1in;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}