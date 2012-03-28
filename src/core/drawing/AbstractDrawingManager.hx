/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.drawing;

import core.geom.Matrix;
import core.nativeElement.NativeElement;
import core.dom.DOMData;
import core.geom.GeomData;

/**
 * The drawing manager exposes a cross-platform
 * 2d drawing API, drawing the same graphics
 * in each runtime using runtime specific API
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractDrawingManager 
{
	/**
	 * A reference to the nativeElement used
	 * as drawing surface
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, never):NativeElement;
	
	/**
	 * The width of the drawing surface
	 */
	private var _width:Int;
	public var width(getWidth, setWidth):Int;
	
	/**
	 * The height of the drawing surface
	 */
	private var _height:Int;
	public var height(getHeight, setHeight):Int;
	
	/**
	 * class constructor.
	 */
	public function new(nativeElement:NativeElement, width:Int, height:Int) 
	{
		this._nativeElement = nativeElement;
		this._width = width;
		this._height = height;
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
	 * Clears the current shape and line of the graphic HTMLElement.
	 */
	public function clear():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public fill control methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Do set the line style on the HTMLElement
	 * @param	lineStyle
	 */
	public function setLineStyle(lineStyle:LineStyleValue):Void
	{
		//abstract
	}
	
	/**
	 * Do set the fill style on the HTMLElement
	 * @param	fillStyle
	 */
	public function setFillStyle(fillStyle:FillStyleValue):Void
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
	 * Draw a bitmap extracted from a NativeElement onto the bitmap surface. Alpha is preserved 
	 * for transparent bitmap
	 * @param	source the source native element containing the bitmap data
	 * @param	matrix a transformation matrix to apply yo the native element when drawing to 
	 * to the bitmap. Defaults to an identity matrix
	 * @param	sourceRect defines the zone from the source nativeElement that must be copied onto the 
	 * native graphic dom element. Takes the whole nativeElement by default
	 */
	public function drawImage(source:NativeElement, matrix:Matrix = null, sourceRect:RectangleData = null):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Low level drawing methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draws a line from current drawing point to point x,y. 
	 * If a linestyle is defined for this Graphic HTMLElement, draw a line with the current 
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
	private function toNativeAlpha(genericAlpa:Float):Dynamic
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getNativeElement():NativeElement
	{
		return _nativeElement;
	}
	
	private function setWidth(value:Int):Int
	{
		return _width = value;
	}
	
	private function getWidth():Int
	{
		return _width;
	}
	
	private function setHeight(value:Int):Int
	{
		return _height = value;
	}
	
	private function getHeight():Int
	{
		return _height;
	}
}