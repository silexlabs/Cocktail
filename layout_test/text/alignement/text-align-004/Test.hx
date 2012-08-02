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
 * TODO : justified space width doesn't seem right
 */
class Test 
{
	public static function main()
	{	
		new Test();
	}
	
	public function new()
	{
		//TODO : should add border
		var test = '<div><p>Test passes if the words "Filler Text" are justified and spaced out on the first two lines of text inside the blue box. The final line of text does not have to be justified but can be based on user agent implementation.</p>';
		test += '<div style="text-align:justify; width:150px;">Filler Text Filler Text Filler Text Filler Text Filler Text Filler Text</div>';
		test += '</div>';
		
		Lib.document.body.innerHTML = test;
	}
}