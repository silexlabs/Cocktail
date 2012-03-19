/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.background;

import cocktail.geom.Matrix;
import core.nativeElement.NativeElement;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import core.drawing.DrawingManager;
import cocktail.geom.GeomData;
import core.unit.UnitData;
import cocktail.style.StyleData;
import cocktailCore.resource.ImageLoader;
import cocktail.domElement.DOMElementData;
import core.unit.UnitManager;
import haxe.Log;

/**
 * This class extends the cross-platform drawing manager
 * with added methods targeted at drawing backround elements,
 * such as background color, bitmap and gradient
 * 
 * @author Yannick DOMINGUEZ
 */
class BackgroundDrawingManager extends DrawingManager
{
	/**
	 * class constructor. Init a drawing surface (for instance BitmapData in Flash)
	 * of the same size as the backgroundBox
	 * 
	 * @param	nativeElement
	 * @param	backgroundBox
	 */
	public function new(nativeElement:NativeElement, backgroundBox:RectangleData) 
	{
		super(nativeElement, Math.round(backgroundBox.width), Math.round(backgroundBox.height));
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw a background image form a nativeImage source.
	 * The nativeImage source is repeated and transformed
	 * as necessary to match the computed background
	 * styles
	 * 
	 * @param	nativeImage
	 * @param	backgroundPositioningBox
	 * @param	backgroundPaintingBox
	 * @param	intrinsicWidth
	 * @param	intrinsicHeight
	 * @param	intrinsicRatio
	 * @param	computedBackgroundSize
	 * @param	computedBackgroundPosition
	 * @param	backgroundRepeat
	 */
	public function drawBackgroundImage(nativeImage:NativeElement, backgroundPositioningBox:RectangleData, backgroundPaintingBox:RectangleData, intrinsicWidth:Int, intrinsicHeight:Int, intrinsicRatio:Float, computedBackgroundSize:DimensionData, computedBackgroundPosition:PointData, backgroundRepeat:BackgroundRepeat):Void
	{
		var totalWidth:Int = Math.round(computedBackgroundPosition.x) + Math.round(backgroundPositioningBox.x);
		var maxWidth:Int =  Math.round(backgroundPaintingBox.x + backgroundPaintingBox.width);
		var imageWidth:Int = Math.round(computedBackgroundSize.width);
		
		switch (backgroundRepeat.x)
		{
			case BackgroundRepeatStyleValue.noRepeat:
				maxWidth = totalWidth + imageWidth;
				
			case BackgroundRepeatStyleValue.repeat:
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				
			case BackgroundRepeatStyleValue.space:
				imageWidth = Math.round(backgroundPositioningBox.width / computedBackgroundSize.width);
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				
			case BackgroundRepeatStyleValue.round:
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
		}
		var initialWidth:Int = totalWidth;
		
		var totalHeight:Float = computedBackgroundPosition.y + Math.round(backgroundPositioningBox.y);
		var maxHeight:Float = backgroundPaintingBox.y + backgroundPaintingBox.height;
		var imageHeight:Float = computedBackgroundSize.height;
		
		switch (backgroundRepeat.y)
		{
			case BackgroundRepeatStyleValue.noRepeat:
				maxHeight = totalHeight + imageHeight;
				
			case BackgroundRepeatStyleValue.repeat:
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				
			case BackgroundRepeatStyleValue.space:
				imageHeight = backgroundPositioningBox.height / computedBackgroundSize.height;
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				
			case BackgroundRepeatStyleValue.round:
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
		}
		
		var initialHeight:Float = totalHeight;
		
		while (totalHeight < maxHeight)
		{
			var matrix:Matrix = new Matrix();
		
			matrix.translate(totalWidth, totalHeight);
			
			matrix.scale(imageWidth / intrinsicWidth ,  imageHeight / intrinsicHeight, { x:0.0, y:0.0 } );
			
			drawImage(nativeImage, matrix, backgroundPaintingBox);
			
			totalWidth += imageWidth;
			
			if (totalWidth >= maxWidth)
			{
				totalWidth = initialWidth;
				totalHeight += imageHeight;
			}
		}
	}
	
	/**
	 * Draw a background color (a monochrome rgba rectangle) using the
	 * size of the background painting box.
	 * 
	 * @param	color
	 * @param	backgroundPaintingBox
	 */
	public function drawBackgroundColor(color:ColorData, backgroundPaintingBox:RectangleData):Void
	{	
		var fillStyle:FillStyleValue = FillStyleValue.monochrome( color );
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		beginFill(fillStyle, lineStyle);
		drawRect(Math.round(backgroundPaintingBox.x), Math.round(backgroundPaintingBox.y), Math.round(backgroundPaintingBox.width), Math.round(backgroundPaintingBox.height));
		
		endFill();
	}
	
	/**
	 * Draw a background gradient programmaticaly. The 
	 * gradient is first drawn on another drawing manager using
	 * the dimensions defined by the computed background size, 
	 * then the drawn gradient is used like as a background
	 * image and drawn using the drawBackgroundImage method
	 * 
	 * @param	gradient
	 * @param	backgroundPositioningBox
	 * @param	backgroundPaintingBox
	 * @param	computedBackgroundSize
	 * @param	computedBackgroundPosition
	 * @param	backgroundRepeat
	 */
	public function drawBackgroundGradient(gradient:GradientValue, backgroundPositioningBox:RectangleData, backgroundPaintingBox:RectangleData, computedBackgroundSize:DimensionData, computedBackgroundPosition:PointData, backgroundRepeat:BackgroundRepeat):Void
	{
		var gradientSurface:DrawingManager = new DrawingManager(NativeElementManager.createNativeElement(NativeElementTypeValue.graphic), computedBackgroundSize.width, computedBackgroundSize.height);
		
		var fillStyle:FillStyleValue;
		var lineStyle = LineStyleValue.none;
		
		switch(gradient)
		{
			
			case GradientValue.linear(value):
				var gradientStyle:GradientStyleData = {
					gradientType:GradientTypeValue.linear,
					gradientStops:getGradientStops(value.colorStops),
					rotation:getRotation(value.angle)
				}
				
				//TODO : clean this up
				#if flash9
				//gradientStyle.rotation -= 90;
				#end
				fillStyle = FillStyleValue.gradient(gradientStyle);
		}
		
		gradientSurface.beginFill(fillStyle, lineStyle);
		gradientSurface.drawRect(0, 0, computedBackgroundSize.width, computedBackgroundSize.height);
		gradientSurface.endFill();
		
		drawBackgroundImage(gradientSurface.nativeElement, backgroundPositioningBox, backgroundPaintingBox, computedBackgroundSize.width, computedBackgroundSize.height, computedBackgroundSize.width / computedBackgroundSize.height, computedBackgroundSize, computedBackgroundPosition, backgroundRepeat);
		
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getGradientStops(value:Array<GradientColorStopData>):Array<GradientStopData>
	{
		var gradientStopsData:Array<GradientStopData> = new Array<GradientStopData>();
		
		for (i in 0...value.length)
		{
			var ratio:Int;
	
			switch (value[i].stop)
			{
				case GradientStopValue.length(value):
					//TODO
					ratio = 0;
					
				case GradientStopValue.percent(value):
					ratio = value;
			}
			
			var color:ColorData = UnitManager.getColorDataFromColorValue(value[i].color);
			gradientStopsData.push( { colorStop:color, ratio:ratio } );
		}
		
		return gradientStopsData;
	}
		
	
	private function getRotation(value:GradientAngle):Int
	{
		var rotation:Int;
		
		switch (value)
		{
			case GradientAngle.angle(value):
				rotation = Math.round(UnitManager.getDegreeFromAngle(value));
				
			case GradientAngle.side(value):
			
				switch (value)
				{
					case GradientSideValue.top:
						rotation = 0;
						
					case GradientSideValue.right:
						rotation = 90;
						
					case GradientSideValue.bottom:
						rotation = 180;
						
					case GradientSideValue.left:
						rotation = 270;
				}
			
			
			case GradientAngle.corner(value):
			
				switch (value)
				{
					case GradientCornerValue.topRight:
						rotation = 45;
						
					case GradientCornerValue.bottomRight:
						rotation = 135;
						
					case GradientCornerValue.bottomLeft:
						rotation = 225;
						
					case GradientCornerValue.topLeft:
						rotation = 315;
				}
			
		}
		
		return rotation;
	}
	
}