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
import haxe.Log;
import cocktail.domElement.base.DOMElementBase;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.nativeReference.NativeReferenceData;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;

class MatrixTests 
{
	private static var rootDOMElement:DOMElement;
	
	public static function main()
	{

		rootDOMElement = new DOMElement(NativeReferenceManager.getRoot());
		
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
		
		var domElement:GraphicDOMElement = new GraphicDOMElement(NativeReferenceManager.createNativeReference(graphic));

		
		//init the test dom element
		
		domElement.setWidth(200);
		domElement.setHeight(100);
		domElement.setX(0);
		domElement.setY(0);
		
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
		
		Assert.equals(domElement.getMatrix().getRotation(), 45);
		
		domElement.resetTransformations();
		
		domElement.rotate(90, constant(center, middle));
		
		Assert.equals(domElement.getMatrix().getRotation(), 90);
		
		domElement.resetTransformations();
		
		domElement.rotate(180, constant(center, middle));
		
		Assert.equals(domElement.getMatrix().getRotation(), 180);
		
		domElement.resetTransformations();
		
		domElement.rotate(270, constant(center, middle));
		
		Assert.equals(domElement.getMatrix().getRotation(), 270);
		
		
		//test x scale
		
		domElement.resetTransformations();
		
		domElement.scale(2, 1, constant(center, middle));
		
		Assert.equals(domElement.getMatrix().getScaleX(), 2);
		
		domElement.resetTransformations();
		
		domElement.scale(-2, 1, constant(center, middle));
		
		Assert.equals(domElement.getMatrix().getScaleX(), -2);
		
		//test y scale
		
		domElement.resetTransformations();
		
		domElement.scale(1, 2, constant(center, middle));
		
		Assert.equals(domElement.getMatrix().getScaleY(), 2);
		
		domElement.resetTransformations();
		
		domElement.scale(1, -2, constant(center, middle));
		
		Assert.equals(domElement.getMatrix().getScaleY(), -2);
		
		//test translation
		
		domElement.resetTransformations();
		
		domElement.translate(20, 30);
		
		Assert.equals(domElement.getMatrix().getTranslationX(), 20);
		Assert.equals(domElement.getMatrix().getTranslationY(), 30);
		
		
		//test skew
		
		domElement.resetTransformations();
		
		domElement.skew(0.5, 0.2, constant(center, middle));
		
		Assert.equals(Std.string(domElement.getMatrix().getSkewX()).substr(0,3), "0.5");
		Assert.equals(Std.string(domElement.getMatrix().getSkewY()).substr(0,3), "0.2");
		
		//test absolut rotation setting
		
		domElement.resetTransformations();
		
		domElement.setRotation(45, constant(center, middle));
		domElement.setRotation(45, constant(center, middle));
		domElement.setRotation(20, constant(center, middle));
		
		Assert.equals(domElement.getRotation(), 20);
		
		domElement.resetTransformations();
		
		//test absolut scale setting
		
		domElement.setScaleX(2, constant(center, middle));
		domElement.setScaleX(2, constant(center, middle));
		domElement.setScaleX(2, constant(center, middle));
		
		domElement.setScaleY(3, constant(center, middle));
		domElement.setScaleY(3, constant(center, middle));
		domElement.setScaleY(3, constant(center, middle));
		
		
		Assert.equals(domElement.getScaleX(), 2);
		Assert.equals(domElement.getScaleY(), 3);
		
		domElement.resetTransformations();
		
		//test absolut translation setting
		
		domElement.setTranslationX(500);
		domElement.setTranslationX(500);
		domElement.setTranslationX(500);
		
		domElement.setTranslationY(20);
		domElement.setTranslationY(20);
		domElement.setTranslationY(20);
		
		Assert.equals(domElement.getTranslationX(), 500);
		Assert.equals(domElement.getTranslationY(), 20);
		
		
	}
	
	
}