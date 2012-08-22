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
		test += 	'<p>There should be a single small column of blue below with no red:</p>';
		test += 	'<div class="a" style="margin: 0; background: url(swatch-red.png) center repeat-y; font-size: 10px;">';
		test += 		'<img src="swatch-blue.png" alt="FAIL: Replaced content did not get replaced." style="display: block; margin-right: auto; margin-left: auto; width: auto;"/>';
		test += 	'</div>';
		test += 	'<div class="b" style="margin: 0; background: url(swatch-red.png) center repeat-y; font-size: 10px; text-align: center;">';
		test += 		'<img src="swatch-blue.png" alt="FAIL: Replaced content did not get replaced." style="vertical-align: top;"/>';
		test += 	'</div>';
		test += 	'<div class="c" style="margin: 0; background: url(swatch-red.png) center repeat-y; font-size: 10px; text-align: center; font: 15px/1 Ahem; color: blue;">X</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}