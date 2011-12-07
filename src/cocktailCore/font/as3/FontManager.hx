/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.font.as3;

import haxe.Log;
import cocktailCore.font.abstract.AbstractFontManager;
import cocktail.resource.ResourceLoaderManager;
import cocktail.font.FontData;


/**
 * This is the implementation of the font loader for the Flash AVM2 runtime. A font in Flash in embeded in a .swf
 * file. It is loaded like a library. The font can be used for a text, just set the HTML style attribute to "font-family=MyFontName"
 *
 * download flex sdk
 * > http://opensource.adobe.com/wiki/display/flexsdk/Flex+SDK
 *
 * create an embedded font with flex sdk
 * > http://rodneypillay.wordpress.com/2010/05/18/fontswf-utility-in-flex-sdk-4/
 * 
 * @author Lex oYo
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
