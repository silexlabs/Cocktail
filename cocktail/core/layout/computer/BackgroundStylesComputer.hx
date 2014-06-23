/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layout.computer;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSValueConverter;
import cocktail.geom.GeomData;
import haxe.Log;
import cocktail.core.font.FontData;
import cocktail.css.CSSStyleData;

/**
 * This class computes all the background styles.
 * 
 * It is assumed that all the styles, except for 
 * background-color are represented by an array
 * of the same length as the background-image style,
 * otherwise, illegal range exception are thrown.
 * 
 * The background computation is done in 2 phases : 
 * - first all the styles that can be immediately
 * computed after a layout (such as background-color)
 * are computed
 * - then, at rendering time when each of the background
 * box (the boxes onto which a background is drawn,
 * for instance for an inline HTMLElement displayed on multiple
 * lines, there will be one background box for each line) and
 * each of the background image dimensions are known, all
 * the styles are computed
 * 
 * @author Yannick DOMINGUEZ
 */
class BackgroundStylesComputer 
{
	/**
	 * Class contructor. Private, as
	 * this class is meant to be accessed
	 * through its public static methods
	 */
	private function new() 
	{
		
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is called during rendering for each background image of a HTMLElement
	 * for each background boxes
	 * 
	 * At this point, all the background boxes of the HTMLElement are known and also
	 * the intrinsic dimension of the background-image which can be an externally loaded
	 * bitmap or a programatically drawn gradient. The dimension of the background
	 * image is used to compute some styles.
	 * 
	 * @param	style
	 * @param	backgroundBox
	 * @param	intrinsicWidth
	 * @param	intrinsicHeight
	 * @param	intrinsicRatio
	 * @param	backgroundPosition
	 * @param	backgroundSize
	 * @param	backgroundOrigin
	 * @param	backgroundClip
	 * @param	backgroundRepeat
	 * @param	backgroundImage
	 * @return	a structure containing each of the computed background styles for the
	 * current background-image
	 */
	public static function computeIndividualBackground(style:CoreStyle, backgroundBox:RectangleVO,
	intrinsicWidth:Null<Float>, intrinsicHeight:Null<Float>, intrinsicRatio:Null<Float>, 
	backgroundPosition:CSSPropertyValue,
	backgroundSize:CSSPropertyValue,
	backgroundOrigin:CSSPropertyValue,
	backgroundClip:CSSPropertyValue,
	backgroundRepeat:CSSPropertyValue,
	backgroundImage:CSSPropertyValue):ComputedBackgroundStyleVO
	{
		//get the area onto which the background image is positioned
		var backgroundPositioningArea:RectangleVO = getBackgroundPositioningArea(style, backgroundOrigin, backgroundBox);
		
		//get the absolute dimensions of the background image
		var computedBackgroundSize:DimensionVO = getComputedBackgroundSize(backgroundSize, backgroundPositioningArea,
		intrinsicWidth, intrinsicHeight, intrinsicRatio);
		
		//get the offset of the background image relative to the background box top left corner
		var computedBackgroundPosition:PointVO = getComputedBackgroundPosition(backgroundPosition,
		backgroundPositioningArea, computedBackgroundSize);
		
		//get the clipping area (the area where the background image is actually displayed)
		var computedBackgroundClip:RectangleVO = getBackgroundPaintingArea(style, backgroundClip, backgroundBox);
		
		var computedBackgroundStyle:ComputedBackgroundStyleVO = new ComputedBackgroundStyleVO();
		computedBackgroundStyle.backgroundOrigin = backgroundPositioningArea;
		computedBackgroundStyle.backgroundClip = computedBackgroundClip;
		computedBackgroundStyle.backgroundRepeat = backgroundRepeat;
		computedBackgroundStyle.backgroundImage = backgroundImage;
		computedBackgroundStyle.backgroundSize = computedBackgroundSize;
		computedBackgroundStyle.backgroundPosition = computedBackgroundPosition;
		
		return computedBackgroundStyle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
		// BACKGROUND POSITION
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the background position of the background image 
	 * (the offset from the top left corner of the background box)
	 * 
	 * @param	backgroundPosition
	 * @param	backgroundPositioningArea
	 * @param	computedBackgroundSize
	 * @param	emReference
	 * @param	exReference
	 * @return
	 */
	private static function getComputedBackgroundPosition(backgroundPosition:CSSPropertyValue, backgroundPositioningArea:RectangleVO, computedBackgroundSize:DimensionVO):PointVO
	{
		var backgroundPositionX:CSSPropertyValue = null;
		var backgroundPositionY:CSSPropertyValue = null;
		
		switch(backgroundPosition)
		{
			case GROUP(value):
				backgroundPositionX = value[0];
				backgroundPositionY = value[1];
				
			default:	
		}
		var computedBackgroundXPosition:Float = doGetComputedBackgroundPosition(backgroundPositionX, backgroundPositioningArea.width, computedBackgroundSize.width);
		var computedBackgroundYPosition:Float = doGetComputedBackgroundPosition(backgroundPositionY, backgroundPositioningArea.height, computedBackgroundSize.height);
		
		var computedBackgroundPosition:PointVO = new PointVO(computedBackgroundXPosition, computedBackgroundYPosition);
		
		return computedBackgroundPosition;
	}
	
	/**
	 * Return the x or y offset of the background image
	 */
	private static function doGetComputedBackgroundPosition(backgroundPosition:CSSPropertyValue, backgroundPositioningAreaDimension:Float, imageDimension:Float):Float
	{
		var computedBackgroundPosition:Float = 0.0;
		
		switch (backgroundPosition)
		{
			case ABSOLUTE_LENGTH(value):
				computedBackgroundPosition = value;
			
			//for percent value, it is relative to the background positioning area minus the width or height of the 
			//background image, such as for width, a 100% value will have the right side of the picture touch the right side
			//of the background positioning area
			case PERCENTAGE(value):
				computedBackgroundPosition = CSSValueConverter.getPixelFromPercent(value, backgroundPositioningAreaDimension - imageDimension);
			
			case KEYWORD(value):
				switch(value)
				{
					//same as 50%	
					case CENTER:
						computedBackgroundPosition = CSSValueConverter.getPixelFromPercent(50, backgroundPositioningAreaDimension - imageDimension);
						
					//same as 0%	
					case LEFT, TOP:
						computedBackgroundPosition = CSSValueConverter.getPixelFromPercent(0, backgroundPositioningAreaDimension - imageDimension);
						
					//same as 100%	
					case RIGHT, BOTTOM:
						computedBackgroundPosition = CSSValueConverter.getPixelFromPercent(100, backgroundPositioningAreaDimension - imageDimension);	
						
					default:	
				}
				
			default:	
		}
		
		return computedBackgroundPosition;
	}
	
			// BACKGROUND SIZE
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * 
	 * Compute the actual dimension that the 
	 * background image should have
	 * 
	 * @param	backgroundSize
	 * @param	backgroundPositioningArea
	 * @param	intrinsicWidth
	 * @param	intrinsicHeight
	 * @param	intrinsicRatio
	 * @return
	 */
	private static function getComputedBackgroundSize(backgroundSize:CSSPropertyValue, backgroundPositioningArea:RectangleVO, intrinsicWidth:Null<Float>, intrinsicHeight:Null<Float>, intrinsicRatio:Null<Float>):DimensionVO
	{
		var computedBackgroundSize:DimensionVO = new DimensionVO(0.0, 0.0);
		
		switch (backgroundSize)
		{
			case KEYWORD(value):
				switch(value)
				{
					//Scale the image, while preserving its
					//intrinsic aspect ratio (if any), to the largest size such that 
					//both its width and its height can fit inside the background positioning area.
					case CONTAIN:
						if (intrinsicRatio != null)
						{
							var ratio:Float = backgroundPositioningArea.width / backgroundPositioningArea.height;
							
							//in this case intrinsic width will be
							//inferior to available width
							if (intrinsicRatio < ratio)
							{
								computedBackgroundSize.height = backgroundPositioningArea.height;
								computedBackgroundSize.width = backgroundPositioningArea.height * intrinsicRatio;
							}
							else
							{
								computedBackgroundSize.width = backgroundPositioningArea.width;
								computedBackgroundSize.height = backgroundPositioningArea.width / intrinsicRatio;
							}
						}
						else
						{
							computedBackgroundSize.width = backgroundPositioningArea.width;
							computedBackgroundSize.height = backgroundPositioningArea.height;
						}
						
					//Scale the image, while preserving its intrinsic aspect
					//ratio (if any), to the smallest size such that both its width
					//and its height can completely cover the background positioning area.
					case COVER:				
						if (intrinsicRatio != null)
						{
							var ratio:Float = backgroundPositioningArea.width / backgroundPositioningArea.height;
							
							//in this case intrinsic width will be
							//equal to available width
							if (intrinsicRatio > ratio)
							{
								computedBackgroundSize.height = backgroundPositioningArea.height;
								computedBackgroundSize.width = backgroundPositioningArea.height * intrinsicRatio;
							}
							else
							{
								computedBackgroundSize.width = backgroundPositioningArea.width;
								computedBackgroundSize.height = backgroundPositioningArea.width / intrinsicRatio;
							}
						}
						else
						{
							computedBackgroundSize.width = backgroundPositioningArea.width;
							computedBackgroundSize.height = backgroundPositioningArea.height;
						}	
						
					case AUTO:
						
						computedBackgroundSize.width = getBackgroundSizeStyleDimensionVO(KEYWORD(AUTO), KEYWORD(AUTO), backgroundPositioningArea.width, backgroundPositioningArea.height,
						intrinsicWidth, intrinsicHeight, intrinsicRatio);
						computedBackgroundSize.height = getBackgroundSizeStyleDimensionVO(KEYWORD(AUTO), KEYWORD(AUTO), backgroundPositioningArea.height, backgroundPositioningArea.width,
						intrinsicHeight, intrinsicWidth, intrinsicRatio);
						
					default:	
				}
				
				case ABSOLUTE_LENGTH(value):
					computedBackgroundSize.width = getBackgroundSizeStyleDimensionVO(backgroundSize, KEYWORD(AUTO), backgroundPositioningArea.width, backgroundPositioningArea.height,
					intrinsicWidth, intrinsicHeight, intrinsicRatio);
					computedBackgroundSize.height = getBackgroundSizeStyleDimensionVO(KEYWORD(AUTO), backgroundSize, backgroundPositioningArea.height, backgroundPositioningArea.width,
					intrinsicHeight, intrinsicWidth, intrinsicRatio);
					
					
				case PERCENTAGE(value):	
					computedBackgroundSize.width = getBackgroundSizeStyleDimensionVO(backgroundSize, KEYWORD(AUTO), backgroundPositioningArea.width, backgroundPositioningArea.height,
					intrinsicWidth, intrinsicHeight, intrinsicRatio);
					computedBackgroundSize.height = getBackgroundSizeStyleDimensionVO(KEYWORD(AUTO), backgroundSize, backgroundPositioningArea.height, backgroundPositioningArea.width,
					intrinsicHeight, intrinsicWidth, intrinsicRatio);
					
					
				case GROUP(value):
					computedBackgroundSize.width = getBackgroundSizeStyleDimensionVO(value[0], value[1], backgroundPositioningArea.width, backgroundPositioningArea.height,
					intrinsicWidth, intrinsicHeight, intrinsicRatio);
					computedBackgroundSize.height = getBackgroundSizeStyleDimensionVO(value[1], value[0], backgroundPositioningArea.height, backgroundPositioningArea.width,
					intrinsicHeight, intrinsicWidth, intrinsicRatio);
					
				default:	
		}
		
		return computedBackgroundSize;
	}
	
	/**
	 * Return the width or height of the background image, sized with 
	 * a length, percentage or auto value
	 * 
	 * @param	value
	 * @param	opositeBackgroundSizeValue
	 * @param	backgroundPositioningAreaDimension
	 * @param	intrinsicDimension
	 * @param	opositeIntrinsicDimension
	 * @param	intrinsicRatio
	 * @return
	 */
	private static function getBackgroundSizeStyleDimensionVO(backgroundSizeValue:CSSPropertyValue, opositeBackgroundSizeValue:CSSPropertyValue,
	backgroundPositioningAreaDimension:Float, opositeBackgroundAreaDimension:Float, intrinsicDimension:Null<Float>, opositeIntrinsicDimension:Null<Float>, intrinsicRatio:Null<Float>):Float
	{
		var backgroundSizeStyleDimension:Float = 0.0;
		
		switch (backgroundSizeValue)
		{
			case ABSOLUTE_LENGTH(value):
				backgroundSizeStyleDimension = value;
			
			//percent relative to the background positioning area	
			case PERCENTAGE(value):
				backgroundSizeStyleDimension = CSSValueConverter.getPixelFromPercent(value, backgroundPositioningAreaDimension);
			
			//for auto, use intrinsic dimension if any or else,
			//treated as a 100% value
			case KEYWORD(value):
				if (value == AUTO)
				{
					var isOpositeAuto:Bool = false;
					switch(opositeBackgroundSizeValue)
					{
						case KEYWORD(value):
							if (value == AUTO)
							{
								isOpositeAuto = true;
							}
						default:	
					}
					
					//if the other dimension is also auto, use the intrinsic dimension if any
					if (intrinsicDimension != null && isOpositeAuto == true)
					{
						backgroundSizeStyleDimension = intrinsicDimension;
					}
					//if the other dimension is not auto, compute it and use a ratio of its dimension
					//to keep the proportion of the background image
					else if (opositeIntrinsicDimension != null && intrinsicRatio != null)
					{
						var opositeDimension:Float = getBackgroundSizeStyleDimensionVO(opositeBackgroundSizeValue, backgroundSizeValue,
						opositeBackgroundAreaDimension, backgroundPositioningAreaDimension, opositeIntrinsicDimension, intrinsicDimension,
						intrinsicRatio);
						
						backgroundSizeStyleDimension = opositeDimension * intrinsicRatio;
					}
					//if the background image doesn't have intrinsic dimensions, treat it like 100%
					else
					{
						backgroundSizeStyleDimension = CSSValueConverter.getPixelFromPercent(100, backgroundPositioningAreaDimension);
					}
				}
				
			default:	
				
		}
		
		return backgroundSizeStyleDimension;
	}
	//
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the rectangle of the positioning area, the area whose top left
	 * corner will be used as origin for the background image. 
	 * This area can be sized to the border, padding or content box
	 * of the background box
	 * 
	 * The positioning area is defined in the space of the margin box of the HTMLElement
	 * 
	 * @param	style
	 * @param	backgroundOrigin
	 * @return
	 */
	private static function getBackgroundPositioningArea(style:CoreStyle, backgroundOrigin:CSSPropertyValue, backgroundBox:RectangleVO):RectangleVO
	{
		var height:Float = 0.0;
		var width:Float =  0.0;
		var x:Float = 0.0;
		var y:Float = 0.0;
		
		switch (backgroundOrigin)
		{
			case KEYWORD(value):
				switch(value)
				{
					case BORDER_BOX:
						height = backgroundBox.height;
						width = backgroundBox.width;
						x = 0.0;
						y = 0.0;
						
						
					case PADDING_BOX:
						height = backgroundBox.height;
						width = backgroundBox.width;
						x = 0.0;
						y = 0.0;
						
						
					case CONTENT_BOX:
						height = backgroundBox.height - style.usedValues.marginTop - style.usedValues.marginBottom - style.usedValues.paddingTop - style.usedValues.paddingBottom - style.usedValues.borderTopWidth - style.usedValues.borderBottomWidth;
						width = backgroundBox.width - style.usedValues.marginLeft - style.usedValues.marginRight - style.usedValues.paddingLeft - style.usedValues.paddingRight - style.usedValues.borderLeftWidth - style.usedValues.borderRightWidth;
						x = 0.0;
						y = 0.0;
						
					default:	
				}
				
			default:
		}
		var rectangle:RectangleVO = new RectangleVO();
		rectangle.x = x;
		rectangle.y = y;
		rectangle.width = width;
		rectangle.height = height;
		return rectangle;
	}
	
	/**
	 * Return the rectangle of the painting area, the area where
	 * the background image will be actually displayed, all the pixels
	 * overflowing are clipped. It can be smaller than the background
	 * positioning area.
	 * 
	 * The painting area is defined in the space of the margin box
	 * of the HTMLElement,like the positioning area
	 * 
	 * @param	style
	 * @param	backgroundClip
	 * @param	backgroundBox
	 * @return
	 */
	private static function getBackgroundPaintingArea(style:CoreStyle, backgroundClip:CSSPropertyValue, backgroundBox:RectangleVO):RectangleVO
	{
		var height:Float = 0.0;
		var width:Float = 0.0;
		var x:Float = 0.0;
		var y:Float = 0.0;
		
		switch (backgroundClip)
		{
			case KEYWORD(value):
				switch(value)
				{
					case BORDER_BOX:
						height = backgroundBox.height;
						width = backgroundBox.width;
						x = 0.0;
						y = 0.0;
						
					case PADDING_BOX:
						height = backgroundBox.height;
						width = backgroundBox.width;
						x = style.usedValues.marginLeft;
						y = style.usedValues.marginTop;
						
						
					case CONTENT_BOX:
						height = backgroundBox.height - style.usedValues.marginTop - style.usedValues.marginBottom - style.usedValues.paddingTop - style.usedValues.paddingBottom - style.usedValues.borderTopWidth - style.usedValues.borderBottomWidth;
						width = backgroundBox.width - style.usedValues.marginLeft - style.usedValues.marginRight - style.usedValues.paddingLeft - style.usedValues.paddingRight - style.usedValues.borderLeftWidth - style.usedValues.borderRightWidth;
						x = style.usedValues.marginLeft + style.usedValues.paddingLeft + style.usedValues.borderLeftWidth;
						y = style.usedValues.marginTop + style.usedValues.paddingTop + style.usedValues.borderTopWidth;
						
					default:	
				}
				
			default:	
		}
		
		var rectangle:RectangleVO = new RectangleVO();
		rectangle.x = x;
		rectangle.y = y;
		rectangle.width = width;
		rectangle.height = height;
		
		return rectangle;
	}
}
