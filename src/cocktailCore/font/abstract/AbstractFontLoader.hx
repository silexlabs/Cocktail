/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.font.abstract;

/**
 * This class is in charge of loading one single font and calling the right callback(s) after the load succedeed/failed
 * It is a base class, which is extended for each target.
 * @author lexa
 */
class AbstractFontLoader 
{	
	/**
	 * The details about the font
	 */
	public static var fontData : FontData;
	
	/**
	 * An array of callbacks to be called when the fonts are successfully loaded
	 */
	public static var _onLoadCompleteCallbackArray : Array<FontData->Void>;
	
	/**
	 * An array of callbacks to be called when the fonts are successfully loaded
	 */
	public static var _onLoadErrorCallbackArray : Array<FontData->Void>;
	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, fonts loading
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start loading the font
	 * @param	url the url of the font to load
	 * @param	name the name of the font to load. 
	 * This is an equivalent of font-family in HTML, and an equivalent of the export name in Flash. 
	 * This is the name you want to put in the css class to apply the style to some text.
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 */
	public function load(url:String, name:String, successCallback:FontData->Void = null, errorCallback:String->Void = null):Void
	{
		// to be implemented for each target
		throw("to be implemented for each target");
	}
	
	/**
	 * Add a callback while the font is loading. This method is called by the font manager, when it is asked to load a font which is already loading
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 */
	public function addCallback(successCallback:FontData->Void = null, errorCallback:String->Void = null):Void
	{
		// to be implemented for each target
		throw("to be implemented for each target");
	}
	
}
