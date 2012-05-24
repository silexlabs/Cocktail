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
		test += '<div style="margin: 5em auto; height: 35px; width: 35px; border: solid 10px red; background: transparent;">';
		test += 	'<div style="margin: 0;background: transparent url(swatch-red.png) no-repeat center; height: 15px; width: 15px; border:10px solid green;">';
		test += 		'<p style="position: absolute; top: 0; left: 0; margin: 1em;">There should be a completely-filled green square and no red.</p>';
		test += 		' <!-- The <div> should be under the <body> box but above the canvas and <html> backdrop. !-->';
		test += 		'<div style="margin: 0;background: red url(swatch-green.png) center no-repeat; height: 15px; width: 15px; padding: 9px; border: solid 10px green; position: absolute; margin-top: -19px; margin-left: -19px; z-index: -1;"></div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}
