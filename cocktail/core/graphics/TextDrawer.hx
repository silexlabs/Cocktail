/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.graphics;

import cocktail.core.linebox.InlineBox;
import cocktail.core.linebox.TextInlineBox;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.geom.GeomData;

/**
 * This class is in charge of the drawing
 * the text inline box of the document as well
 * as the text decorations (underline, overline...)
 * applying to those inline boxes
 * 
 * @author Yannick DOMINGUEZ
 */
class TextDrawer 
{
	/**
	 * a reusable point used to compute the 
	 * position where to render each text inline
	 * box
	 */
	private static var _destPoint:PointVO = new PointVO(0, 0);
	
	/**
	 * A reusable rect used during rendering
	 */
	private static var _renderRect:RectangleVO = new RectangleVO();
	
	/**
	 * A reusable rect used as the bounds for the various text decorations
	 */
	private static var _decorationRect:RectangleVO = new RectangleVO();
	
	/**
	 * the thickness, in pixel, used for text decorations (underline,
	 * overline...)
	 */
	private static var TEXT_DECORATION_THICKNESS:Float = 1.0;
	
	private function new() 
	{
		
	}
	
	/**
	 * Draw all the text inline boxes of the provided
	 * elment renderer as well as all the text
	 * decorations associated with it
	 * 
	 * @param	graphicsContext
	 * @param	elementRenderer the element renderer containing the text inline boxes
	 * to draw
	 * @param	hasUnderline wether the underline text decoration should be applied
	 * to all text inline boxes
	 * @param	hasOverline same for overline
	 * @param	hasLineThrough same for line-through (strike)
	 * @param	hasBlink same for blink. note : blink is not actually applied
	 * @param	scrollOffset
	 * @param	clipRect
	 */
	public static function draw(graphicsContext:GraphicsContext, elementRenderer:ElementRenderer, 
	hasUnderline:Bool, hasOverline:Bool, hasLineThrough:Bool, hasBlink:Bool,
	scrollOffset:PointVO, clipRect:RectangleVO):Void
	{
		//loop through all text inline boxes
		var inlineBoxesLength:Int = elementRenderer.inlineBoxes.length;
		for (i in 0...inlineBoxesLength)
		{
			var inlineBox:InlineBox = elementRenderer.inlineBoxes[i];
			
			//get bounds and position where to draw this text inline box
			_renderRect.width = inlineBox.bounds.width;
			_renderRect.height = inlineBox.bounds.height;
			_destPoint.x = inlineBox.bounds.x + elementRenderer.globalBounds.x - scrollOffset.x;
			_destPoint.y = inlineBox.bounds.y + elementRenderer.globalBounds.y - scrollOffset.y;
			
			//TODO 2 : should not happen, seems to happen for spaces
			//on empty lines
			if (inlineBox.lineBox != null)
			{
				_destPoint.y += inlineBox.lineBox.bounds.y;
				_destPoint.x += inlineBox.lineBox.bounds.x;
			}
				
			//draw underline
			if (hasUnderline == true)
			{
				_decorationRect.width = _renderRect.width;
				_decorationRect.height = TEXT_DECORATION_THICKNESS;
				_decorationRect.x = _destPoint.x;
				_decorationRect.y = _destPoint.y + elementRenderer.getLeadedAscent() + elementRenderer.coreStyle.fontMetrics.underlineOffset;
				
				graphicsContext.graphics.fillRect(_decorationRect, elementRenderer.coreStyle.usedValues.color, clipRect);
			}
			
			//draw overline
			if (hasOverline == true)
			{
				_decorationRect.width = _renderRect.width;
				_decorationRect.height = TEXT_DECORATION_THICKNESS;
				_decorationRect.x = _destPoint.x;
				_decorationRect.y = _destPoint.y;
				
				graphicsContext.graphics.fillRect(_decorationRect, elementRenderer.coreStyle.usedValues.color, clipRect);
			}
			
			//draw text 
			if (inlineBox.isSpace == false)
			{
				//need to type to get ref to native bitmap data
				var typedTextInlineBox:TextInlineBox = cast(inlineBox);
				if (typedTextInlineBox.nativeTextBitmap != null)
				{
					graphicsContext.graphics.copyPixels(typedTextInlineBox.nativeTextBitmap, _renderRect, _destPoint, clipRect);
				}
			}
			
			//draw line through
			if (hasLineThrough == true)
			{
				_decorationRect.width = _renderRect.width;
				_decorationRect.height = TEXT_DECORATION_THICKNESS;
				_decorationRect.x = _destPoint.x;
				_decorationRect.y = _destPoint.y + elementRenderer.getLeadedAscent() - elementRenderer.getLeadedDescent();
				
				graphicsContext.graphics.fillRect(_decorationRect, elementRenderer.coreStyle.usedValues.color, clipRect);
			}
		}
	}
}