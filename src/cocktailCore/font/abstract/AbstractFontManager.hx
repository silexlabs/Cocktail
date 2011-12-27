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
 * This class is the manager for system and embedded fonts. Use it to load new fonts, or to check if a system font is supported, etc.
 * It is a base class, which is extended for each target.
 * @author lexa
 */
class AbstractFontManager 
{	
	/**
	 * List of loaded fonts, successfull loaded fonts only
	 */
	private static var _loadedFonts:Array<FontData>;
	
	/**
	 * the font loaders for currently loading fonts
	 */
	private static var _fontLoaderArray:Array<FontLoader>;
	
	/**
	 * Constructor initializes the static attributes
	 */
	public function new()
	{
		if(_fontLoaderArray == null)
			_fontLoaderArray = new Array();
		if(_loadedFonts == null)
			_loadedFonts = new Array();
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
	public function loadFont(url : String, name : String, successCallback : FontData->Void = null, errorCallback : FontData->String->Void = null):Void
	{
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
		fontLoader.addCallback(_onFontLoadingSuccess, _onFontLoadingError);
		fontLoader.addCallback(successCallback, errorCallback);
		fontLoader.load(url, name);
		_fontLoaderArray.push(fontLoader);
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public virtual methods
	//////////////////////////////////////////////////////////////////////////////////////////
	/** 
	 * Returns a list of fonts which have been loaded.
	 */
	public function getEmbeddedFonts() : Array<FontData>
	{
		return _loadedFonts;
	}
	/** 
	 * Returns a list of fonts which are installed on the current runtime.
	 */
	public function getSystemFonts() : Array<FontData>
	{
		throw ("Virtual method should be implemented in sub class");
		return null;
	}
	/** 
	 * Returns true if the font specified bay fontName has been loaded or is available as a system font.
	 */
	public function hasFont(fontName:String) : Bool
	{
		var fontDataArray : Array<FontData>;
		var idx : Int;
		
		// check in the loaded fonts
		fontDataArray = getEmbeddedFonts();
		for (idx in 0...fontDataArray.length)
			if (fontDataArray[idx].name == fontName)
				return true;
		
		// check in the system fonts
		fontDataArray = getSystemFonts();
		for (idx in 0...fontDataArray.length)
			if (fontDataArray[idx].name == fontName)
				return true;
		
		return false;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * A font has been loaded
	 */
	private function _onFontLoadingSuccess(fontData : FontData)
	{
		// store the font data
		_loadedFonts.push(fontData);
		
		// free the font loader
		if (_removeFontLoader(fontData) == false)
		{
			// to do handle error
			trace("could not remove font loader from the list after the font was successfully loaded");
		}
	}
	/**
	 * A font could not be loaded
	 */
	private function _onFontLoadingError(fontData : FontData, errorStr : String)
	{
		// to do handle error
		trace("font loading has failed");
		
		// free the font loader
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
	private function _removeFontLoader(fontData : FontData) : Bool
	{
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