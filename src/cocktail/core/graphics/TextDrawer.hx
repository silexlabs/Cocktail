package cocktail.core.graphics;

import cocktail.core.linebox.InlineBox;
import cocktail.core.linebox.TextInlineBox;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.geom.GeomData;

/**
 * ...
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
	
	private static var _decorationRect:RectangleVO = new RectangleVO();
	
	private function new() 
	{
		
	}
	
	public static function draw(graphicsContext:GraphicsContext, elementRenderer:ElementRenderer, 
	hasUnderline:Bool, hasOverline:Bool, hasLineThrough:Bool, hasBlink:Bool,
	scrollOffset:PointVO, clipRect:RectangleVO):Void
	{
		var inlineBoxesLength:Int = elementRenderer.inlineBoxes.length;
		for (i in 0...inlineBoxesLength)
		{
			var inlineBox:InlineBox = elementRenderer.inlineBoxes[i];
			_renderRect.width = inlineBox.bounds.width;
			_renderRect.height = inlineBox.bounds.height;
			
			_destPoint.x = inlineBox.bounds.x + elementRenderer.globalBounds.x - scrollOffset.x;
			_destPoint.y = inlineBox.bounds.y + elementRenderer.globalBounds.y - scrollOffset.y;
			
			if (inlineBox.lineBox != null)
			{
				_destPoint.y += inlineBox.lineBox.bounds.y;
				_destPoint.x += inlineBox.lineBox.bounds.x;
			}
				
			if (hasUnderline == true)
			{
				
				_decorationRect.width = _renderRect.width;
				_decorationRect.height = 1;
				_decorationRect.x = _destPoint.x;
				_decorationRect.y = _destPoint.y + elementRenderer.getLeadedAscent() + elementRenderer.coreStyle.fontMetrics.underlineOffset;
				
				graphicsContext.graphics.fillRect(_decorationRect, elementRenderer.coreStyle.usedValues.color, clipRect);
			}
			
			if (inlineBox.isSpace == false)
			{
				//need to type to get ref to native bitmap data
				var typedTextInlineBox:TextInlineBox = cast(inlineBox);
				if (typedTextInlineBox.nativeTextBitmap != null)
				{
					graphicsContext.graphics.copyPixels(typedTextInlineBox.nativeTextBitmap, _renderRect, _destPoint, clipRect);
				}
			}
		}
	}
	
}