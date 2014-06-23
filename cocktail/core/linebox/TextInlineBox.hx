/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.linebox;

import cocktail.core.css.CoreStyle;
import cocktail.geom.Matrix;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.font.FontManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.Bindings;
import cocktail.geom.GeomData;
import cocktail.core.font.FontData;

/**
 * A special kind of line box used to render text. 
 * Wrap a native text element which is platform
 * specific
 * 
 * @author Yannick DOMINGUEZ
 */
class TextInlineBox extends InlineBox
{
	/**
	 * Proxies access to the native text element wrapped by this
	 * text line box
	 */
	private var _nativeText:NativeText;
	
	/**
	 * The bitmap data extracted from the native text to 
	 * be displayed on screen
	 */
	public var nativeTextBitmap(get_nativeTextBitmap, null):NativeBitmapData;
	
	/**
	 * A reusable rectangle used to draw text to bitmap
	 */
	private static var _bitmapBounds:RectangleVO = new RectangleVO();
	
	/**
	 * the dispalyed text
	 */
	private var _text:String;
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, leadedAscent:Float, leadedDescent:Float, text:String, fontMetrics:FontMetricsVO, fontManager:FontManager, fontFamily:String) 
	{
		super(elementRenderer, leadedAscent, leadedDescent);
		
		isText = true;
		
		_text = text;
		initNativeTextElement(text, fontManager, elementRenderer.coreStyle, fontFamily);
		
		//get the dimensions of the text
		bounds.width = _nativeText.width;
		bounds.height = leadedAscent + leadedDescent;
	}
	
	/**
	 * cleanup method
	 */
	override public function dispose():Void
	{
		super.dispose();
		if (_nativeText != null)
		{
			_nativeText.dispose();
			_nativeText = null;
		}
	}
	
	/**
	 * Instantiate a platform specific text rendering element
	 */
	private function initNativeTextElement(text:String, fontManager:FontManager, style:CoreStyle, fontFamily:String):Void
	{
		//create and store a native text element, using the styles of the 
		//TextRenderer which created this TextLineBox
		var nativeTextElement:NativeTextElement = fontManager.createNativeTextElement(text, style, fontFamily);
		//wrap the native text element
		_nativeText = new NativeText(nativeTextElement);
	}
	
	/**
	 * get the bitmap data from the native text
	 */
	private function initTextBitmap():Void
	{	
		_bitmapBounds.y = leadedAscent;
		_bitmapBounds.width = bounds.width;
		_bitmapBounds.height = bounds.height;
		
		//text size might be null if character not recognised
		if (_bitmapBounds.width != 0 && _bitmapBounds.height != 0)
		{
			nativeTextBitmap = _nativeText.getBitmap(_bitmapBounds);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//  PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_nativeTextBitmap():NativeBitmapData
	{
		//bitmap for text is created the first
		//time it is drawn
		if (nativeTextBitmap == null)
		{
			initTextBitmap();
		}
		return nativeTextBitmap;
	}
	
	/**
	 * return the generated text width
	 */
	private function getTextWidth():Float
	{
		return _nativeText.width;
	}

	/**
	 * return the generated text height, which is
	 * the addition of the leaded ascent and descent
	 */
	private function getTextHeight():Float
	{
		return leadedAscent + leadedDescent;
	}
	
	
}
