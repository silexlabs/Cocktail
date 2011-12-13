/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.CapsStyle;
import flash.display.DisplayObjectContainer;
import flash.display.GradientType;
import flash.display.JointStyle;
import flash.display.LineScaleMode;
import flash.display.Sprite;
import flash.geom.Matrix;
import flash.Lib;
import haxe.Log;
import cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
import cocktail.geom.GeomData;
import cocktail.style.StyleData;
import cocktail.domElement.DOMElementData;

/**
 * This is the Flash AVM2 implementation of the graphic DOMElement.
 * It draws shape programatically onto a native Sprite object.
 * The sprite DOMElement is then cached as a bitmap. It allows to work
 * with both the flash vector drawing API and bitmaps.
 * 
 * @author Yannick DOMINGUEZ
 */
class GraphicDOMElement extends AbstractGraphicDOMElement
{
	/**
	 * A transparent clip used to give a width and height
	 * to the DOMElement without scaling its content. 
	 */
	private var _backGroundSprite:Sprite;
	
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
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
		
		_typedNativeElement = cast(this._nativeElement);
		
		//init the background sprite and attach it to the display list
		_backGroundSprite = new Sprite();
		this._nativeElement.addChild(_backGroundSprite);

		setUpBackgroundSprite(_backGroundSprite, this.intrinsicWidth, this.intrinsicHeight);
		
		//init the bitmap display object and attach it to the display list
		_bitmapDrawing = new Bitmap(new BitmapData(this.intrinsicWidth, this.intrinsicHeight, true, 0x00FFFFFF));
		this._nativeElement.addChild(_bitmapDrawing);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden getter/setter
	// The width and height setter/getter are overriden. In Flash, the with and height
	// depends on the transparent background Sprite, it allows drawing graphics
	// smaller than the whole graphic DOMElement. The background Sprite also
	// acts as a mask, to clip the graphics
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setWidth(value:Int):Int
	{
		super.setWidth(value);
		
		//update the background delimiting this DOMElement
		setUpBackgroundSprite(this._backGroundSprite, value, this.height);
	
		//update the bitmap drawing
		updateBitmapDrawingSize();
		
		return value;
	}
	
	override private function setHeight(value:Int):Int 
	{
		super.setHeight(value);
		
		//update the background delimiting this dom element
		setUpBackgroundSprite(this._backGroundSprite, this.width, value);
		
		//update the bitmap drawing
		updateBitmapDrawingSize();
		
		return value;
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
		var currentGraphicBitmapData:BitmapData = new BitmapData(Math.round(_typedNativeElement.width), Math.round(_typedNativeElement.height), true, 0x00FFFFFF);
		
		//draw the current vector into a bitmap
		currentGraphicBitmapData.draw(_typedNativeElement);
		
		//retrive the current bitmapData (the sum of all the previous
		//vector drawings)
		var bitmapData:BitmapData = _bitmapDrawing.bitmapData;
		
		//copy each pixel from the new vector drawing into the current bitmapData,
		//preserving the alpha values
		bitmapData.copyPixels(currentGraphicBitmapData, new flash.geom.Rectangle(0, 0, _typedNativeElement.width, _typedNativeElement.height), new flash.geom.Point(0, 0));
		
		//set the bitmapData on the bitmap display object
		_bitmapDrawing.bitmapData = bitmapData;
	}

	/**
	 * Update the size of the bitmap display object when the size of
	 * the DOMElement changes
	 */
	private function updateBitmapDrawingSize():Void
	{
		//retrieve the current bitmapData
		var currentBitmapData:BitmapData = _bitmapDrawing.bitmapData;
		
		//create a new transparent bitmapData with the new size of the DOMElement
		//or the intrinsic size of the DOMElement if it hasn't a specific size yet
		var width:Int;
		var height:Int;
		if (this.width != 0)
		{
			width = this.width;
		}
		else
		{
			width = this.intrinsicWidth;
		}
		if (this.height != 0)
		{
			height = this.height;
		}
		else
		{
			height = this.intrinsicHeight;
		}
		var newBitmapData:BitmapData = new BitmapData(width, height, true, 0x00FFFFFF);
		
		//retrieve the width of pixels that must be copied
		//from the current bitmap data
		var drawingWidth:Int = 0;
		
		//if the current bitmap data width is superior to the new
		//width of the DOMElement, then only the new width of pixels
		//must be copied, the rest will be cropped
		if (currentBitmapData.width > width)
		{
			drawingWidth = width;
		}
		//else if the new width is superior to the current bitmap width
		//all current bitmap pixel width must be copied
		else
		{
			drawingWidth = currentBitmapData.width;
		}
		
		//same for height
		var drawingHeight:Int = 0;
		
		if (currentBitmapData.height > height)
		{
			drawingHeight = height;
		}
		else
		{
			drawingHeight = currentBitmapData.height;
		}
		
		//copy each of the current bitmap data pixels with alpha in the new bitmap data
		newBitmapData.copyPixels(currentBitmapData, new flash.geom.Rectangle(0, 0, currentBitmapData.width, currentBitmapData.height), new flash.geom.Point(0, 0));
	
		//free the memory used by the current bitmap data
		currentBitmapData.dispose();
		
		//replace the current bitmap data by the new one
		this._nativeElement.removeChild(_bitmapDrawing);
		_bitmapDrawing = new Bitmap(newBitmapData);
		this._nativeElement.addChild(_bitmapDrawing);
		
	}
	
