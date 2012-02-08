/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer;

import cocktailCore.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import cocktailCore.unit.UnitManager;
import cocktail.geom.GeomData;
import cocktail.unit.UnitData;
import haxe.Log;

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
 * for instance for an inline DOMElement displayed on multiple
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
	 * Compute the background styles which can be computed 
	 * when the layout is done. the background boxes and
	 * the dimensions of the background images are not yet
	 * known
	 */
	public static function compute(style:AbstractStyle):Void
	{
		//actually compute the background color
		style.computedStyle.backgroundColor = getComputedBackgroundColor(style);
		
		style.computedStyle.backgroundRepeat = style.backgroundRepeat;
		
		style.computedStyle.backgroundClip = style.backgroundClip;
		
		style.computedStyle.backgroundSize = style.backgroundSize;
		
		style.computedStyle.backgroundPosition = style.backgroundPosition;

		style.computedStyle.backgroundOrigin = style.backgroundOrigin;
		
		style.computedStyle.backgroundImage = style.backgroundImage;

	}
	
	/**
	 * This method is called during rendering for each background image of a DOMElement
	 * for each background boxes
	 * 
	 * At this point, all the background boxes of the DOMElement are known and also
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
	public static function computeIndividualBackground(style:AbstractStyle, backgroundBox:RectangleData,
	intrinsicWidth:Null<Int>, intrinsicHeight:Null<Int>, intrinsicRatio:Null<Float>, 
	backgroundPosition:BackgroundPositionStyleData,
	backgroundSize:BackgroundSizeStyleValue,
	backgroundOrigin:BackgroundOriginStyleValue,
	backgroundClip:BackgroundClipStyleValue,
	backgroundRepeat:BackgroundRepeatStyleData,
	backgroundImage:BackgroundImageStyleValue):ComputedBackgroundStyleData
	{
		//get the area onto which the background image is positioned
		var backgroundPositioningArea:RectangleData = getBackgroundPositioningArea(style, backgroundOrigin, backgroundBox);
		
		//get the absolute dimensions of the background image
		var computedBackgroundSize:DimensionData = getComputedBackgroundSize(backgroundSize, backgroundPositioningArea,
		intrinsicWidth, intrinsicHeight, intrinsicRatio, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//get the offset of the background image relative to the background box top left corner
		var computedBackgroundPosition:PointData = getComputedBackgroundPosition(backgroundPosition,
		backgroundPositioningArea, computedBackgroundSize, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//get the clipping area (the area where the background image is actually displayed)
		var computedBackgroundClip:RectangleData = getBackgroundPaintingArea(style, backgroundClip, backgroundBox);
		
		var computedBackgroundStyle:ComputedBackgroundStyleData = {
			backgroundOrigin:backgroundPositioningArea,
			backgroundClip:computedBackgroundClip,
			backgroundRepeat:backgroundRepeat,
			backgroundImage:backgroundImage,
			backgroundSize:computedBackgroundSize,
			backgroundPosition:computedBackgroundPosition
		}
		
		return computedBackgroundStyle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
		// BACKGROUND COLOR
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the background color as an integer
	 */
	private static function getComputedBackgroundColor(style:AbstractStyle):ColorData
	{
		var computedColor:ColorData;
		
		switch (style.backgroundColor)
		{
			case BackgroundColorStyleValue.colorValue(value):
				computedColor = UnitManager.getColorDataFromColorValue(value);
		}
		
		return computedColor;
	}
	
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
	private static function getComputedBackgroundPosition(backgroundPosition:BackgroundPositionStyleData, backgroundPositioningArea:RectangleData, computedBackgroundSize:DimensionData, emReference:Float, exReference:Float):PointData
	{
		var computedBackgroundXPosition:Float = getComputedBackgroundXPosition(backgroundPosition.x, Math.round(backgroundPositioningArea.width), computedBackgroundSize.width,  emReference, exReference);
		var computedBackgroundYPosition:Float = getComputedBackgroundYPosition(backgroundPosition.y, Math.round(backgroundPositioningArea.height), computedBackgroundSize.height, emReference, exReference);
		
		var computedBackgroundPosition:PointData = {
			x:computedBackgroundXPosition,
			y:computedBackgroundYPosition
		};
		return computedBackgroundPosition;
	}
	
	/**
	 * Return the x offset of the background image
	 */
	private static function getComputedBackgroundXPosition(backgroundPosition:BackgroundPositionXStyleValue, backgroundPositioningAreaDimension:Int, imageDimension:Int, emReference:Float, exReference:Float):Int
	{
		var computedBackgroundXPosition:Int;
		
		switch (backgroundPosition)
		{
			case BackgroundPositionXStyleValue.length(value):
				computedBackgroundXPosition = UnitManager.getPixelFromLengthValue(value, emReference, exReference);
			
			//for percent value, it is relative to the background positioning area minus the width of the 
			//background image, such as a 100% will have the right side of the picture touch the right side
			//of the background positioning area
			case BackgroundPositionXStyleValue.percent(value):
				computedBackgroundXPosition = Math.round(UnitManager.getPixelFromPercent(value, backgroundPositioningAreaDimension - imageDimension)) ;
			
			//same as 50%	
			case BackgroundPositionXStyleValue.center:
				computedBackgroundXPosition = Math.round(UnitManager.getPixelFromPercent(50, backgroundPositioningAreaDimension - imageDimension)) ;
			
			//same as 0%	
			case BackgroundPositionXStyleValue.left:
				computedBackgroundXPosition = Math.round(UnitManager.getPixelFromPercent(0, backgroundPositioningAreaDimension - imageDimension)) ;
			
			//same as 100%	
			case BackgroundPositionXStyleValue.right:
				computedBackgroundXPosition = Math.round(UnitManager.getPixelFromPercent(100, backgroundPositioningAreaDimension - imageDimension)) ;
		}
		
		return computedBackgroundXPosition;
	}
	
	/**
	 * Return the y offset of the background image. Same as getComputedBackgroundXPosition
	 */
	private static function getComputedBackgroundYPosition(backgroundPosition:BackgroundPositionYStyleValue, backgroundPositioningAreaDimension:Int, imageDimension:Int, emReference:Float, exReference:Float):Int
	{
		var computedBackgroundYPosition:Int;
		
		switch (backgroundPosition)
		{
			case BackgroundPositionYStyleValue.length(value):
				computedBackgroundYPosition = UnitManager.getPixelFromLengthValue(value, emReference, exReference);
				
			case BackgroundPositionYStyleValue.percent(value):
				computedBackgroundYPosition = Math.round(UnitManager.getPixelFromPercent(value, backgroundPositioningAreaDimension - imageDimension)) ;
				
			case BackgroundPositionYStyleValue.center:
				computedBackgroundYPosition = Math.round(UnitManager.getPixelFromPercent(50, backgroundPositioningAreaDimension - imageDimension)) ;
				
			case BackgroundPositionYStyleValue.top:
				computedBackgroundYPosition = Math.round(UnitManager.getPixelFromPercent(0, backgroundPositioningAreaDimension - imageDimension)) ;
				
			case BackgroundPositionYStyleValue.bottom:
				computedBackgroundYPosition = Math.round(UnitManager.getPixelFromPercent(100, backgroundPositioningAreaDimension - imageDimension)) ;
		}
		
		return computedBackgroundYPosition;
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
	 * @param	emReference
	 * @param	exReference
	 * @return
	 */
	private static function getComputedBackgroundSize(backgroundSize:BackgroundSizeStyleValue, backgroundPositioningArea:RectangleData, intrinsicWidth:Null<Int>, intrinsicHeight:Null<Int>, intrinsicRatio:Null<Float>, emReference:Float, exReference:Float):DimensionData
	{
		var computedBackgroundSize:DimensionData;
		
		switch (backgroundSize)
		{
			//Scale the image, while preserving its
			//intrinsic aspect ratio (if any), to the largest size such that 
			//both its width and its height can fit inside the background positioning area.
			case BackgroundSizeStyleValue.contain:
				if (intrinsicRatio != null)
				{
					var ratio:Float = intrinsicRatio / (backgroundPositioningArea.width / backgroundPositioningArea.height);
					
					computedBackgroundSize = {
						width:Math.round(intrinsicWidth * ratio),
						height:Math.round(intrinsicHeight * ratio)
					}
				}
				else
				{
					computedBackgroundSize = {
						width:Math.round(backgroundPositioningArea.width),
						height:Math.round(backgroundPositioningArea.height)
					}
				}
				
			//Scale the image, while preserving its intrinsic aspect
			//ratio (if any), to the smallest size such that both its width
			//and its height can completely cover the background positioning area. 	
			case BackgroundSizeStyleValue.cover:
				if (intrinsicRatio != null)
				{
					var ratio:Float =  (backgroundPositioningArea.width / backgroundPositioningArea.height) / intrinsicRatio;
					
					computedBackgroundSize = {
						width:Math.round(intrinsicWidth * ratio),
						height:Math.round(intrinsicHeight * ratio)
					}
				}
				else
				{
					computedBackgroundSize = {
						width:Math.round(backgroundPositioningArea.width),
						height:Math.round(backgroundPositioningArea.height)
					}
				}	
			
				
			case BackgroundSizeStyleValue.dimensions(value):
				computedBackgroundSize = {
					width:getBackgroundSizeStyleDimensionData(value.x, value.y, Math.round(backgroundPositioningArea.width), Math.round(backgroundPositioningArea.height),
					intrinsicWidth, intrinsicHeight, intrinsicRatio, emReference, exReference),
					height:getBackgroundSizeStyleDimensionData(value.y, value.x, Math.round(backgroundPositioningArea.height), Math.round(backgroundPositioningArea.width),
					intrinsicHeight, intrinsicWidth, intrinsicRatio, emReference, exReference)
				}
		}
		
		return computedBackgroundSize;
	}
	
	/**
	 * Return the width or height of the background image, sized with 
	 * a length, percentage or auto value
	 * 
	 * @param	value
	 * @param	opositeBackgroundSizeStyleDimensionValue
	 * @param	backgroundPositioningAreaDimension
	 * @param	intrinsicDimension
	 * @param	opositeIntrinsicDimension
	 * @param	intrinsicRatio
	 * @param	emReference
	 * @param	exReference
	 * @return
	 */
	private static function getBackgroundSizeStyleDimensionData(value:BackgroundSizeStyleDimensionValue, opositeBackgroundSizeStyleDimensionValue:BackgroundSizeStyleDimensionValue,
	backgroundPositioningAreaDimension:Int, opositeBackgroundAreaDimension:Int, intrinsicDimension:Null<Int>, opositeIntrinsicDimension:Null<Int>, intrinsicRatio:Null<Float>,
	emReference:Float, exReference:Float):Int
	{
		var backgroundSizeStyleDimension:Int;
		
		switch (value)
		{
			//absolute or relative length value
			case BackgroundSizeStyleDimensionValue.length(value):
				backgroundSizeStyleDimension = UnitManager.getPixelFromLengthValue(value, emReference, exReference);
			
			//percent relative to the background positioning area	
			case BackgroundSizeStyleDimensionValue.percent(value):
				backgroundSizeStyleDimension = Math.round(UnitManager.getPixelFromPercent(value, backgroundPositioningAreaDimension));
			
			//for auto, use intrinsic dimension if any or else,
			//treated as a 100% value
			case BackgroundSizeStyleDimensionValue.auto:
				//if the other dimension is alos auto, use the intrinsic dimension if any
				if (intrinsicDimension != null && opositeBackgroundSizeStyleDimensionValue == BackgroundSizeStyleDimensionValue.auto)
				{
					backgroundSizeStyleDimension = intrinsicDimension;
				}
				//if the other dimension is not auto, compute it and use a ratio of its dimension
				//to keep the proportion of the background image
				else if (opositeIntrinsicDimension != null && intrinsicRatio != null)
				{
					var opositeDimension:Int = getBackgroundSizeStyleDimensionData(opositeBackgroundSizeStyleDimensionValue, value,
					opositeBackgroundAreaDimension, backgroundPositioningAreaDimension, opositeIntrinsicDimension, intrinsicDimension,
					intrinsicRatio, emReference, exReference);
					
					backgroundSizeStyleDimension = Math.round(opositeDimension * intrinsicRatio);
				}
				//if the background image doesn't have intrinsic dimensions, treat it like 100%
				else
				{
					backgroundSizeStyleDimension = Math.round(UnitManager.getPixelFromPercent(100, backgroundPositioningAreaDimension));
				}
		}
		
		return backgroundSizeStyleDimension;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the rectangle of the positioning area, the area whose top left
	 * corner will be used as origin for the background image. 
	 * This area can be sized to the border, padding or content box
	 * of the background box
	 * 
	 * The positioning area is defined in the space of the margin box of the DOMElement
	 * 
	 * @param	style
	 * @param	backgroundOrigin
	 * @return
	 */
	private static function getBackgroundPositioningArea(style:AbstractStyle, backgroundOrigin:BackgroundOriginStyleValue, backgroundBox:RectangleData):RectangleData
	{
		var backgroundPositioningArea:RectangleData;
		
		var height:Float;
		var width:Float;
		var x:Float;
		var y:Float;
		
		switch (backgroundOrigin)
		{
			case BackgroundOriginStyleValue.borderBox:
				height = backgroundBox.height - style.computedStyle.marginTop - style.computedStyle.marginBottom;
				width = backgroundBox.width - style.computedStyle.marginLeft - style.computedStyle.marginRight;
				x = style.computedStyle.marginLeft;
				y = style.computedStyle.marginRight;
				
				
			case BackgroundOriginStyleValue.paddingBox:
				height = backgroundBox.height - style.computedStyle.marginTop - style.computedStyle.marginBottom;
				width = backgroundBox.width - style.computedStyle.marginLeft - style.computedStyle.marginRight;
				x = style.computedStyle.marginLeft;
				y = style.computedStyle.marginRight;
				
				
			case BackgroundOriginStyleValue.contentBox:
				height = backgroundBox.height - style.computedStyle.marginTop - style.computedStyle.marginBottom - style.computedStyle.paddingTop - style.computedStyle.paddingBottom;
				width = backgroundBox.width - style.computedStyle.marginLeft - style.computedStyle.marginRight - style.computedStyle.paddingLeft - style.computedStyle.paddingRight;
				x = style.computedStyle.marginLeft + style.computedStyle.paddingLeft;
				y = style.computedStyle.marginRight + style.computedStyle.paddingTop;
				
		}
		
		backgroundPositioningArea = {
			height:height,
			width:width,
			x:x,
			y:y
		}
		
		return backgroundPositioningArea;
	}
	
	/**
	 * Return the rectangle of the painting area, the area where
	 * the background image will be actually displayed, all the pixels
	 * overflowing are clipped. It can be smaller than the background
	 * positioning area.
	 * 
	 * The painting area is defined in the space of the margin box
	 * of the DOMElement,like the positioning area
	 * 
	 * @param	style
	 * @param	backgroundClip
	 * @param	backgroundBox
	 * @return
	 */
	private static function getBackgroundPaintingArea(style:AbstractStyle, backgroundClip:BackgroundClipStyleValue, backgroundBox:RectangleData):RectangleData
	{
		var backgroundPaintingArea:RectangleData;
		
		var height:Float;
		var width:Float;
		var x:Float;
		var y:Float;
		
		switch (backgroundClip)
		{
			case BackgroundClipStyleValue.borderBox:
				height = backgroundBox.height - style.computedStyle.marginTop - style.computedStyle.marginBottom;
				width = backgroundBox.width - style.computedStyle.marginLeft - style.computedStyle.marginRight;
				x = style.computedStyle.marginLeft;
				y = style.computedStyle.marginRight;
				
				
			case BackgroundClipStyleValue.paddingBox:
				height = backgroundBox.height - style.computedStyle.marginTop - style.computedStyle.marginBottom;
				width = backgroundBox.width - style.computedStyle.marginLeft - style.computedStyle.marginRight;
				x = style.computedStyle.marginLeft;
				y = style.computedStyle.marginRight;
				
				
			case BackgroundClipStyleValue.contentBox:
				height = backgroundBox.height - style.computedStyle.marginTop - style.computedStyle.marginBottom - style.computedStyle.paddingTop - style.computedStyle.paddingBottom;
				width = backgroundBox.width - style.computedStyle.marginLeft - style.computedStyle.marginRight - style.computedStyle.paddingLeft - style.computedStyle.paddingRight;
				x = style.computedStyle.marginLeft + style.computedStyle.paddingLeft;
				y = style.computedStyle.marginRight + style.computedStyle.paddingTop;
				
		}
		
		backgroundPaintingArea = {
			height:height,
			width:width,
			x:x,
			y:y
		}
		
		return backgroundPaintingArea;
	}
}