/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.font.js;

import js.Dom.HtmlDom;
import js.Lib;
import cocktail.font.abstract.AbstractFontManager;
import cocktail.font.FontData;

/**
 * This class handles the fonts loading, stores a list of loaded fonts. 
 * This is the implementation for the JavaScript runtime. 
 * @author lexa
 */
class FontManager extends AbstractFontManager 
{	
	/**
	 * List of loaded fonts, successfull loaded fonts only
	 */
	public static var fonts:Array<FontData>;
	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	private function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, fonts loading
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start loading a font
	 * @param	url the url of the font to load
	 * @param	name the name of the font to load. 
	 * This is an equivalent of font-family in HTML, and an equivalent of the export name in Flash. 
	 * This is the name you want to put in the css class to apply the style to some text.
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadFont(url:String, name:String, successCallback:FontData->Void, errorCallback:String->Void):Void
	{
		var extension:String = url.substr(url.lastIndexOf("."), url.length); 
		var fontData:FontData = {
			url:url,
			name:name,
			type : unknown
		};
		var fontTypeString:String = "";
		
		if (extension == ".ttf")
		{
			fontData.type = ttf;
			fontTypeString = " format(\"truetype\")";
		}
		else if (extension == ".eot")
		{
			fontData.type = eot;
			fontTypeString = "";
		}
		//Create a 'style' element	
		var styleE:HtmlDom = Lib.document.createElement("style");
		styleE.innerHTML = "@font-face{font-family: "+name+" ; src: url( \""+url+"\" )" +fontTypeString+ ";}";
		
		// Set it's onLoad callback
		untyped styleE.onload = onLoadComplete;
		
		//Set it's error callback
		untyped styleE.onerror = onLoadError;
		
		// Now add this new element to the head tag
		Lib.document.getElementsByTagName("head")[0].appendChild(styleE);
		
		//successCallback(fontData);
	}
	/**
	 * When the font is loaded, calls the success callback with the font data structure
	 * @param	data the loaded library data
	 */
	private function onLoadComplete(data:Dynamic):Void
	{
		
		//_onLoadCompleteCallback(null);
	}
	
}