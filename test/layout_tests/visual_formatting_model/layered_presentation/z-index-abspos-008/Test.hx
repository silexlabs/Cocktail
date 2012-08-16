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
		test += '<div style="position: absolute; width: 4em; height: 4em;">';
		test += 	'<div style="position: absolute; width: 4em; height: 4em; top: 1em; left: 1em; width: 12em; height: 12em; background: gray;">';
		test += 		'<div style="position: absolute; width: 4em; height: 4em; top: 1em; left: 4em; background: blue;">';
		test += 			'<div class="c" style="position: absolute; width: 4em; height: 4em; top: 3em; left: -3em; background: lime; z-index: 2;">';
		test += 			'</div>';
		test += 		'</div>';
		test += 		'<div class="d" style="position: absolute; width: 4em; height: 4em; top: 4em; left: 7em; background: orange;">';
		test += 			'<div class="e" style="position: absolute; width: 4em; height: 4em; top: 3em; left: -3em; background: yellow; z-index: 1;">';
		test += 			'</div>';
		test += 		'</div>';
		test += 	'</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}
