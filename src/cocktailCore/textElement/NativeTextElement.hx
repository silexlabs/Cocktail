/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.textElement;

/**
 * Set the right runtime specific NativeTextElement at compile-time
 * 
 * A NativeTextElement is an abstraction of a text element, variying
 * based on runtime
 */
#if (flash9 || cpp || nme)
typedef NativeTextElement = String;

#elseif js
import js.Dom;
typedef NativeTextElement =  js.HtmlDom;

#elseif php
typedef NativeTextElement =  String;

#end