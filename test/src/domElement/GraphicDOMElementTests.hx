/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package domElement;

/**
 * Units tests for Graphic DOMElements
 * @author Yannick DOMINGUEZ
 */

import haxe.Log;
import cocktail.domElement.base.DOMElementBase;
import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.resource.ResourceLoaderManager;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;

import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;

class GraphicDOMElementTests 
{
	private static var rootDOMElement:DOMElement;
	
	public static function main()
	{
		
		rootDOMElement = new DOMElement(NativeElementManager.getRoot());
		
		var runner = new Runner();
		runner.addCase(new GraphicDOMElementTests());
		Report.create(runner, NeverShowSuccessResults, NeverShowHeader);
		//Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
	}
	
	/**
	 * drawn a one color rectangle
	 */
	public function testDrawRectangle()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(200);
		graphicDOMElement.setHeight(200);
		graphicDOMElement.setX(0);
		graphicDOMElement.setY(0);
		
		var colorStop:ColorStopData = { color:Std.parseInt("0xFF0000") , alpha:100 };
		var fillStyle:FillStyleValue = monochrome(colorStop);
		
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:10,
			trCornerRadius:0,
			blCornerRadius:60,
			brCornerRadius:0
		}
		
		
		graphicDOMElement.drawRect(0, 0, 100, 100, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		Assert.equals(1, 1);
	}
	
	public function testDrawStar()
	{
		var starDOMElement:GraphicDOMElement = new GraphicDOMElement();
		starDOMElement.width = 300;
		starDOMElement.height = 300;
		
		starDOMElement.x = 400;
		starDOMElement.y = 200;
		
		starDOMElement.beginFill(monochrome( { color:0xFF0000, alpha: 70 } ));
		
		starDOMElement.drawStar(0, 0, 50, 10, 7);
		starDOMElement.endFill();
		
		rootDOMElement.addChild(starDOMElement);
	}
	
	public function testDrawPooly()
	{
		var polyDOMElement:GraphicDOMElement = new GraphicDOMElement();
		polyDOMElement.width = 300;
		polyDOMElement.height = 300;
		
		polyDOMElement.x = 400;
		polyDOMElement.y = 300;
		
		polyDOMElement.beginFill(monochrome( { color:0xFF0000, alpha: 70 } ));
		
		polyDOMElement.drawPolygon(20, 40, 50, 9);
		polyDOMElement.endFill();
		
		rootDOMElement.addChild(polyDOMElement);
	}
	
	/**
	 * draw a linear gradient rectangle
	 */
	public function testDrawLinearGradientRectangle()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(150);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(200);
		graphicDOMElement.setY(0);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		var colorStop:ColorStopData = { color:Std.parseInt("0xFF0000") , alpha:100 };
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:60		}
	
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		var fillStyle:FillStyleValue = gradient(gradientStyle);
		
		
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawRect(20, 40, 50, 30, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		Assert.equals(1, 1);
	}
	
	/**
	 * draw a bitmap rectangle
	 */
	public function testDrawBitmapRectangle()
	{
		ResourceLoaderManager.loadImage("../resource/testPicture.jpg", onImageLoaded, function(msg:String) { } ); 
		
		Assert.equals(1, 1);
	}
	
	private function onImageLoaded(imageDOMElement:ImageDOMElement)
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(100);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(400);
		graphicDOMElement.setY(0);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		var fillStyle:FillStyleValue = bitmap(imageDOMElement, true);
		
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawRect(20, 5, 65, 45, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		
	}
	
	/**
	 * draw a rectangular stroke
	 */
	public function testDrawRectangleStroke()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(100);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(600);
		graphicDOMElement.setY(0);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		

		var colorStop:ColorStopData = { color:Std.parseInt("0xFF0000"), alpha:100 };
		
		var lineStyleData:LineStyleData = {
			thickness:20,
			capStyle:round,
			jointStyle:JointStyleValue.round,
			miterLimit:10
		}
		var lineStyle:LineStyleValue = LineStyleValue.monochrome(colorStop, lineStyleData);
		
		var fillStyle:FillStyleValue = none;
		
		
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawRect(0, 0, 100, 100, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		Assert.equals(1, 1);
	}
	
	/**
	 * draw a rectangular gradient stroke
	 */
	public function testDrawRectangleGradientStroke()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(100);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(20);
		graphicDOMElement.setY(60);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:0
		}
		
		var lineStyleData:LineStyleData = {
			thickness:20,
			capStyle:round,
			jointStyle:JointStyleValue.round,
			miterLimit:10
		}
		var lineStyle:LineStyleValue = LineStyleValue.gradient(gradientStyle, lineStyleData);
		
		var fillStyle:FillStyleValue = monochrome({color:Std.parseInt("0xFFF000"), alpha:50});
		
		
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawRect(0, 0, 100, 100, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		graphicDOMElement.zOrder = 5;
		Assert.equals(1, 1);
	}
	
	/**
	 * draw a bitmap rectangular stroke
	 */
	public function testDrawBitmapRectangleStroke()
	{
		ResourceLoaderManager.loadImage("../resource/testPicture.jpg", onStrokeImageLoaded, function(msg:String) { } ); 
		Assert.equals(1, 1);
	}
	
	private function onStrokeImageLoaded(imageDOMElement:ImageDOMElement)
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(100);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(400);
		graphicDOMElement.setY(100);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		var fillStyle:FillStyleValue = none;
		
		var lineStyleData:LineStyleData = {
			thickness:20,
			capStyle:round,
			jointStyle:JointStyleValue.round,
			miterLimit:10
		}
		
		var lineStyle:LineStyleValue = LineStyleValue.bitmap(imageDOMElement, lineStyleData, true) ;
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawRect(0, 0, 100, 100, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
	}
	
	/**
	 * draw a complex shape
	 */ 
	public function testDrawShape()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(100);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(300);
		graphicDOMElement.setY(100);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:0
		}
		
		var lineStyleData:LineStyleData = {
			thickness:2,
			capStyle:round,
			jointStyle:JointStyleValue.round,
			miterLimit:10
		}
		var lineStyle:LineStyleValue = LineStyleValue.gradient(gradientStyle, lineStyleData);
		
		var fillStyle:FillStyleValue = FillStyleValue.monochrome({ color:Std.parseInt("0xDDDDDD"), alpha:100 }) ;
		
		
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.moveTo(10, 10);
		graphicDOMElement.lineTo(20, 10);
		graphicDOMElement.curveTo(40, 20, 60, 10);
		graphicDOMElement.lineTo(0, 0);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		Assert.equals(1, 1);
	}
	
	/**
	 * draw an ellipse
	 */
	public function testDrawEllipse()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(100);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(50);
		graphicDOMElement.setY(100);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:0
		}
		
		var lineStyleData:LineStyleData = {
			thickness:2,
			capStyle:round,
			jointStyle:JointStyleValue.round,
			miterLimit:10
		}
		var lineStyle:LineStyleValue = LineStyleValue.gradient(gradientStyle, lineStyleData);
		
		var fillStyle:FillStyleValue = FillStyleValue.monochrome({ color:Std.parseInt("0xDDDDDD"), alpha:100 }) ;
		
		
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawEllipse(0, 0, 100, 100);
		graphicDOMElement.endFill();
		
		
		
		rootDOMElement.addChild(graphicDOMElement);
		
		
		
		Assert.equals(1, 1);
	}
	
	/**
	 * draw a bitmap rectangular stroke
	 */
	public function testDrawImage()
	{
		ResourceLoaderManager.loadImage("../resource/testPicture.jpg", onDrawImageLoaded, function(msg:String) { } ); 
		Assert.equals(1, 1);
	}
	
	public function onDrawImageLoaded(imageDOMElement:ImageDOMElement):Void
	{
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement();
		graphicDOMElement.x = 500;
		graphicDOMElement.width = 100;
		graphicDOMElement.height = 100;
		graphicDOMElement.y = 200;
		graphicDOMElement.drawImage(imageDOMElement, { x:0.0, y:0.0 }, { x:0.0, y:0.0, width:65.0, height:65.0 } );
		graphicDOMElement.drawImage(imageDOMElement, { x:10.0, y:15.0 }, { x:5.0, y:5.0, width:50.0, height:50.0 } );
		graphicDOMElement.drawImage(imageDOMElement, {x:70.0, y:15.0}, {x:10.0,y:5.0,width:50.0,height:50.0});
		rootDOMElement.addChild(graphicDOMElement);
		
	}
	
	/**
	 * draw a linear gradient rectangle
	 */
	public function testDrawRadialGradientRectangle()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(150);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(200);
		graphicDOMElement.setY(200);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		var colorStop:ColorStopData = { color:Std.parseInt("0xFF0000") , alpha:100 };
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:radial,
			gradientStops:gradientStops,
			rotation:0
		}
	
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		var fillStyle:FillStyleValue = gradient(gradientStyle);
		
		
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawRect(0, 0, 150, 100, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		Assert.equals(1, 1);
	}
	
	/**
	 * draw a transparent lineat gradient
	 */
	public function testDrawTransparentLinearGradientRectangle()
	{
		#if flash9
		var nativeDOMElement = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement = js.Lib.document.createElement("canvas");
		#end
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(100);
		graphicDOMElement.setHeight(100);
		graphicDOMElement.setX(0);
		graphicDOMElement.setY(200);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:0,
			trCornerRadius:0,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		var colorStop:ColorStopData = { color:Std.parseInt("0xFF0000") , alpha:100 };
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:20 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:60 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:20		}
	
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		var fillStyle:FillStyleValue = gradient(gradientStyle);
		
		
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		graphicDOMElement.drawRect(0, 0, 150, 100, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		Assert.equals(1, 1);
	}
	
}