/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.flash_player;

import core.nativeElement.NativeElement;
import core.drawing.AbstractDrawingManager;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.CapsStyle;
import flash.display.GradientType;
import flash.display.JointStyle;
import flash.display.LineScaleMode;
import flash.display.Sprite;
import core.geom.Matrix;
import core.dom.DOMData;
import core.geom.GeomData;
import flash.geom.ColorTransform;
import haxe.Log;

/**
 * This is the Flash AVM2 implementation of the DrawingManager.
 * It draws shape programatically onto a native Sprite object.
 * The sprite HTMLElement is then cached as a bitmap. It allows to work
 * with both the flash vector drawing API and bitmaps.
 * 
 * @author Yannick DOMINGUEZ
 */
class DrawingManager extends AbstractDrawingManager
{	
	/**
	 * a bitmap display object onto which 
	 * are drawn bitmap and/or rasterised
	 * vector drawings
	 */
	private var _bitmapDrawing:Bitmap;
	
	/**
	 * Cast the nativeElement as a sprite to access the 
	 * graphics object
	 */
	private var _typedNativeElement:Sprite;
	
	/**
	 * class constructor. Init the background Sprite with
	 * a default width and height. Add a bitmap display object that
	 * will copy the vector drawing as they are drawn
	 */
	public function new(nativeElement:NativeElement, width:Int, height:Int) 
	{
		super(nativeElement, width, height);
		
		_typedNativeElement = cast(this._nativeElement);
		
		//init the bitmap display object and attach it to the display list
		_bitmapDrawing = new Bitmap(new BitmapData(_width, _height, true, 0x00000000));
		this._nativeElement.addChild(_bitmapDrawing);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden fill control methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Ends a fill on the native Sprite's graphic object.
	 * Convert the resulting vector into a bitmap
	 */
	override public function endFill():Void
	{
		_typedNativeElement.graphics.endFill();
		blit();
		_typedNativeElement.graphics.clear();
	}
	
	/**
	 * clear the vector and bitmap drawing
	 */
	override public function clear():Void
	{
		_typedNativeElement.graphics.clear();
		_bitmapDrawing.bitmapData.fillRect(new flash.geom.Rectangle(0, 0, width, height), 0x00000000);
	}
		
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private pixel manipulation method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Turn the current drawn graphic object into a bitmap. Each graphic object is drawn
	 * into the same bitmap as they are drawn (done on each call to the endFill method).
	 */
	private function blit():Void
	{ 
		
		//create a new transparent bitmap data, the size of the vector drawing
		var currentGraphicBitmapData:BitmapData = new BitmapData(Math.round(_typedNativeElement.width), Math.round(_typedNativeElement.height), true, 0x00000000);
		
		//draw the current vector into a bitmap
		currentGraphicBitmapData.draw(_typedNativeElement);
		
		//retrive the current bitmapData (the sum of all the previous
		//vector drawings)
		var bitmapData:BitmapData = _bitmapDrawing.bitmapData;
		
		//copy each pixel from the new vector drawing into the current bitmapData,
		//preserving the alpha values
		bitmapData.copyPixels(currentGraphicBitmapData, new flash.geom.Rectangle(0, 0, width, height), new flash.geom.Point(0, 0));
		
		//set the bitmapData on the bitmap display object
		_bitmapDrawing.bitmapData = bitmapData;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Private fill control methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Do set the fill style on the Sprite
	 * @param	fillStyle
	 */
	override public function setFillStyle(fillStyle:FillStyleValue):Void
	{
		switch(fillStyle)
		{
			//if there must be no fill style (probably only a stroke style)
			//start a transparent fill
			case none:
				_typedNativeElement.graphics.beginFill(0,0);
			
			//for a fill style with one color, use the native beginFill method
			case monochrome(colorStop):
				_typedNativeElement.graphics.beginFill(colorStop.color, toNativeAlpha(colorStop.alpha));
			
			//for a gradient fill, use the beginGradientFill native method
			case gradient(gradientStyle):
				
				_typedNativeElement.graphics.beginGradientFill(
					getGradientType(gradientStyle.gradientType),
					getGradientColors(gradientStyle.gradientStops),
					getGradientAlphas(gradientStyle.gradientStops),
					getGradientRatios(gradientStyle.gradientStops),
					getGradientBox(gradientStyle)
				);
		
			//for a bitmap fill, use the natvie beginBitmapFill method, using
			//an ImageHTMLElement as source for the bitmap data
			case bitmap(imageHTMLElement, repeat):
				_typedNativeElement.graphics.beginBitmapFill(getBitmapData(imageHTMLElement.nativeElement), new flash.geom.Matrix(), repeat);
		}	
	}
	
	/**
	 * Do set the lineStyle on the Sprite
	 * @param	lineStyle
	 */
	override public function setLineStyle(lineStyle:LineStyleValue):Void
	{
		switch(lineStyle)
		{
			//if there must be no line (probably just a fill instead), do nothing
			case none:
				
			//if there must be a one-color line, use the native lineStyle method
			case monochrome(color, lineStyleData):
				//set the line style
				_typedNativeElement.graphics.lineStyle(
					lineStyleData.thickness,
					color.color,
					toNativeAlpha(color.alpha),
					true,
					LineScaleMode.NORMAL,
					toNativeCapStyle(lineStyleData.capStyle),
					toNativeJointStyle(lineStyleData.jointStyle),
					lineStyleData.miterLimit);			
			
			//for a gradient line, 	use the native lineGradientStyle method	
			case gradient(gradientStyle, lineStyleData):
				
				//set first the line style so that the line is visible	
				_typedNativeElement.graphics.lineStyle(
					lineStyleData.thickness,
					0,
					1,
					true,
					LineScaleMode.NONE,
					toNativeCapStyle(lineStyleData.capStyle),
					toNativeJointStyle(lineStyleData.jointStyle),
					lineStyleData.miterLimit);
					
				_typedNativeElement.graphics.lineGradientStyle(
					getGradientType(gradientStyle.gradientType),
					getGradientColors(gradientStyle.gradientStops),
					getGradientAlphas(gradientStyle.gradientStops), 
					getGradientRatios(gradientStyle.gradientStops),
					getGradientBox(gradientStyle)
				);
			
			//for a bitmap line style, use an ImageHTMLElement as the source
			//for the BitmapData. The line style must also be set before
			//setting the bitmap data on the line
			case bitmap(imageHTMLElement, lineStyleData, repeat):
				//set first the line style so that the line is visible	
				_typedNativeElement.graphics.lineStyle(
					lineStyleData.thickness,
					0,
					1,
					true,
					LineScaleMode.NONE,
					toNativeCapStyle(lineStyleData.capStyle),
					toNativeJointStyle(lineStyleData.jointStyle),
					lineStyleData.miterLimit);
				
				//then set the bitmap data on it
				_typedNativeElement.graphics.lineBitmapStyle(getBitmapData(imageHTMLElement.nativeElement), new flash.geom.Matrix(), repeat);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden High level pixel manipulation method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw a bitmap extracted from a NativeElement into the bitmap display object.
	 */
	override public function drawImage(source:NativeElement, matrix:Matrix = null, sourceRect:RectangleData = null):Void
	{	
		//init destination point and sourceRect if null
		
		if (matrix == null)
		{
			matrix = new Matrix();
		}
		
		if (sourceRect == null)
		{
			var width:Float = source.width;
			var height:Float = source.height;
			sourceRect = {
				x:0.0,
				y:0.0,
				width:width,
				height:height
			};
		}
		
		//get the ImageHTMLElement bitmap data and current bitmap data
		var sourceBitmapData:BitmapData = getBitmapData(source);
		var currentBitmapData:BitmapData = _bitmapDrawing.bitmapData;
		
		//convert the abstract rectangle and point into flash natives one
		var nativeSourceRect:flash.geom.Rectangle = new flash.geom.Rectangle(sourceRect.x, sourceRect.y, sourceRect.width, sourceRect.height);
		
		var matrixData:MatrixData = matrix.data;
		var nativeMatrix:flash.geom.Matrix = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
		
		//draw the ImageHTMLElement bitmap data onto the current bitmap data
		currentBitmapData.draw(sourceBitmapData, nativeMatrix, null, null, nativeSourceRect);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden low level drawing methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Use the native Flash lineTo method
	 */
	override public function lineTo(x:Float, y:Float):Void
	{
		_typedNativeElement.graphics.lineTo(x, y);
	}
	
	/**
	 * Use the native Flash moveTo method
	 */
	override public function moveTo(x:Float, y:Float):Void
	{
		_typedNativeElement.graphics.moveTo(x, y);
	}
	
	/**
	 * Use the native Flash curveTo method
	 */
	override public function curveTo(controlX:Float, controlY:Float, x:Float, y:Float):Void
	{
		_typedNativeElement.graphics.curveTo(controlX, controlY, x, y);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden utils conversion methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * In Flash AVM2, alpha values range from 0 to 1
	 */
	override private function toNativeAlpha(genericAlpha:Float):Dynamic
	{
		return genericAlpha;
	}
	
	/**
	 * In Flash AVM2, ratio values range from 0 to 255
	 */
	override private function toNativeRatio(genericRatio:Int):Dynamic
	{
		if (genericRatio == 0)
		{
			return 0;
		}
		return Math.round((255 / genericRatio) * 100);
	}
	
	/**
	 * In Flash AVM2, the caps styles values are wrapped as a fake enum
	 * @return a fake enum value (converted to string at compile time)
	 */
	override private function toNativeCapStyle(genericCapStyle:CapsStyleValue):Dynamic
	{
		var capStyle:CapsStyle = CapsStyle.ROUND;
				
		switch(genericCapStyle)
		{
			case round:
				capStyle = CapsStyle.ROUND;
			
			case square:
				capStyle = CapsStyle.SQUARE;
			
			case none:
				capStyle = CapsStyle.NONE;
		}
		
		return capStyle;
	}
	
	/**
	 * In Flash AVM2, the joint styles values are wrapped as a fake enum
	 * @return a fake enum value (converted to string at compile time)
	 */
	override private function toNativeJointStyle(genericJointStyle:JointStyleValue):Dynamic
	{
		var jointStyle:JointStyle = JointStyle.BEVEL;
				
		switch(genericJointStyle)
		{
			case miter:
				jointStyle = JointStyle.MITER;
			
			case round:
				jointStyle = JointStyle.ROUND;
				
			case bevel:
				jointStyle = JointStyle.BEVEL;
		}
		
		return jointStyle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Converts the generic type of Gradient (linear, radial) to a Flash
	 * specific one
	 * @return a strongly typed Flash gradient value
	 */
	private function getGradientType(genericGradientType:GradientTypeValue):GradientType
	{
		var gradientType:GradientType = LINEAR;
				
			switch(genericGradientType)
			{
				case linear:
					gradientType =  GradientType.LINEAR;
					
				case radial:
					gradientType = GradientType.RADIAL;
			}
				
		return gradientType;	
	}
	
	/**
	 * Get the bitmap data from a NativeElement
	 * @return a bitmap data using the NativeElement sprite as it's source
	 */
	private function getBitmapData(nativeElement:NativeElement):BitmapData
	{
		var nativeElementWidth:Int = Math.round(nativeElement.width);
		var nativeElementHeight:Int = Math.round(nativeElement.height);
		
		var bitmapData:BitmapData = new BitmapData(nativeElementWidth, nativeElementHeight, true, 0x00000000);
		bitmapData.draw(nativeElement);
		
		return bitmapData;
	}
	
	/**
	 * Get the colors from the gradient stops data
	 * @param	gradientStops contains all the gradient data
	 * @return an array of color
	 */
	private function getGradientColors(gradientStops:Array<GradientStopData>):Array<Int>
	{
		var ret:Array<Int> = new Array<Int>();
		
		for (i in 0...gradientStops.length)
		{
			ret[i] = gradientStops[i].colorStop.color;
		}
		
		return ret;
	}
	
	/**
	 * Get all the alphas of the color of gradient stops
	 * @param	gradientStops contains all the gradient data
	 * @return an array of alpha (from 0 to 1)
	 */
	private function getGradientAlphas(gradientStops:Array<GradientStopData>):Array<Float>
	{
		var ret:Array<Float> = new Array<Float>();
		
		for (i in 0...gradientStops.length)
		{
			ret[i] = toNativeAlpha(gradientStops[i].colorStop.alpha);
		}
		
		return ret;
	}
	
	/**
	 * Get all the ratio of the colors of the gradient stop
	 * @param	gradientStops contains all the gradient data
	 * @return an array of ratio (from 0 to 255)
	 */
	private function getGradientRatios(gradientStops:Array<GradientStopData>):Array<Int>
	{
		var ret:Array<Int> = new Array<Int>();
		
		for (i in 0...gradientStops.length)
		{
			ret[i] = toNativeRatio(gradientStops[i].ratio);
		}
		return ret;
	}
	

	/**
	 * create and return a gradient box corresponding to the size of the
	 * whole HTMLElement
	 */
	private function getGradientBox(gradientStyle:GradientStyleData):flash.geom.Matrix
	{
		var gradientBox:flash.geom.Matrix = new flash.geom.Matrix();
		gradientBox.createGradientBox(this.width, this.height, (gradientStyle.rotation) / 180 * Math.PI);
		return gradientBox;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	// update the bitmap surface when the width or height changes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setWidth(value:Int):Int
	{
		super.setWidth(value);
		_bitmapDrawing = new Bitmap(new BitmapData(value, height, true, 0x00000000));
		this._nativeElement.addChild(_bitmapDrawing);
		return _width = value;
	}
	

	override private function setHeight(value:Int):Int
	{
		super.setHeight(value);
		_bitmapDrawing = new Bitmap(new BitmapData(width, value, true, 0x00000000));
		this._nativeElement.addChild(_bitmapDrawing);
		return _height = value;
	}
	
}