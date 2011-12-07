/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.font.js;

import js.Dom.HtmlDom;
import js.Lib;
import cocktailCore.font.abstract.AbstractFontLoader;
import cocktail.font.FontData;

/**
 * This class is in charge of loading one single font and calling the right callback(s) after the load succedeed/failed
 * This is the implementation for the JavaScript runtime. 
 * @author lexa
 */
class FontLoader extends AbstractFontLoader
{	
	private var _styleE:HtmlDom;
	/**
	 * Constructor
	 */
	public function new()
	{
		super();
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
	override public function load(url:String, name:String, successCallback : FontData->Void = null, errorCallback : FontData->String->Void = null):Void
	{
		super.load(url, name, successCallback, errorCallback);
		
		if (fontData.type != swf)
		{
			// build the string to display in the style html tag
			var fontTypeString:String = "";
			if (fontData.type == ttf)
				fontTypeString = " format(\"truetype\")";
			else
				fontTypeString = "";
	
			//Create a 'style' element	
			_styleE = Lib.document.createElement("style");
			_styleE.innerHTML = "@font-face{font-family: "+name+" ; src: url( \""+url+"\" )" +fontTypeString+ ";}";
			
	/*
			// Detection of the font loading success/error, impossible with JS, use Typekit or google Web Fonts API for detection
			untyped _styleE.async = 'true';
		    untyped _styleE.load = _styleE.onload = _styleE.onreadystatechange = _successCallback;
	
	//	    untyped _styleE.addEventListener('onload', _successCallback, false);
	//	    untyped _styleE.addEventListener('error', _errorCallback, false);
	*/
			// workaround : allways call success callback
			_successCallback();
	
			// Now add this new element to the head tag
			Lib.document.getElementsByTagName("head")[0].appendChild(_styleE);
			
			// to do: detect css loading errors
			// ?? styleE.async = 'true'; styleE.onload = tk.onreadystatechange = 
	//		successCallback();
		}
		else
		{
			// error because the font format is not appropriate for the target
			trace("Could not load font, the font format is not appropriate for the target: "+url);
			_onLoadError("Could not load font, the font format is not appropriate for the target: "+url);
		}
	}
	/**
	 * empty the arrays and remove references to callbacks
	 */
	override private function cleanup()
	{
		super.cleanup(); 
/*	    untyped _styleE.removeEventListener('load', _successCallback, false);
	    untyped _styleE.removeEventListener('error', _errorCallback, false);
*/
	}
}
