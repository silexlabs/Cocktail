/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.font;

import cocktail.core.css.CoreStyle;
import cocktail.core.font.FontData;
import cocktail.port.FontManagerImpl;
import cocktail.port.NativeElement;

import cocktail.core.style.StyleData;

/**
 * The FontManager is used to get metrics for fonts and
 * create native text rendering element
 * 
 * This is a Singleton instantiatin the actual FontManager
 * implementation class which is platform specific
 * 
 * @author Yannick DOMINGUEZ
 */
class FontManager 
{	
	/**
	 * singleton instance
	 */
	private static var _instance:FontManager;
	
	/**
	 * The instance of the platform specific
	 * FontManager implementation
	 */
	private var _fontManagerImpl:FontManagerImpl;
	
	/**
	 * Class constructor. Private to respect Singleton
	 * pattern
	 */
	private function new()
	{
		_fontManagerImpl = new FontManagerImpl();
	}
	
	/**
	 * Singleton method
	 */
	public static function getInstance():FontManager
	{
		if (_instance == null)
		{
			_instance = new FontManager();
		}
		return _instance;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, forward calls to font manager implementation
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns metrics for a given
	 * font and font size
	 */
	public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsData
	{
		return _fontManagerImpl.getFontMetrics(fontFamily, fontSize);
	}
	
	/**
	 * create a runtime specific text display
	 * element for the provided text string
	 * and the styles that were computed for
	 * this text
	 */
	public function createNativeTextElement(text:String, style:CoreStyle):NativeElement
	{
		return _fontManagerImpl.createNativeTextElement(text, style);
	}
}