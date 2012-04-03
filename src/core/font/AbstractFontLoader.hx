/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.font.abstract;
import cocktail.font.FontData;

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
	public var fontData : FontData;
	
	/**
	 * An array of callbacks to be called when the font is successfully loaded
	 */
	public var _successCallbackArray : Array<FontData->Void>;
	
	/**
	 * An array of callbacks to be called when the font could not be loaded
	 */
	public var _errorCallbackArray : Array<FontData->String->Void>;
	
	/**
	 * Constructor
	 */
	public function new()
	{
		_successCallbackArray = new Array();
		_errorCallbackArray = new Array();
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
	public function load(url:String, name:String):Void
	{
		// create the font data
		var extension:String = url.substr(url.lastIndexOf("."), url.length); 
		fontData = 
		{
			url : url,
			name : name,
			type : unknown
		};
		// extension
		if (extension == ".ttf")
			fontData.type = ttf;
		else if (extension == ".eot")
			fontData.type = eot;
		else if (extension == ".otf")
			fontData.type = otf;
		else if (extension == ".swf")
			fontData.type = swf;
		else 
			fontData.type = unknown;
	}
	
	/**
	 * Add a callback while the font is loading. 
	 * This method is called by the font manager, when it is asked to load a font which is already loading
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 */
	public function addCallback(successCallback:FontData->Void = null, errorCallback : FontData->String->Void = null):Void
	{
		// store the callback in the corresponding array
		if (successCallback != null)
			_successCallbackArray.push(successCallback);

		// store the callback in the corresponding array
		if (errorCallback != null)
			_errorCallbackArray.push(errorCallback);
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * Success callback for the font, call _onFontLoaded callback
	 */
	private function _successCallback()
	{
		// call the callbacks
		var idx : Int;
		for (idx in 0..._successCallbackArray.length)
			_successCallbackArray[idx](fontData);
			
		// clean up
		cleanup();
	}
	/**
	 * Error callback for the font, call _onFontLoaded callback
	 */
	private function _errorCallback(errorStr : String)
	{
		// call the callbacks
		var idx : Int;
		for (idx in 0..._errorCallbackArray.length)
			_errorCallbackArray[idx](fontData, errorStr);
			
		// clean up
		cleanup();
	}
	/**
	 * empty the arrays and remove references to callbacks
	 */
	private function cleanup()
	{
		while (_successCallbackArray.length > 0)
			_successCallbackArray.pop();
		while (_errorCallbackArray.length > 0)
			_errorCallbackArray.pop();
	}
}
