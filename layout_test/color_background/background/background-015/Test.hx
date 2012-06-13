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
		test += 	'<p>Test passes if the box below has a cat image repeated across the screen, but not down the screen (there is not a cat on top of a cat).</p>';
		//test += 	'<div style="background: repeat-x url(\'http://test.csswg.org/suites/css2.1/20110323/xhtml1/support/cat.png\'); border: 1px solid black; height: 200px;"></div>';
		test += 	'<div style="background: repeat-x url(\'cat.png\'); border: 1px solid black; height: 200px;"></div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}