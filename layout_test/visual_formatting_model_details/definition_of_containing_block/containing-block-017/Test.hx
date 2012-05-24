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
		//should add black border
		/*var test = '';
		test += '<div>';
		test += 	'<p>Test passes if there is no red visible on the page.</p>';
		test += 	'<div style="border: solid silver; direction: ltr; margin-bottom: 20px; padding: 100px; width: 450px;">';
		test += 		'<span id="test" style="border: 5px solid silver; padding: 50px; position: relative;">';
		test += 			'<span id="first-box" style="color: silver;"><span id="tl-control" style="border-top: 30px solid red; margin-left: -50px; margin-right: 20px; padding: 20px 15px;"></span>Filler Text Filler Text Filler Text Filler Text</span>';
		test += 			'<span style="height: 30px; position: absolute; width: 30px; background: green; bottom: 0; right: 0;">BR</span>';
		test += 			'<span style="height: 30px; position: absolute; width: 30px; background: green; left: 0; top: 0;">TL</span>';
		test += 			'<span id="last-box" style="color: silver;">Filler Text Filler Text Filler Text Filler Text<span id="br-control" style="border-bottom: 30px solid red; margin-left: 20px; margin-right: -50px; padding: 20px 15px;"></span></span>';
		test += 		'</span>';
		test += 	'</div>';
		test += '</div>';*/
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if there is no red visible on the page.</p>';
		test += 	'<div style="direction: ltr; margin-bottom: 20px; padding: 100px; width: 450px;">';
		test += 		'<span id="test" style="padding: 50px; position: relative;">';
		test += 			'<span id="first-box" style="color: silver;"><span id="tl-control" style="margin-left: -50px; margin-right: 20px; padding: 20px 15px;"></span>Filler Text Filler Text Filler Text Filler Text</span>';
		test += 			'<span style="height: 30px; position: absolute; width: 30px; background: green; bottom: 0; right: 0;">BR</span>';
		test += 			'<span style="height: 30px; position: absolute; width: 30px; background: green; left: 0; top: 0;">TL</span>';
		test += 			'<span id="last-box" style="color: silver;">Filler Text Filler Text Filler Text Filler Text<span id="br-control" style="margin-left: 20px; margin-right: -50px; padding: 20px 15px;"></span></span>';
		test += 		'</span>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}