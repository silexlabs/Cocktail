/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.graphics;

import cocktail.core.css.CoreStyle;
import cocktail.geom.GeomData;
import cocktail.css.CSSStyleData;

/**
 * This class is in charge of
 * drawing each border of a box, 
 * defined by its borders styles, 
 * if it has any
 * 
 * @author Yannick DOMINGUEZ
 */
class BorderDrawer 
{
	/**
	 * A reusable rect used to
	 * store a single border bounding box
	 */
	private static var _currentBorderBox:RectangleVO = new RectangleVO();
	
	/**
	 * class constructor, private for static
	 * class
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * draw each border
	 * of the box according to their css styles,
	 * each of the 4 border has individual css
	 * styles
	 * 
	 * @param	graphicContext
	 * @param	borderBox the bounding box of the element including all the borders,
	 * in the space of the viewport
	 * @param	style contains all the border style
	 * @param	clipRect the clipping applied to the box, in the space
	 * of the viewport
	 */
	public static function draw(graphicContext:GraphicsContext, borderBox:RectangleVO, style:CoreStyle, clipRect:RectangleVO):Void
	{
		drawBorder(graphicContext, getTopBorderBox(borderBox, style.usedValues.borderTopWidth), style.usedValues.borderTopColor, style.getKeyword(style.borderTopStyle), clipRect); 
		drawBorder(graphicContext, getLeftBorderBox(borderBox, style.usedValues.borderLeftWidth), style.usedValues.borderLeftColor, style.getKeyword(style.borderLeftStyle), clipRect); 
		drawBorder(graphicContext, getRightBorderBox(borderBox, style.usedValues.borderRightWidth), style.usedValues.borderRightColor, style.getKeyword(style.borderRightStyle), clipRect); 
		drawBorder(graphicContext, getBottomBorderBox(borderBox, style.usedValues.borderBottomWidth), style.usedValues.borderBottomColor, style.getKeyword(style.borderBottomStyle), clipRect); 
	}
	
	/**
	 * draw the outline of the box, according
	 * to the css oultine styles
	 * 
	 * TODO 1 : for now 'invert' value is not supported,
	 * will instead draw last used outline color
	 * 
	 * @param	graphicContext
	 * @param	outlineBox the bounding box of the outline, 
	 * includes the outline width
	 * @param	style
	 * @param	clipRect
	 */
	public static function drawOutline(graphicContext:GraphicsContext, outlineBox:RectangleVO, style:CoreStyle, clipRect:RectangleVO):Void
	{
		drawBorder(graphicContext, getTopBorderBox(outlineBox, style.usedValues.outlineWidth), style.usedValues.outlineColor, style.getKeyword(style.outlineStyle), clipRect); 
		drawBorder(graphicContext, getLeftBorderBox(outlineBox, style.usedValues.outlineWidth), style.usedValues.outlineColor, style.getKeyword(style.outlineStyle), clipRect); 
		drawBorder(graphicContext, getRightBorderBox(outlineBox, style.usedValues.outlineWidth), style.usedValues.outlineColor, style.getKeyword(style.outlineStyle), clipRect); 
		drawBorder(graphicContext, getBottomBorderBox(outlineBox, style.usedValues.outlineWidth), style.usedValues.outlineColor, style.getKeyword(style.outlineStyle), clipRect);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw a single border
	 * 
	 * @param	graphicContext
	 * @param	borderBox the bounding box for the specific border
	 * being drawn
	 * @param	borderColor the color of the border, including its alpha
	 * @param	borderStyle the pattern used to draw the border (solid, dotted, dashed...)
	 * @param	clipRect
	 * 
	 * TODO 2 : for now, only solid borders are supported
	 * TODO 1 : if adjoining borders are drawn (left and top for instance), their are currently
	 * drawn over each other, which causes a visual bug if they don't have the same color
	 * or if they have alpha
	 */
	private static function drawBorder(graphicContext:GraphicsContext, borderBox:RectangleVO, borderColor:ColorVO, borderStyle:CSSKeywordValue, clipRect:RectangleVO):Void
	{
		//no need to draw the border if it has no width or height
		if (Math.round(borderBox.width) <= 0 || Math.round(borderBox.height) <= 0 )
		{
			return;
		}
		
		graphicContext.nativeLayer.graphics.fillRect(borderBox, borderColor, clipRect);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return bounding box of the top
	 * border in the space of the
	 * viewport
	 */
	private static function getTopBorderBox(borderBox:RectangleVO, borderWidth:Float):RectangleVO
	{
		_currentBorderBox.x = borderBox.x;
		_currentBorderBox.y = borderBox.y;
		_currentBorderBox.width = borderBox.width;
		_currentBorderBox.height = borderWidth;
		
		return _currentBorderBox;
	}
	
	/**
	 * same as above for bottom border
	 */
	private static function getBottomBorderBox(borderBox:RectangleVO, borderWidth:Float):RectangleVO
	{
		_currentBorderBox.x = borderBox.x;
		_currentBorderBox.y = borderBox.y + borderBox.height - borderWidth;
		_currentBorderBox.width = borderBox.width;
		_currentBorderBox.height = borderWidth;
		
		return _currentBorderBox;
	}
	
	/**
	 * same as above for left border
	 */
	private static function getLeftBorderBox(borderBox:RectangleVO, borderWidth:Float):RectangleVO
	{
		_currentBorderBox.x = borderBox.x;
		_currentBorderBox.y = borderBox.y;
		_currentBorderBox.width = borderWidth;
		_currentBorderBox.height = borderBox.height;
		
		return _currentBorderBox;
	}
	
	/**
	 * same as above for right border
	 */
	private static function getRightBorderBox(borderBox:RectangleVO, borderWidth:Float):RectangleVO
	{
		_currentBorderBox.x = borderBox.x + borderBox.width - borderWidth;
		_currentBorderBox.y = borderBox.y;
		_currentBorderBox.width = borderWidth;
		_currentBorderBox.height = borderBox.height;
		
		return _currentBorderBox;
	}
}
