/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package ;
import js.Lib;

/**
 * TODO : fail because div should be inline and other elements are not wrapped
 * in anonymous block
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the letter "a" is below the blue line and the letter "b" is above.</p>';
		test += '<div>';
		test += '<div style="position:relative; top:24px; width:200px; height:2px; left:0; background-color:blue;"></div>';
		test += '<span style="position:relative; top:25px;">a</span>';
		test += '<span>b</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}