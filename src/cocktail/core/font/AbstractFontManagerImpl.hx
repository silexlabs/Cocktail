/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.font;

import cocktail.core.font.FontData;
import cocktail.port.NativeElement;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.StyleData;

/**
 * The FontManager is used to get metrics for fonts and
 * create native text rendering element
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractFontManagerImpl
{	
	/**
	 * A cache of the computed font metrics where the
	 * keys are the font name and the font sizes
	 */
	private var _computedFontMetrics:Hash<Hash<FontMetricsData>>;
	
	/**
	 * Class constructor. Init class attributes
	 */
	public function new()
	{
		_computedFontMetrics = new Hash<Hash<FontMetricsData>>();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, font creation and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns metrics for a given
	 * font and font size
	 */
	public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsData
	{
		var fontMetrics:FontMetricsData;
		
		//this method caches all the generated font metrics and
		//tries first to retrieve them on subsequent calls
		if (_computedFontMetrics.exists(fontFamily) == true)
		{
			var fontSizeHash:Hash<FontMetricsData> = _computedFontMetrics.get(fontFamily);
			if (fontSizeHash.exists(Std.string(fontSize)) == true)
			{
				fontMetrics = fontSizeHash.get(Std.string(fontSize));
			}
			else
			{
				fontMetrics = doGetFontMetrics(fontFamily, fontSize);
				fontSizeHash.set(Std.string(fontSize), fontMetrics);
				_computedFontMetrics.set(fontFamily, fontSizeHash); 
			}
		}
		else
		{
			fontMetrics = doGetFontMetrics(fontFamily, fontSize);
			var fontSizeHash:Hash<FontMetricsData> = new Hash<FontMetricsData>();
			fontSizeHash.set(Std.string(fontSize), fontMetrics);
			
			_computedFontMetrics.set(fontFamily, fontSizeHash); 
		}
		
		return fontMetrics;
	}
	
	/**
	 * create a runtime specific text display
	 * element for the provided text string
	 * and the styles that were computed for
	 * this text
	 */
	public function createNativeTextElement(text:String, computedStyle:ComputedStyle):NativeElement
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually compute a font metrics using runtime
	 * specific API
	 */
	private function doGetFontMetrics(fontFamily:String, fontSize:Float):FontMetricsData
	{
		return null;
	}
}