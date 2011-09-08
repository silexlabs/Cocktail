/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package domObject;

/**
 * Units tests for DOMObjects
 * @author Yannick DOMINGUEZ & Raphael HARMEL
 * 
 * 2011-08-10 PHP part is not complete yet.
 * 
 */

import haxe.Log;
import cocktail.domObject.ContainerDOMObject;
import cocktail.domObject.TextDOMObject;
import cocktail.geom.GeomData;
import cocktail.domObject.DOMObject;
import cocktail.domObject.base.DOMObjectBase;

import cocktail.domObject.GraphicDOMObject;
import cocktail.domObject.DOMObjectData;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;

import cocktail.resource.ResourceLoaderManager;

import cocktail.nativeReference.NativeReferenceManager;

#if flash9
import flash.display.Sprite;
import flash.Lib;

#elseif js
import js.Dom;
import js.Lib;
#end

class DOMObjectTests 
{
	
	private static var rootDOMObject:DOMObject;
	
	public static function main()
	{
		rootDOMObject = new DOMObject(NativeReferenceManager.getRoot());
		
		var runner = new Runner();
		runner.addCase(new DOMObjectTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
	}
	
	#if flash9
	
	/**
	 * test adding/removing DOMObject,
	 * and getting/setting there properties for Flash as3
	 */
	public function testAddRemoveChild()
	{
		var spriteParentDOMObject:Sprite = new Sprite();
		spriteParentDOMObject.graphics.beginFill(0x00FF00, 1);
		spriteParentDOMObject.graphics.drawRect(0, 0, 200, 200);
		spriteParentDOMObject.graphics.endFill();
		//create a new DOMObject
		var parentDOMObject:DOMObject = new DOMObject(spriteParentDOMObject);
		
		//add the native Sprite to the Flash Stage
		Lib.current.addChild(parentDOMObject.nativeReference);
		
		var spriteChildDOMObject:Sprite = new Sprite();
		spriteChildDOMObject.graphics.beginFill(0xFF0000, 1);
		spriteChildDOMObject.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMObject.graphics.endFill();
		//create a child DOMObject
		var childDOMObject:DOMObject = new DOMObject(spriteChildDOMObject);
		childDOMObject.setWidth(100);
		childDOMObject.setHeight(100);
		
		//add the child DOMObject to the parent DOMObject
		parentDOMObject.addChild(childDOMObject);
		
		//compare the names to verify that the children's parent is the parent DOMObject
		Assert.same(childDOMObject.getParent().nativeReference.name, parentDOMObject.nativeReference.name);
		
		//test getting each of the properties of the child DOMObject
		Assert.equals(childDOMObject.getWidth(), 100);
		Assert.equals(childDOMObject.getHeight(), 100);
		Assert.equals(childDOMObject.getX(), 0);
		Assert.equals(childDOMObject.getY(), 0);
		Assert.equals(childDOMObject.getZOrder(), 0);
		
		//set the child height of the DOMObject and test the returned height
		childDOMObject.setHeight(200);
		Assert.equals(childDOMObject.getHeight(), 200);
		
		//remove the child and parent DOMObjects from the display list
		parentDOMObject.removeChild(childDOMObject);
		Lib.current.removeChild(parentDOMObject.nativeReference);
		
		//check that the parent is now null
		Assert.same(childDOMObject.getParent(), null);
		
	}
	
	#elseif js
	
	/**
	 * test adding/removing DOMObject,
	 * and getting/setting there properties for JavaScript
	 */
	public function testAddRemoveChild()
	{
		//create a new div
		var divParentDOMObject:HtmlDom = js.Lib.document.createElement("div");
		divParentDOMObject.setAttribute("id","parentDiv");
		divParentDOMObject.innerHTML = "parent div";
		
		//create a new DOM object
		var parentDOMObject:DOMObject = new DOMObject(divParentDOMObject);
		
		//attach the div to the document body
		rootDOMObject.addChild(parentDOMObject);
		

		
		//create a new child div
		var divChildDOMObject:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMObject.setAttribute("id", "childDiv");
		divChildDOMObject.innerHTML = "child div";
		
		//create a new child DOMObject
		var childDOMObject:DOMObject = new DOMObject(divChildDOMObject);
		
		childDOMObject.setWidth(300);
		childDOMObject.setHeight(200);
		childDOMObject.setX(100);
		childDOMObject.setY(50);
		
		//attach the child DOMObject on the parent DOMObject
		parentDOMObject.addChild(childDOMObject);
		
		//test getting each of the properties of the child DOMObject
		Assert.equals(childDOMObject.getWidth(), 300);
		Assert.equals(childDOMObject.getHeight(), 200);
		Assert.equals(childDOMObject.getX(), 100);
		Assert.equals(childDOMObject.getY(), 50);
		Assert.equals(childDOMObject.getZOrder(), 0);
		
		
		//check the parent of the child DOMObject
		//Assert.same(childDOMObject.getParent(), parentDOMObject);
		
		//remove the child DOMObject from the div
		parentDOMObject.removeChild(childDOMObject);
		
		//check that the child object has no more parent
		Assert.same(childDOMObject.getParent(), null);
	}

	#elseif php
	
	/**
	 * test adding/removing DOMObject,
	 * and getting/setting there properties for JavaScript
	 */
	public function testAddRemoveChild()
	{
		//create a new div
		var divParentDOMObject:Xml = Xml.createElement("div");
		divParentDOMObject.set("id","parentDiv");
		divParentDOMObject.addChild(Xml.createPCData("parent div"));
		
		//create a new DOM object
		var parentDOMObject:DOMObject = new DOMObject(divParentDOMObject);
		
		//attach the div to the document body
		rootDOMObject.addChild(parentDOMObject);

		//create a new child div
		var divChildDOMObject:Xml = Xml.createElement("div");
		divChildDOMObject.set("id","childDiv");
		divChildDOMObject.addChild(Xml.createPCData("child div"));
		
		//create a new child DOMObject
		var childDOMObject:DOMObject = new DOMObject(divChildDOMObject);
		
		childDOMObject.setWidth(300);
		childDOMObject.setHeight(200);
		childDOMObject.setX(100);
		childDOMObject.setY(50);
		
		//attach the child DOMObject on the parent DOMObject
		parentDOMObject.addChild(childDOMObject);
		
		//test getting each of the properties of the child DOMObject
		Assert.equals(childDOMObject.getWidth(), 300);
		Assert.equals(childDOMObject.getHeight(), 200);
		Assert.equals(childDOMObject.getX(), 100);
		Assert.equals(childDOMObject.getY(), 50);
		Assert.equals(childDOMObject.getZOrder(), 0);
		
		//check the parent of the child DOMObject
		//Assert.same(childDOMObject.getParent(), parentDOMObject);
		
		//remove the child DOMObject from the div
		parentDOMObject.removeChild(childDOMObject);
		
		//check that the child object has no more parent
		Assert.same(childDOMObject.getParent(), null);
	}
	#end
	
	/**
	 * Test visibility and opacity methods
	 */
	public function testVisibilityOpacity()
	{
		#if flash9
		var nativeDOMObject:Dynamic = new flash.display.Sprite();
		#elseif js
		var nativeDOMObject:Dynamic = js.Lib.document.createElement("canvas");
		#end
		
		//test with a graphic dom object to easily have a background
		var graphicDOMObject:GraphicDOMObject = new GraphicDOMObject(nativeDOMObject);
		
		graphicDOMObject.setWidth(200);
		graphicDOMObject.setHeight(200);
		graphicDOMObject.setX(0);
		graphicDOMObject.setY(100);
		
		var colorStop:ColorStopData = { color:Std.parseInt("0xFF0000") , alpha:100 };
		var fillStyle:FillStyleValue = monochrome(colorStop);
		
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		graphicDOMObject.beginFill(fillStyle, lineStyle);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:10,
			trCornerRadius:0,
			blCornerRadius:20,
			brCornerRadius:0
		}
		
		
		graphicDOMObject.drawRect(0, 0, 100, 100, cornerRadiuses);
		graphicDOMObject.endFill();
		
		rootDOMObject.addChild(graphicDOMObject);
		
		graphicDOMObject.setIsVisible(false);
		Assert.equals(graphicDOMObject.getIsVisible(), false);
		
		graphicDOMObject.setIsVisible(true);
		Assert.equals(graphicDOMObject.getIsVisible(), true);
		
		graphicDOMObject.setAlpha(0.5);
		Assert.equals(graphicDOMObject.getAlpha(), 0.5);
	}
	
