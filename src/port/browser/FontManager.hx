/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.font.js;

import js.Dom.HtmlDom;
import js.Lib;
import cocktailCore.font.abstract.AbstractFontManager;
import cocktail.font.FontData;


/**
 * This class is the manager for system and embedded fonts. Use it to load new fonts, or to check if a system font is supported, etc.
 * This is the implementation for the JavaScript runtime. 
 * @author lexa
 */
class FontManager extends AbstractFontManager 
{	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	override public function new() 
	{
		super();
	}
	/** 
	 * Returns a list of fonts which are installed on the current runtime.
	 */
	override public function getSystemFonts() : Array<FontData>
	{
		// throw ("It is impossible to list the system fonts in javascript");
		trace ("It is impossible to list the system fonts in javascript");
		return new Array();
	}
}
