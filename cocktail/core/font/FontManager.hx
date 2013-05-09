/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.font;

import cocktail.core.css.CoreStyle;
import cocktail.core.font.FontData;
import cocktail.port.FontManagerImpl;
import cocktail.port.NativeTextElement;

import cocktail.core.layout.LayoutData;

/**
 * The FontManager is used to get metrics for fonts and
 * create native text rendering element using platform
 * specific API
 * 
 * @author Yannick DOMINGUEZ
 */
class FontManager 
{	
	/**
	 * The instance of the platform specific
	 * FontManager implementation
	 */
	private var _fontManagerImpl:FontManagerImpl;
	
	/**
	 * Class constructor
	 */
	public function new()
	{
		_fontManagerImpl = new FontManagerImpl();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_fontManagerImpl.dispose();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, forward calls to font manager implementation
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns metrics for a given
	 * font and font size
	 */
	public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsVO
	{
		return _fontManagerImpl.getFontMetrics(fontFamily, fontSize);
	}
	
	/**
	 * create a runtime specific text display
	 * element for the provided text string
	 * and the styles that were computed for
	 * this text
	 */
	public function createNativeTextElement(text:String, style:CoreStyle, fontFamily:String):NativeTextElement
	{
		return _fontManagerImpl.createNativeTextElement(text, style, fontFamily);
	}
	
	/**
	 * Get a css cont family array and return it
	 * as a string of font family formatted for the
	 * native runtime
	 */
	public function getNativeFontFamily(fontFamily:Array<String>):String
	{
		return _fontManagerImpl.getNativeFontFamily(fontFamily);
	}
}