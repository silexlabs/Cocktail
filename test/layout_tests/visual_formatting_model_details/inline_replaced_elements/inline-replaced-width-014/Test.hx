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
		test += 	'<p>There should be no red below, just two 300&times;100 pixel green rectangles seperated by 1em of margin.</p>';
		test += 	'<div style="width: 300px; height: 100px; background: red;">';
		test += 		'<p style="width: 200%;">';
		test += 			'<img src="1x1-green.png" alt="Image support required for this test" style="width: 50%; height: 100px; vertical-align: bottom;"/>';
		test +=			'</p>';
		test += 	'</div>';
		test += 	'<div style="width: 300px; position: relative;">';
		test += 		'<p style="width: 200%;">';
		test += 			'<img src="1x1-green.png" alt="Image support required for this test" style="width: 50%; height: 100px; vertical-align: bottom;"/>';
		test += 			'<span style="position: absolute; top: 0; left: 0; background: green; width: 300px; height: 100px;"></span>';
		test +=			'</p>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}