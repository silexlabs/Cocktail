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
		var test = '<div><p>Test passes if there is a large orange box that covers the bottom-right corner of the blue box and continues to the right side and the bottom of the page.</p>';
		test += '<div style="position:relative; background-color:blue; height:2in; width:2in;">';
		test += '<div style="background-color:orange; position:fixed; bottom:0; right:0; top:1in; left:1in;"></div>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}