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
		// TODO border to add
		var test = '';
		test += '<div>';
		test += 	'<p>Test passes if the box below can be scrolled to the words "Filler Text".</p>';
		//test += 	'<div style="border: solid; overflow: auto; width: 200px;">';
		test += 	'<div style="overflow: auto; width: 200px;">';
		test += 		'<span style="position: relative; left: 200px;">Filler Text</span>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}