	/**
	 * Clears the native sprite fill and stroke and reset the
	 * fill style and line style. Clears also the bitmap display object
	 */
	override public function clear():Void
	{
		_typedNativeElement.graphics.clear();
		
		//draws a transparent rectangle over all the bitmap, erasing it's content
		_bitmapDrawing.bitmapData.fillRect(new flash.geom.Rectangle(0, 0, this.intrinsicWidth, this.intrinsicHeight), 0x00FFFFFF);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Private fill control methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Do set the fill style on the Sprite
	 * @param	fillStyle
	 */
	override private function setFillStyle(fillStyle:FillStyleValue):Void
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
			//an ImageDOMElement as source for the bitmap data
			case bitmap(imageDOMElement, repeat):
				_typedNativeElement.graphics.beginBitmapFill(getBitmapData(imageDOMElement), new Matrix(), repeat);
		}	
	}
	
	/**
	 * Do set the lineStyle on the Sprite
	 * @param	lineStyle
	 */
	override private function setLineStyle(lineStyle:LineStyleValue):Void
	{
		switch(lineStyle)
		{
			//if there must be no line (probably just a fill instead), do nothing
			case none:
				
			
			//if there must be a one-color line, use the native lineStyle method
			case monochrome(colorStop, lineStyleData):
				//set the line style
				_typedNativeElement.graphics.lineStyle(
					lineStyleData.thickness,
					colorStop.color,
					toNativeAlpha(colorStop.alpha),
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
			
			//for a bitmap line style, use an ImageDOMElement as the source
			//for the BitmapData. The line style must also be set before
			//setting the bitmap data on the line
			case bitmap(imageDOMElement, lineStyleData, repeat):
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
				_typedNativeElement.graphics.lineBitmapStyle(getBitmapData(imageDOMElement), new Matrix(), repeat);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden High level pixel manipulation method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw a bitmap extracted from an ImageDOMElement into the bitmap display object.
	 */
	override public function drawImage(source:ImageDOMElement, destinationPoint:PointData = null, sourceRect:RectangleData = null):Void
	{	
		//init destination point and sourceRect if null
		
		if (destinationPoint == null)
		{
			destinationPoint = {
				x:0.0,
				y:0.0
			};
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
		
		
		//get the ImageDOMElement bitmap data and current bitmap data
		var sourceBitmapData:BitmapData = getBitmapData(source);
		var currentBitmapData:BitmapData = _bitmapDrawing.bitmapData;
		
		//convert the abstract rectangle and point into flash natives one
		var nativeSourceRect:flash.geom.Rectangle = new flash.geom.Rectangle(sourceRect.x, sourceRect.y, sourceRect.width, sourceRect.height);
		var nativeDestinationPoint:flash.geom.Point = new flash.geom.Point(destinationPoint.x, destinationPoint.y);
		
		//draw the ImageDOMElement bitmap data onto the current bitmap data
		currentBitmapData.copyPixels(sourceBitmapData, nativeSourceRect, nativeDestinationPoint, null, null, true);

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
	override private function toNativeAlpha(genericAlpha:Int):Dynamic
	{
		return genericAlpha * 0.01;
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
	 * Get the bitmap data from an ImageDOMElement
	 * @param	imageDOMElement contains a Sprite containing a bitmap
	 * @return a bitmap data using the DOMElement sprite as it's source
	 */
	private function getBitmapData(imageDOMElement:DOMElement):BitmapData
	{
		var bitmapData:BitmapData = new BitmapData(imageDOMElement.width, imageDOMElement.height, true, 0x00FFFFFF);
		bitmapData.draw(imageDOMElement.nativeElement);
		
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
	 * fill the background flash sprite with a transparent fill, this sprite becomes
	 * the actual with and height of this DOMElement. Set it as the mask of the native
	 * DOMElement used to draw the graphics, to clip the graphics
	 */
	private function setUpBackgroundSprite(sprite:Sprite, width:Int, height:Int):Void
	{
		sprite.graphics.clear();
		sprite.graphics.beginFill(0, 0);
		sprite.graphics.drawRect(0, 0, width, height);
		sprite.graphics.endFill();
		
		this._nativeElement.mask = _backGroundSprite;
	}
	
	/**
	 * create and return a gradient box corresponding to the size of the
	 * whole DOMElement
	 */
	private function getGradientBox(gradientStyle:GradientStyleData):Matrix
	{
		var gradientBox:Matrix = new Matrix();
		gradientBox.createGradientBox(this.width, this.height, gradientStyle.rotation / 180 * Math.PI);
		return gradientBox;
	}
}