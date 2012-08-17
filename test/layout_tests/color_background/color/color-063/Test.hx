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
		test += 	'<p>Test passes if the boxes below are the same color.</p>';
		//test += 	'<div id="test" style="height: 1in; width: 1in; color: rgb(128, 128, 128); font: 1in Ahem;">X</div>';
		test += 	'<div id="test" style="height: 1in; width: 1in; color: #123456; font-size: 1in; font-family: Ahem;">X</div>';
		test += 	'<div id="reference" style="height: 1in; width: 1in; background-color: #123456; margin-top: 10px;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}