	/**
	 * Test the manipulation of DOMObjects z-indexes in Flash and JavaScript
	 */
	public function testZIndex()
	{
		//in Flash
		#if flash9
		//create a new DOMObject
		var spriteParentDOMObject:Sprite = new Sprite();
		spriteParentDOMObject.graphics.beginFill(0x00FF00, 0);
		spriteParentDOMObject.graphics.drawRect(0, 0, 200, 200);
		spriteParentDOMObject.graphics.endFill();
		var parentDOMObject:DOMObject = new DOMObject(spriteParentDOMObject);
		
		//add the native Sprite to the Flash Stage
		rootDOMObject.addChild(parentDOMObject);
		
		var spriteChildDOMObject1:Sprite = new Sprite();
		spriteChildDOMObject1.graphics.beginFill(0xFF0000, 1);
		spriteChildDOMObject1.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMObject1.graphics.endFill();
		//create a child DOMObject
		var childDOMObject1:DOMObject = new DOMObject(spriteChildDOMObject1);
		
		var spriteChildDOMObject2:Sprite = new Sprite();
		spriteChildDOMObject2.graphics.beginFill(0x00FF00, 1);
		spriteChildDOMObject2.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMObject2.graphics.endFill();
		//create a child DOMObject
		var childDOMObject2:DOMObject = new DOMObject(spriteChildDOMObject2);
		
		var spriteChildDOMObject3:Sprite = new Sprite();
		spriteChildDOMObject3.graphics.beginFill(0x0000FF, 1);
		spriteChildDOMObject3.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMObject3.graphics.endFill();
		//create a child DOMObject
		var childDOMObject3:DOMObject = new DOMObject(spriteChildDOMObject3);
		
		//in JavaScript
		#elseif js
		//create a new div
		var divParentDOMObject:HtmlDom = js.Lib.document.createElement("div");
		divParentDOMObject.setAttribute("id", "parentDiv");
		
		//create a new DOM object
		var parentDOMObject:DOMObject = new DOMObject(divParentDOMObject);
		
		//parentDOMObject.setWidth(100);
		//parentDOMObject.setHeight(100);
		
		//attach the div to the document body
		rootDOMObject.addChild(parentDOMObject);
		
		//create a new div
		var divChildDOMObject1:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMObject1.setAttribute("id", "childDiv1");
		divChildDOMObject1.style.backgroundColor = "#FF0000";
		
		//create a new DOM object
		var childDOMObject1:DOMObject = new DOMObject(divChildDOMObject1);
		
		//create a new div
		var divChildDOMObject2:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMObject2.setAttribute("id", "childDiv2");
		divChildDOMObject2.style.backgroundColor = "#00FF00";
		
		//create a new DOM object
		var childDOMObject2:DOMObject = new DOMObject(divChildDOMObject2);
		
		//create a new div
		var divChildDOMObject3:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMObject3.setAttribute("id", "childDiv3");
		divChildDOMObject3.style.backgroundColor = "#0000FF";
		
		//create a new DOM object
		var childDOMObject3:DOMObject = new DOMObject(divChildDOMObject3);
		
		//in PHP
		#elseif php
		//create a new div
		var divParentDOMObject:Xml = Xml.createElement("div");
		divParentDOMObject.set("id", "parentDiv");
		
		//create a new DOM object
		var parentDOMObject:DOMObject = new DOMObject(divParentDOMObject);
		
		//parentDOMObject.setWidth(100);
		//parentDOMObject.setHeight(100);
		
		//attach the div to the document body
		rootDOMObject.addChild(parentDOMObject);
		
		//create a new div
		var divChildDOMObject1:Xml = Xml.createElement("div");
		divChildDOMObject1.set("id", "childDiv1");
		//divChildDOMObject1.style.backgroundColor = "#FF0000";
		
		//create a new DOM object
		var childDOMObject1:DOMObject = new DOMObject(divChildDOMObject1);
		
		//create a new div
		var divChildDOMObject2:Xml = Xml.createElement("div");
		divChildDOMObject2.set("id", "childDiv2");
		//divChildDOMObject2.style.backgroundColor = "#00FF00";
		
		//create a new DOM object
		var childDOMObject2:DOMObject = new DOMObject(divChildDOMObject2);
		
		//create a new div
		var divChildDOMObject3:Xml = Xml.createElement("div");
		divChildDOMObject3.set("id", "childDiv3");
		//divChildDOMObject3.style.backgroundColor = "#0000FF";
		
		//create a new DOM object
		var childDOMObject3:DOMObject = new DOMObject(divChildDOMObject3);
		
		#end
		
		//set the width/height and position of the DOMObject
		childDOMObject1.setWidth(100);
		childDOMObject1.setHeight(100);
		childDOMObject2.setWidth(100);
		childDOMObject2.setHeight(100);
		childDOMObject3.setWidth(100);
		childDOMObject3.setHeight(100);
		
		childDOMObject2.setX(50);
		childDOMObject3.setX(80);
		
		//then add them to the parent node
		parentDOMObject.addChild(childDOMObject1);
		parentDOMObject.addChild(childDOMObject2);
		parentDOMObject.addChild(childDOMObject3);
		
		//check the default z-order set when the domObject is tested
		Assert.equals(1, childDOMObject2.getZOrder());
		
		//check z-order manipulation and coherence with another
		//domObject z-index
		childDOMObject2.setZOrder(0);
		Assert.equals(1, childDOMObject1.getZOrder());
		
		//check out of range z-index
		childDOMObject1.setZOrder(999);
		Assert.equals(2, childDOMObject1.getZOrder());
		
	}
	
