/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package geom;

/**
 * Units tests for DOMElements transformation matrix
 * @author Yannick DOMINGUEZ
 */
import cocktail.domElement.ContainerDOMElement;
import haxe.Log;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;

class MatrixTests 
{
	private static var rootDOMElement:ContainerDOMElement;
	
	public static function main()
	{

		rootDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		
		var runner = new Runner();
		runner.addCase(new MatrixTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
	}
	
	/**
	 * test all of the transformations
	 */
	public function testMatrixTransformations():Void
	{
		
		var domElement:GraphicDOMElement = new GraphicDOMElement(NativeElementManager.createNativeElement(graphic));

		
		//init the test dom element
		
		domElement.width = 200;
		domElement.height = 100;
		domElement.x = 0;
		domElement.y = 0;
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:0		}
		
		domElement.beginFill(gradient( gradientStyle), LineStyleValue.none);
		domElement.drawRect(0, 0, 200, 100, { tlCornerRadius:0, trCornerRadius:0, blCornerRadius:0, brCornerRadius:0 } );
		domElement.endFill();
		
		rootDOMElement.addChild(domElement);
		
		//test rotations at angles of each of a circle quarter
		
		domElement.rotate(45, constant(center, middle));
		
		Assert.equals(domElement.matrix.getRotation(), 45);
		
		domElement.resetTransformations();
		
		domElement.rotate(90, constant(center, middle));
		
		Assert.equals(domElement.matrix.getRotation(), 90);
		
		domElement.resetTransformations();
		
		domElement.rotate(180, constant(center, middle));
		
		Assert.equals(domElement.matrix.getRotation(), 180);
		
		domElement.resetTransformations();
		
		domElement.rotate(270, constant(center, middle));
		
		Assert.equals(domElement.matrix.getRotation(), 270);
		
		
		//test x scale
		
		domElement.resetTransformations();
		
		domElement.scale(2, 1, constant(center, middle));
		
		Assert.equals(domElement.matrix.getScaleX(), 2);
		
		domElement.resetTransformations();
		
		domElement.scale(-2, 1, constant(center, middle));
		
		Assert.equals(domElement.matrix.getScaleX(), -2);
		
		//test y scale
		
		domElement.resetTransformations();
		
		domElement.scale(1, 2, constant(center, middle));
		
		Assert.equals(domElement.matrix.getScaleY(), 2);
		
		domElement.resetTransformations();
		
		domElement.scale(1, -2, constant(center, middle));
		
		Assert.equals(domElement.matrix.getScaleY(), -2);
		
		//test translation
		
		domElement.resetTransformations();
		
		domElement.translate(20, 30);
		
		Assert.equals(domElement.matrix.getTranslationX(), 20);
		Assert.equals(domElement.matrix.getTranslationY(), 30);
		
		
		//test skew
		
		domElement.resetTransformations();
		
		domElement.skew(0.5, 0.2, constant(center, middle));
		
		Assert.equals(Std.string(domElement.matrix.getSkewX()).substr(0,3), "0.5");
		Assert.equals(Std.string(domElement.matrix.getSkewY()).substr(0,3), "0.2");
		
		//test absolut rotation setting
		
		domElement.resetTransformations();
		
		domElement.registrationPoint = constant(center, middle);
		
		domElement.rotation = 45;
		domElement.rotation = 45;
		domElement.rotation = 20;
		
		Assert.equals(domElement.rotation, 20);
		
		domElement.resetTransformations();
		
		//test absolut scale setting
		
		domElement.scaleX = 2;
		domElement.scaleX = 2;
		domElement.scaleX = 2;
		
		domElement.scaleY = 3;
		domElement.scaleY = 3;
		domElement.scaleY = 3;
		
		
		Assert.equals(domElement.scaleX, 2);
		Assert.equals(domElement.scaleY, 3);
		
		domElement.resetTransformations();
		
		//test absolut translation setting
		
		domElement.translationX = 500;
		domElement.translationX = 500;
		domElement.translationX = 500;
		
		domElement.translationY = 20;
		domElement.translationY = 20;
		domElement.translationY = 20;
		
		Assert.equals(domElement.translationX, 500);
		Assert.equals(domElement.translationY, 20);
		
		
	}
	
	
}