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
		var test = '<div><div style="display:inline-block"><img src="bubble.png" style="display:block; margin-left:auto; margin-right:auto;" /></div></div>';
		//test += '<div style="width:200px; height:200px; position:absolute;" id="div1">';
		//test += '<div style="position:absolute; background-color:blue; display:inline; height:50%; width:100%;"></div>';
		//test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}