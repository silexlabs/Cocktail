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
 * TODO : test is incomplete
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		var test = '<div><p>Test passes if below the yellow box is on the left-hand side of the blue box and the orange box is on the right-hand side fo the blue box.</p>';
		test += '<div>';
		test += '<span id="span1" style="color: orange; font-size: 16px; font-family: Ahem;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
		test += '<span id="span2" style="font-size: 16px; font-family: Ahem;color: yellow;position: relative;left: -6em;"> XXXXXX </span>XXXXXX</span > ';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}