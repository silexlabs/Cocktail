/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.linebox;

import cocktail.core.geom.Matrix;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.style.ComputedStyle;
import cocktail.Lib;
import cocktail.core.font.FontManager;
import cocktail.port.DrawingManager;
import cocktail.port.NativeElement;
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
class TextLineBox extends LineBox
{
	/**
	 * A ref to the font metrics of the TextRenderer
	 */
	private var _fontMetrics:FontMetricsData;
	
	/**
	 * The native text element wrapped by this
	 * text line box
	 */
	private var _nativeText:NativeText;
	
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, text:String, fontMetrics:FontMetricsData, fontManager:FontManager) 
	{
		_fontMetrics = fontMetrics;
		
		super(elementRenderer);
		
		initNativeTextElement(text, fontManager, elementRenderer.coreStyle.computedStyle);
		
		//get the dimensions of the text
		bounds.width = getTextWidth();
		bounds.height = getTextHeight();
		
		//TODO 1 : null if space 
		if (_nativeElement != null)
		{
			//TODO 1 : all this should be abstracted in FontManager
			#if (flash9 || nme)
			_bitmap = new flash.display.BitmapData(Math.round(bounds.width), Math.round(bounds.height), true, 0x00000000);
			var matr = new flash.geom.Matrix();
			matr.translate(0.0, leadedAscent);
			
			_bitmap.draw(_nativeElement, matr);
			#end
			_nativeElement = null;
		}
		
		
	}
	
	/**
	 * Instantiate a platfor specific text rendering element
	 */
	private function initNativeTextElement(text:String, fontManager:FontManager, computedStyle:ComputedStyle):Void
	{
		//create and store a native text element, using the styles of the 
		//TextRenderer which created this TextLineBox
		var nativeElement:NativeElement = fontManager.createNativeTextElement(text, computedStyle);
		_nativeText = new NativeText(nativeElement, leadedAscent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render the text using the graphic context as canvas.
	 * 
	 * TODO 4 : should also render text decoration, or should
	 * be on TextRenderer ?
	 * 
	 * TODO 2 : should use globalBounds instead, but global bounds is
	 * used itself to determine the bounds of the text
	 */
	override public function render(graphicContext:DrawingManager):Void
	{
		var rect:RectangleData = {
			x:0.0,
			y:0.0,
			width:bounds.width,
			height:bounds.height
		}
		
		var destPoint:PointData = {
			x:bounds.x + elementRenderer.globalContainingBlockOrigin.x,
			y:bounds.y + elementRenderer.globalContainingBlockOrigin.y - elementRenderer.scrollOffset.y
		}
		
		graphicContext.copyPixels(_bitmap, rect, destPoint);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function getBaselineOffset(parentBaselineOffset:Float, parentXHeight:Float):Float
	{
		return parentBaselineOffset;
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
	
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = elementRenderer.coreStyle.computedStyle.lineHeight - (ascent + descent);

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
	
		var leading:Float = elementRenderer.coreStyle.computedStyle.lineHeight - (ascent + descent);

		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedDescent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//  PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the generated text width
	 * 
	 * TODO 2 : should either create abstract native element
	 * for text to access text width, or use fontManager to
	 * get text width
	 */
	private function getTextWidth():Float
	{
		return _nativeText.width;
		#if (flash9 || nme)
		return untyped _nativeElement.textWidth ;
		#else
		return 0.0;
		#end
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