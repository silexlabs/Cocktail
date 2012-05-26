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
 * TODO : fail because of float support
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if the orange box is below the blue box and the yellow box is directly left of the orange box.</p>';
		test += '<div id="div1">';
		test += '<div style="background-color:blue; width:1in;">Block box</div>';
		test += '<span style="background-color:orange; width:1in;" id="span1">Inline box</span>';
		test += '<span style="background-color:yellow; float:left; width:0.5in;" id="span2">Float</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}