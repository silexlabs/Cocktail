/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package geom;

/**
 * Units tests for DOMObjects transformation matrix
 * @author Yannick DOMINGUEZ
 */
import haxe.Log;
import cocktail.domObject.base.DOMObjectBase;
import cocktail.domObject.DOMObject;
import cocktail.domObject.GraphicDOMObject;
import cocktail.domObject.DOMObjectData;
import cocktail.geom.GeomData;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.nativeReference.NativeReferenceData;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;

class MatrixTests 
{
	private static var rootDOMObject:DOMObject;
	
	public static function main()
	{

		rootDOMObject = new DOMObject(NativeReferenceManager.getRoot());
		
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
		
		var domObject:GraphicDOMObject = new GraphicDOMObject(NativeReferenceManager.createNativeReference(graphic));

		
		//init the test dom object
		
		domObject.setWidth(200);
		domObject.setHeight(100);
		domObject.setX(0);
		domObject.setY(0);
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xFF0000"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0x00FF00"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:0		}
		
		domObject.beginFill(gradient( gradientStyle), LineStyleValue.none);
		domObject.drawRect(0, 0, 200, 100, { tlCornerRadius:0, trCornerRadius:0, blCornerRadius:0, brCornerRadius:0 } );
		domObject.endFill();
		
		rootDOMObject.addChild(domObject);
		
		//test rotations at angles of each of a circle quarter
		
		domObject.rotate(45, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getRotation(), 45);
		
		domObject.resetTransformations();
		
		domObject.rotate(90, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getRotation(), 90);
		
		domObject.resetTransformations();
		
		domObject.rotate(180, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getRotation(), 180);
		
		domObject.resetTransformations();
		
		domObject.rotate(270, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getRotation(), 270);
		
		
		//test x scale
		
		domObject.resetTransformations();
		
		domObject.scale(2, 1, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getScaleX(), 2);
		
		domObject.resetTransformations();
		
		domObject.scale(-2, 1, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getScaleX(), -2);
		
		//test y scale
		
		domObject.resetTransformations();
		
		domObject.scale(1, 2, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getScaleY(), 2);
		
		domObject.resetTransformations();
		
		domObject.scale(1, -2, constant(center, middle));
		
		Assert.equals(domObject.getMatrix().getScaleY(), -2);
		
		//test translation
		
		domObject.resetTransformations();
		
		domObject.translate(20, 30);
		
		Assert.equals(domObject.getMatrix().getTranslationX(), 20);
		Assert.equals(domObject.getMatrix().getTranslationY(), 30);
		
		
		//test skew
		
		domObject.resetTransformations();
		
		domObject.skew(0.5, 0.2, constant(center, middle));
		
		Assert.equals(Std.string(domObject.getMatrix().getSkewX()).substr(0,3), "0.5");
		Assert.equals(Std.string(domObject.getMatrix().getSkewY()).substr(0,3), "0.2");
		
		//test absolut rotation setting
		
		domObject.resetTransformations();
		
		domObject.setRotation(45, constant(center, middle));
		domObject.setRotation(45, constant(center, middle));
		domObject.setRotation(20, constant(center, middle));
		
		Assert.equals(domObject.getRotation(), 20);
		
		domObject.resetTransformations();
		
		//test absolut scale setting
		
		domObject.setScaleX(2, constant(center, middle));
		domObject.setScaleX(2, constant(center, middle));
		domObject.setScaleX(2, constant(center, middle));
		
		domObject.setScaleY(3, constant(center, middle));
		domObject.setScaleY(3, constant(center, middle));
		domObject.setScaleY(3, constant(center, middle));
		
		
		Assert.equals(domObject.getScaleX(), 2);
		Assert.equals(domObject.getScaleY(), 3);
		
		domObject.resetTransformations();
		
		//test absolut translation setting
		
		domObject.setTranslationX(500);
		domObject.setTranslationX(500);
		domObject.setTranslationX(500);
		
		domObject.setTranslationY(20);
		domObject.setTranslationY(20);
		domObject.setTranslationY(20);
		
		Assert.equals(domObject.getTranslationX(), 500);
		Assert.equals(domObject.getTranslationY(), 20);
		
		
	}
	
	
}