	/**
	 * Test the container dom object specific method
	 */
	public function testContainerDOMObject()
	{
		#if flash9
		var containerDomObject:ContainerDOMObject = new ContainerDOMObject(new Sprite());
		#elseif js
		var containerDomObject:ContainerDOMObject = new ContainerDOMObject(js.Lib.document.createElement("div"));
		#elseif php
		var containerDomObject:ContainerDOMObject = new ContainerDOMObject(Xml.createElement('div'));
		#end
		
		rootDOMObject.addChild(containerDomObject);
		
		containerDomObject.setSemantic("nav");
		
		Assert.same(containerDomObject.getSemantic(), "nav");
	}
	
	/**
	 * Test the text dom object specific method
	 */
	public function testTextDOMObject()
	{
		#if flash9
		var textDomObject:TextDOMObject = new TextDOMObject(new Sprite());
		#elseif js
		var textDomObject:TextDOMObject = new TextDOMObject(js.Lib.document.createElement("div"));
		#elseif php
		var textDomObject:TextDOMObject = new TextDOMObject(Xml.createElement('div'));
		#end
		
		rootDOMObject.addChild(textDomObject);
		
		textDomObject.setText("<h1>test html text</h1>");
		
		textDomObject.setWidth(500);
		
		Assert.same(textDomObject.getText(), "<h1>test html text</h1>");
	}
	
}