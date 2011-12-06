/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.font.as3;

import haxe.Log;
import cocktail.font.abstract.AbstractFontManager;
import cocktail.resource.ResourceLoaderManager;


/**
 * This is the implementation of the font loader for the Flash AVM2 runtime. A font in Flash in embeded in a .swf
 * file. It is loaded like a library. The font can be used for a text, just set the HTML style attribute to "font-family=MyFontName"
 * @author Lex oYo
 */
class FontManager extends AbstractFontManager
{
	/**
	 * List of loaded fonts, successfull loaded fonts only
	 */
	public static var fonts:Array<FontData>;
	
	/**
	 * List of fonts being loaded
	 */
	public static var loadingFonts:Array<FontData>;
	
	/**
	 * class constructor
	 */
	public function new() 
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
	public static function loadFont(url:String, name:String, successCallback:Void->Void, errorCallback:String->Void):Void
	{
		ResourceLoaderManager.loadLibrary(url, onLoadComplete, onLoadError);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Callbacks for the loader
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the file is done loading, calls the success callback and update the fonts array
	 * @param	data the loaded library data
	 */
	private static function onLoadComplete(data:Dynamic):Void
	{
		trace("onLoadComplete");
	}
	/**
	 * An error occured while loading the font
	 * @param	data the loaded library data
	 */
	private static function onLoadError(data:Dynamic):Void
	{
		trace("onLoadError");
	}
}
