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
 * This class handles the fonts loading, stores a list of loaded fonts. 
 * This is the implementation for the JavaScript runtime. 
 * @author lexa
 */
class FontManager extends AbstractFontManager 
{	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	override private function new() 
	{
		super();
	}
	public static function loadFont(url : String, name : String, successCallback : FontData->Void = null, errorCallback : FontData->String->Void = null):Void
	{
		AbstractFontManager.loadFont(url, name, successCallback, errorCallback);
	}
}
