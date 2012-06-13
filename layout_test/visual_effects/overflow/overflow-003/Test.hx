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
		test += 	'<p>Test passes if the box below can be scrolled to the green square in the bottom-right corner.</p>';
		test += 	'<div style="height: 1in; overflow: scroll; width: 1in;">';
		test += 		'<div style="height: 2in; position: relative; width: 2in;">';
		test += 			'<div style="background: green; bottom: 0; height: 20px; position: absolute; right: 0; width: 20px;"></div>';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}