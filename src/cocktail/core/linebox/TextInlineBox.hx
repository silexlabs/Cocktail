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
import cocktail.core.geom.Matrix;
import cocktail.core.renderer.ElementRenderer;

import cocktail.Lib;
import cocktail.core.font.FontManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;
import cocktail.port.NativeText;

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
	 * A ref to the font metrics of the TextRenderer
	 */
	private var _fontMetrics:FontMetricsVO;
	
	/**
	 * Proxies access to the native text element wrapped by this
	 * text line box
	 */
	private var _nativeText:NativeText;
	
	/**
	 * The bitmap data extracted from the native text to 
	 * be displayed on screen
	 */
	public var nativeTextBitmap(default, null):NativeBitmapData;
	
	/**
	 * A rectangle containing the dimension
	 * of the text to render
	 */
	private var _renderRect:RectangleVO;
	
	/**
	 * The destination point where to
	 * draw the text
	 */
	private var _destinationPoint:PointVO;
	
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, text:String, fontMetrics:FontMetricsVO, fontManager:FontManager) 
	{
		_fontMetrics = fontMetrics;
		
		super(elementRenderer);
		
		initNativeTextElement(text, fontManager, elementRenderer.coreStyle);
		
		//get the dimensions of the text
		bounds.width = getTextWidth();
		bounds.height = getTextHeight();
		
		_renderRect = new RectangleVO();
		_renderRect.width = bounds.width;
		_renderRect.height = bounds.height;
		_destinationPoint = new PointVO(0.0, 0.0);
		initTextBitmap();
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
		_fontMetrics = null;
		_renderRect = null;
		_destinationPoint = null;
	}
	
	/**
	 * Instantiate a platform specific text rendering element
	 */
	private function initNativeTextElement(text:String, fontManager:FontManager, style:CoreStyle):Void
	{
		//create and store a native text element, using the styles of the 
		//TextRenderer which created this TextLineBox
		var nativeElement:NativeElement = fontManager.createNativeTextElement(text, style);
		//wrap the native text element
		_nativeText = new NativeText(nativeElement);
	}
	
	/**
	 * get the bitmap data from the native text
	 */
	private function initTextBitmap():Void
	{	
		var bitmapBounds:RectangleVO = new RectangleVO();
		bitmapBounds.y = leadedAscent;
		bitmapBounds.width = bounds.width;
		bitmapBounds.height = bounds.height;
		nativeTextBitmap = _nativeText.getBitmap(bitmapBounds);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Overriden as this is the text line box
	 */
	override public function isText():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the leaded ascent of the generated text
	 */
	override private function getLeadedAscent():Float 
	{
		var ascent:Float = _fontMetrics.ascent;
		var descent:Float = _fontMetrics.descent;
		
		var lineHeight:Float = elementRenderer.coreStyle.usedValues.lineHeight;
		
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = lineHeight - (ascent + descent);

		//apply leading to the ascent and descent
		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedAscent;
	}
	
	/**
	 * Return the leaded descent of the generated text
	 */
	override private function getLeadedDescent():Float 
	{
		var ascent:Float = _fontMetrics.ascent;
		var descent:Float = _fontMetrics.descent;	
	
		var lineHeight:Float = elementRenderer.coreStyle.usedValues.lineHeight;
		
		var leading:Float = lineHeight - (ascent + descent);

		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedDescent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//  PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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