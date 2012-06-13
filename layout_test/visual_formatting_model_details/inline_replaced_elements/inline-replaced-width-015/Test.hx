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
		test += 	'<p>There should be no red below, just two 300x200 pixel lime rectangles.</p>';
		test += 	'<div style="width: 300px; height: 200px; background: red; position: relative;">';
		test += 		'<div style="width: 300px; height: 100px; background: lime;">';
		test += 			'<p style="width: 125%; height: 100px;">';
		test += 				'<img src="1x1-lime.png" alt="" style="vertical-align: bottom; float: left; height: 100px; width: 100px;"/>';
		test += 				'<img src="1x1-lime.png" alt="Image support required for this test" style="vertical-align: bottom; width: 80%; height: 100px;"/>';
		test +=				'</p>';
		test += 		'</div>';
		test += 	'</div>';
		test += 	'<div style="width: 300px; height: 200px; background: red; position: relative;">';
		test += 		'<div style="width: 300px; height: 100px; background: lime;">';
		test += 			'<p style="width: 125%; height: 100px;">';
		test += 				'<img src="1x1-lime.png" alt="" style="vertical-align: bottom; float: left; height: 100px; width: 100px;"/>';
		test += 				'<img src="1x1-red.png" alt="Image support required for this test" style="vertical-align: bottom; width: 80%; height: 100px;"/>';
		test += 				'<span style="position: absolute; bottom: 0; left: 0; background: lime; height: 100px; width: 300px;"></span>';
		test +=				'</p>';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}