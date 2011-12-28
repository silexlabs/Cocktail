/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktail.domElement.EmbeddedDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import haxe.Log;

/**
 * The graphic DOMElement is used as a canvas to draw bitmap graphics programmatically. 
 * 
 * It is an abstraction of Flash and JavaScript respective drawing APIs. 
 * It was at first considered to only have a drawing API in a separate
 * package which could have been leveraged by each of the DOMElements,
 * but unlike Flash where every Sprite can be used to draw graphics,
 * in HTML graphics can only be drawn on a canvas element. As a result, 
 * drawing is only available on the graphics DOMElement as in HTML
 * we need to make sure that the native DOM element is a canvas.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractGraphicDOMElement extends EmbeddedDOMElement
{

	/**
	 * class constructor
	 * 
	 * Init the default intrinsic width, height and ratio.
	 * 
	 * By convention a GraphicDOMElement dimensions is
	 * 300 * 150 by default, according to the HTML5 Canvas
	 * element specifications
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		//get a graphic native element if none is provided
		if (nativeElement == null)
		{
			nativeElement = NativeElementManager.createNativeElement(graphic);
		}
		
		super(nativeElement);
		
		this._intrinsicHeight = 150;
		this._intrinsicWidth = 300;
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public drawing API
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Controls the fill
	// methods to init/end/clear the fill
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a  fill used when drawing a shape with subsequent calls to lineTo,
	 * moveTo or curveTo. The fill remain in effect until endFill  
	 * is called. 
	 * @param	fillStyle the data used to draw the fill. Default to none
	 * @param	lineStyle the data used to draw the fill stroke/line. Default to none
	 */
	public function beginFill(fillStyle:FillStyleValue = null, lineStyle:LineStyleValue = null):Void
	{
		//init fill and line style if null
		if (fillStyle == null)
		{
			fillStyle = FillStyleValue.none;
		}
		
		if (lineStyle == null)
		{
			lineStyle = LineStyleValue.none;
		}
		
		//set fill style
		setFillStyle(fillStyle);
		
		//set line style
		setLineStyle(lineStyle);
	}
	
	/**
	 * Ends a fill started with beginFill and draw the shape and line defined by the path formed by the 
	 * linetTo, moveTo and curveTo methods onto the graphical container.
	 */
	public function endFill():Void
	{
		//abstract
	}
	
	/**
	 * Clears the current shape and line of the graphic DOMElement.
	 */
	public function clear():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private fill control methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Do set the line style on the DOMElement
	 * @param	lineStyle
	 */
	private function setLineStyle(lineStyle:LineStyleValue):Void
	{
		//abstract
	}
	
	/**
	 * Do set the fill style on the DOMElement
	 * @param	fillStyle
	 */
	private function setFillStyle(fillStyle:FillStyleValue):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// High level drawing methods
	// Leverage the native low level drawing APIs
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * High level method to draw a rectangle which may have rounded corners. 
	 * Needs to be called after beginFill or beginGradientFill was called.
	 * @param	x the left point of the rectangle
	 * @param	y the top point of the rectangle
	 * @param	width the width of the rectangle
	 * @param	height the height of the rectangle
	 * @param	cornerRadiuses the corner radiuses values of the rectangle
	 */
	public function drawRect(x:Int, y:Int, width:Int, height:Int, cornerRadiuses:CornerRadiusData = null):Void
	{
		//init corner radius if null
		if (cornerRadiuses == null)
		{
			cornerRadiuses = {
				tlCornerRadius:0,
				trCornerRadius:0,
				blCornerRadius:0,
				brCornerRadius:0
			};
		}
		
		moveTo(cornerRadiuses.tlCornerRadius + x, y);
		lineTo(width - cornerRadiuses.trCornerRadius + x, y);
	
	
		curveTo(width + x, y, width + x , cornerRadiuses.trCornerRadius + y  );
		
		lineTo(width + x , cornerRadiuses.trCornerRadius + y );
		lineTo(width + x , height - cornerRadiuses.brCornerRadius + y);
		curveTo(width + x, height + y , width - cornerRadiuses.brCornerRadius + x , height + y );
		lineTo(width - cornerRadiuses.brCornerRadius + x , height + y );
		lineTo(cornerRadiuses.blCornerRadius + x , height + y );
		curveTo(x, height + y , x, height - cornerRadiuses.blCornerRadius  +y );
		lineTo(x, height - cornerRadiuses.blCornerRadius + y );
		lineTo(x, cornerRadiuses.tlCornerRadius + y );
		curveTo(x,y, cornerRadiuses.tlCornerRadius + x , y);
		lineTo(cornerRadiuses.tlCornerRadius + x , y);
	}
	
	/**
	 * High level method to draw an ellipse or circle. 
	 * Needs to be called after beginFill or beginGradientFill was called.
	 * width and height must be equal to draw a circle.
	 * @param	x the left point of the ellipse
	 * @param	y the top point of the ellipse
	 * @param	width the width of the ellipse
	 * @param	height the height of ellipse
	 */
	public function drawEllipse(x:Int, y:Int, width:Int, height:Int):Void
	{
		var xRadius:Float = width / 2;
		var yRadius:Float = height / 2;
		
		var xCenter:Float = (width / 2) + x  ;
		var yCenter:Float = (height /2) + y ;
		
		var angleDelta:Float = Math.PI / 4;
		var xCtrlDist:Float = xRadius/Math.cos(angleDelta/2);
		var yCtrlDist:Float = yRadius/Math.cos(angleDelta/2);
		
		
		moveTo(xCenter + xRadius, yCenter);
		var angle:Float = 0;
		
		var rx, ry, ax, ay;
		
		for (i in 0...8) {
		angle += angleDelta;
		rx = xCenter + Math.cos(angle-(angleDelta/2))*(xCtrlDist);
		ry = yCenter + Math.sin(angle-(angleDelta/2))*(yCtrlDist);
		ax = xCenter + Math.cos(angle)*xRadius;
		ay = yCenter + Math.sin(angle)*yRadius;
		curveTo(rx, ry, ax, ay);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// High level pixel manipulation method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw a bitmap extracted from an image dom element into the native graphic dom element. Alpha is preserved 
	 * for transparent bitmap
	 * @param	source the source image dom element containing the bitmap data
	 * @param	destinationPoint represent the top left point of the drawn image on the native graphic
	 * dom element. for instance a 0,0 point will draw the image in the top left corner of the graphic
	 * dom element. Takes 0,0 by default
	 * @param	sourceRect defines the zone from the source dom element that must be copied onto the 
	 * native graphic dom element. Takes the whole image by default
	 */
	public function drawImage(source:ImageDOMElement, destinationPoint:PointData = null, sourceRect:RectangleData = null):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Low level drawing methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draws a line from current drawing point to point x,y. 
	 * If a linestyle is defined for this Graphic DOMElement, draw a line with the current 
	 * linestyle from current point to point x,y. The current position becomes point x,y.
	 * @param	x target point x
	 * @param	y target point y
	 */
	public function lineTo(x:Float, y:Float):Void
	{
		//abstract
	}
	
	/**
	 * Moves the current drawing point to position x,y without drawing a line.
	 * @param	x target point x
	 * @param	y target point y
	 */
	public function moveTo(x:Float, y:Float):Void
	{
		//abstract
	}
	
	/**
	 * Draws a curve from current drawing point to point x,y using the 
	 * controlX,controlY as control point. The curve drawn is a quadratic
	 * bezier curve
	 * @param	controlX
	 * @param	controlY
	 * @param	x
	 * @param	y
	 */
	public function curveTo(controlX:Float, controlY:Float, x:Float, y:Float):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Utils conversion methods
	// used to convert generic graphic data to specific runtime
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Converts the generic alpha value to a runtime 
	 * specific one
	 * @return returns a dynamic as it may be a float
	 */
	private function toNativeAlpha(genericAlpa:Int):Dynamic
	{
		return null;
	}
	
	/**
	 * Converts the generic color value to a runtime specifc
	 * one
	 * @return return a dynamic as color can be represented as a String
	 */
	private function toNativeColor(genericColor:Int):Dynamic
	{
		return null;
	}
	
	/**
	 * Converts the generic gradient ratio value to a runtime 
	 * specific one
	 * @return a dynamic, as it may be a float
	 */
	private function toNativeRatio(genericRatio:Int):Dynamic
	{
		return null;
	}
	
	/**
	 * Converts the generic cap style value to a runtime
	 * specific one
	 * @return a dynamic, as it may be an enum or string
	 */
	private function toNativeCapStyle(genericCapStyle:CapsStyleValue):Dynamic
	{
		return null;
	}
	
	/**
	 * Converts a generic joint style value to a runtime 
	 * specific one
	 * @return a dynamic, as it may be an enum or string
	 */
	private function toNativeJointStyle(genericJointStyle:JointStyleValue):Dynamic
	{
		return null;
	}
	
	
}