/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.core.css.CoreStyle;
import cocktail.core.font.FontData;
import cocktail.port.NativeTextElement;

import cocktail.core.layout.LayoutData;

/**
 * The FontBuilder is used to get metrics for fonts and
 * create native text element
 * 
 * @author Yannick DOMINGUEZ
 */
class FontBuilderBase
{	
	/**
	 * Class constructor.
	 */
	public function new()
	{
		
	}
	
	/**
	 * clean up method
	 */
	public function dispose()
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, font creation and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns metrics for a given
	 * font and font size.
	 * 
	 * Returns a default metrics for port with no font support
	 */
	public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsVO
	{
		return new FontMetricsVO(12.0, 12.0, 12.0, 12.0, 3.0, 3.0, 3.0, 5.0 );
	}
	
	/**
	 * create a runtime specific text display
	 * element for the provided text string
	 * and the styles that were computed for
	 * this text
	 */
	public function createNativeTextElement(text:String, style:CoreStyle, fontFamily:String):NativeTextElement
	{
		return null;
	}
	
	/**
	 * Get a css cont family array and return it
	 * as a string of font family formatted for the
	 * native runtime
	 */
	public function getNativeFontFamily(fontFamily:Array<String>):String
	{
		return null;
	}
}