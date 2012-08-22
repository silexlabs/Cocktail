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
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if there is no vertical space between the green and blue boxes.</p>';
		test += 	'<div style="background: red; font: 20px/1em Ahem; height: 5em; width: 5em;">';
		test += 		'<span class="color1" style="color: green;">XXXXX</span>';
		test += 		'<span class="color2" style="color: blue;">XXXXX</span>';
		test += 		'<span class="color1" style="color: green;">XXXXX</span>';
		test += 		'<span class="color2" style="color: blue;">XXXXX</span>';
		test += 		'<span class="color1" style="color: green;">XXXXX</span>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}