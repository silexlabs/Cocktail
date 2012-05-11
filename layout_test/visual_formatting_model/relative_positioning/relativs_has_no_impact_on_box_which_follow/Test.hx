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
		var test = '<div><p>Test passes if "Filler Text1" and "Filler Text3" are on the first line and "Filler Text2" is on the second line and the space has been reserved where "Filler Text2" would have been if it were on the first line.</p>';
		test += '<div>';
		test += '<span>';
		test += 'Filler Text1';
		test += '<span style="position:relative; top:25px; left:0;"> Filler Text2 </span>';
		test += 'Filler Text3';
		test += '</span>';
		test += '</div></div>';
		
		Lib.document.body.innerHTML = test;
	}
}