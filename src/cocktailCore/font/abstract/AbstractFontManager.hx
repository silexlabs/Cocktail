/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.font.abstract;

import cocktail.font.FontData;
import cocktailCore.font.FontLoader;

/**
 * This class is the manager for system and embedded fonts. Use this static class to load new fonts, or to check if a system font is supported, etc.
 * It has a loadedFonts array used to make sure a font is not loaded twice.
 * It is a base class, which is extended for each target.
 * Since the FontManager is a static class, this base class is only for the documentation
 * @author lexa
 */
class AbstractFontManager 
{	
	/**
	 * List of loaded fonts, successfull loaded fonts only
	 */
	public static var loadedFonts:Array<FontData>;
	
	/**
	 * the font loaders for currently loading fonts
	 */
	private static var _fontLoaderArray:Array<FontLoader>;
	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	private function new() {}
	/**
	 * This method initializes the static attributes
	 */
	private static function _init() 
	{
		if(_fontLoaderArray == null)
			_fontLoaderArray = new Array();
		if(loadedFonts == null)
			loadedFonts = new Array();
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
	 */
	public static function loadFont(url : String, name : String, successCallback : FontData->Void = null, errorCallback : FontData->String->Void = null):Void
	{
		// init the static attributes if needed
		_init();
		
		// check if the font is allready loading
		var fontLoader : FontLoader;
		var idx : Int;

		for (idx in 0..._fontLoaderArray.length)
		{
			if (_fontLoaderArray[idx].fontData.url == url && _fontLoaderArray[idx].fontData.name == name)
			{
				_fontLoaderArray[idx].addCallback(successCallback, errorCallback);
				return ;
			}
		}
		// create the font loader 
		fontLoader = new FontLoader();
		fontLoader.load(url, name, successCallback, errorCallback);
		fontLoader.addCallback(_onFontLoadingSuccess, _onFontLoadingError);
		_fontLoaderArray.push(fontLoader);
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public virtual methods
	//////////////////////////////////////////////////////////////////////////////////////////
/*
getEmbeddedFonts() : Array
Returns a list of fonts which have been loaded.

getSystemFonts() : Array
Returns a list of fonts which are installed on the current runtime.

hasFont(fontName:String) : Boolean
Returns true if the font specified bay fontName has been loaded or is available as a system font.

*/
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * A font has been loaded
	 */
	private static function _onFontLoadingSuccess(fontData : FontData)
	{
		// init the static attributes if needed
		_init();
		
		loadedFonts.push(fontData);
		if (_removeFontLoader(fontData) == false)
		{
			// to do handle error
			trace("could not remove font loader from the list after the font was successfully loaded");
		}
	}
	/**
	 * A font could not be loaded
	 */
	private static function _onFontLoadingError(fontData : FontData, errorStr : String)
	{
		// init the static attributes if needed
		_init();
		
		// to do handle error
		trace("font loading has failed");
		
		if (_removeFontLoader(fontData) == false)
		{
			// to do handle error
			trace("could not remove font loader from the list after the font loading has failed");
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, utilities
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * Remove a font loader from the list
	 */
	private static function _removeFontLoader(fontData : FontData) : Bool
	{
		// init the static attributes if needed
		_init();
		
		// find the font loader
		var fontLoader : FontLoader;
		var idx : Int;
		for (idx in 0..._fontLoaderArray.length)
		{
			if (_fontLoaderArray[idx].fontData.url == fontData.url && _fontLoaderArray[idx].fontData.name == fontData.name)
			{
				_fontLoaderArray.remove(_fontLoaderArray[idx]);
				return true;
			}
		}
		return false;
	}
}