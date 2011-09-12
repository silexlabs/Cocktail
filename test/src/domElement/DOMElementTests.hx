/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package domElement;

/**
 * Units tests for DOMElements
 * @author Yannick DOMINGUEZ & Raphael HARMEL
 * 
 * 2011-08-10 PHP part is not complete yet.
 * 
 */

import haxe.Log;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.TextDOMElement;
import cocktail.geom.GeomData;
import cocktail.domElement.DOMElement;
import cocktail.domElement.base.DOMElementBase;

import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;
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

class DOMElementTests 
{
	
	private static var rootDOMElement:DOMElement;
	
	public static function main()
	{
		rootDOMElement = new DOMElement(NativeReferenceManager.getRoot());
		
		var runner = new Runner();
		runner.addCase(new DOMElementTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
	}
	
	#if flash9
	
	/**
	 * test adding/removing DOMElement,
	 * and getting/setting there properties for Flash as3
	 */
	public function testAddRemoveChild()
	{
		var spriteParentDOMElement:Sprite = new Sprite();
		spriteParentDOMElement.graphics.beginFill(0x00FF00, 1);
		spriteParentDOMElement.graphics.drawRect(0, 0, 200, 200);
		spriteParentDOMElement.graphics.endFill();
		//create a new DOMElement
		var parentDOMElement:DOMElement = new DOMElement(spriteParentDOMElement);
		
		//add the native Sprite to the Flash Stage
		Lib.current.addChild(parentDOMElement.nativeReference);
		
		var spriteChildDOMElement:Sprite = new Sprite();
		spriteChildDOMElement.graphics.beginFill(0xFF0000, 1);
		spriteChildDOMElement.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMElement.graphics.endFill();
		//create a child DOMElement
		var childDOMElement:DOMElement = new DOMElement(spriteChildDOMElement);
		childDOMElement.setWidth(100);
		childDOMElement.setHeight(100);
		
		//add the child DOMElement to the parent DOMElement
		parentDOMElement.addChild(childDOMElement);
		
		//compare the names to verify that the children's parent is the parent DOMElement
		Assert.same(childDOMElement.getParent().nativeReference.name, parentDOMElement.nativeReference.name);
		
		//test getting each of the properties of the child DOMElement
		Assert.equals(childDOMElement.getWidth(), 100);
		Assert.equals(childDOMElement.getHeight(), 100);
		Assert.equals(childDOMElement.getX(), 0);
		Assert.equals(childDOMElement.getY(), 0);
		Assert.equals(childDOMElement.getZOrder(), 0);
		
		//set the child height of the DOMElement and test the returned height
		childDOMElement.setHeight(200);
		Assert.equals(childDOMElement.getHeight(), 200);
		
		//remove the child and parent DOMElements from the display list
		parentDOMElement.removeChild(childDOMElement);
		Lib.current.removeChild(parentDOMElement.nativeReference);
		
		//check that the parent is now null
		Assert.same(childDOMElement.getParent(), null);
		
	}
	
	#elseif js
	
	/**
	 * test adding/removing DOMElement,
	 * and getting/setting there properties for JavaScript
	 */
	public function testAddRemoveChild()
	{
		//create a new div
		var divParentDOMElement:HtmlDom = js.Lib.document.createElement("div");
		divParentDOMElement.setAttribute("id","parentDiv");
		divParentDOMElement.innerHTML = "parent div";
		
		//create a new DOM object
		var parentDOMElement:DOMElement = new DOMElement(divParentDOMElement);
		
		//attach the div to the document body
		rootDOMElement.addChild(parentDOMElement);
		

		
		//create a new child div
		var divChildDOMElement:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMElement.setAttribute("id", "childDiv");
		divChildDOMElement.innerHTML = "child div";
		
		//create a new child DOMElement
		var childDOMElement:DOMElement = new DOMElement(divChildDOMElement);
		
		childDOMElement.setWidth(300);
		childDOMElement.setHeight(200);
		childDOMElement.setX(100);
		childDOMElement.setY(50);
		
		//attach the child DOMElement on the parent DOMElement
		parentDOMElement.addChild(childDOMElement);
		
		//test getting each of the properties of the child DOMElement
		Assert.equals(childDOMElement.getWidth(), 300);
		Assert.equals(childDOMElement.getHeight(), 200);
		Assert.equals(childDOMElement.getX(), 100);
		Assert.equals(childDOMElement.getY(), 50);
		Assert.equals(childDOMElement.getZOrder(), 0);
		
		
		//check the parent of the child DOMElement
		//Assert.same(childDOMElement.getParent(), parentDOMElement);
		
		//remove the child DOMElement from the div
		parentDOMElement.removeChild(childDOMElement);
		
		//check that the child object has no more parent
		Assert.same(childDOMElement.getParent(), null);
	}

	#elseif php
	
	/**
	 * test adding/removing DOMElement,
	 * and getting/setting there properties for JavaScript
	 */
	public function testAddRemoveChild()
	{
		//create a new div
		var divParentDOMElement:Xml = Xml.createElement("div");
		divParentDOMElement.set("id","parentDiv");
		divParentDOMElement.addChild(Xml.createPCData("parent div"));
		
		//create a new DOM object
		var parentDOMElement:DOMElement = new DOMElement(divParentDOMElement);
		
		//attach the div to the document body
		rootDOMElement.addChild(parentDOMElement);

		//create a new child div
		var divChildDOMElement:Xml = Xml.createElement("div");
		divChildDOMElement.set("id","childDiv");
		divChildDOMElement.addChild(Xml.createPCData("child div"));
		
		//create a new child DOMElement
		var childDOMElement:DOMElement = new DOMElement(divChildDOMElement);
		
		childDOMElement.setWidth(300);
		childDOMElement.setHeight(200);
		childDOMElement.setX(100);
		childDOMElement.setY(50);
		
		//attach the child DOMElement on the parent DOMElement
		parentDOMElement.addChild(childDOMElement);
		
		//test getting each of the properties of the child DOMElement
		Assert.equals(childDOMElement.getWidth(), 300);
		Assert.equals(childDOMElement.getHeight(), 200);
		Assert.equals(childDOMElement.getX(), 100);
		Assert.equals(childDOMElement.getY(), 50);
		Assert.equals(childDOMElement.getZOrder(), 0);
		
		//check the parent of the child DOMElement
		//Assert.same(childDOMElement.getParent(), parentDOMElement);
		
		//remove the child DOMElement from the div
		parentDOMElement.removeChild(childDOMElement);
		
		//check that the child object has no more parent
		Assert.same(childDOMElement.getParent(), null);
	}
	#end
	
	/**
	 * Test visibility and opacity methods
	 */
	public function testVisibilityOpacity()
	{
		#if flash9
		var nativeDOMElement:Dynamic = new flash.display.Sprite();
		#elseif js
		var nativeDOMElement:Dynamic = js.Lib.document.createElement("canvas");
		#end
		
		//test with a graphic dom object to easily have a background
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(nativeDOMElement);
		
		graphicDOMElement.setWidth(200);
		graphicDOMElement.setHeight(200);
		graphicDOMElement.setX(0);
		graphicDOMElement.setY(100);
		
		var colorStop:ColorStopData = { color:Std.parseInt("0xFF0000") , alpha:100 };
		var fillStyle:FillStyleValue = monochrome(colorStop);
		
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		graphicDOMElement.beginFill(fillStyle, lineStyle);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:10,
			trCornerRadius:0,
			blCornerRadius:20,
			brCornerRadius:0
		}
		
		
		graphicDOMElement.drawRect(0, 0, 100, 100, cornerRadiuses);
		graphicDOMElement.endFill();
		
		rootDOMElement.addChild(graphicDOMElement);
		
		graphicDOMElement.setIsVisible(false);
		Assert.equals(graphicDOMElement.getIsVisible(), false);
		
		graphicDOMElement.setIsVisible(true);
		Assert.equals(graphicDOMElement.getIsVisible(), true);
		
		graphicDOMElement.setAlpha(0.5);
		Assert.equals(graphicDOMElement.getAlpha(), 0.5);
	}
	
	/**
	 * Test the manipulation of DOMElements z-indexes in Flash and JavaScript
	 */
	public function testZIndex()
	{
		//in Flash
		#if flash9
		//create a new DOMElement
		var spriteParentDOMElement:Sprite = new Sprite();
		spriteParentDOMElement.graphics.beginFill(0x00FF00, 0);
		spriteParentDOMElement.graphics.drawRect(0, 0, 200, 200);
		spriteParentDOMElement.graphics.endFill();
		var parentDOMElement:DOMElement = new DOMElement(spriteParentDOMElement);
		
		//add the native Sprite to the Flash Stage
		rootDOMElement.addChild(parentDOMElement);
		
		var spriteChildDOMElement1:Sprite = new Sprite();
		spriteChildDOMElement1.graphics.beginFill(0xFF0000, 1);
		spriteChildDOMElement1.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMElement1.graphics.endFill();
		//create a child DOMElement
		var childDOMElement1:DOMElement = new DOMElement(spriteChildDOMElement1);
		
		var spriteChildDOMElement2:Sprite = new Sprite();
		spriteChildDOMElement2.graphics.beginFill(0x00FF00, 1);
		spriteChildDOMElement2.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMElement2.graphics.endFill();
		//create a child DOMElement
		var childDOMElement2:DOMElement = new DOMElement(spriteChildDOMElement2);
		
		var spriteChildDOMElement3:Sprite = new Sprite();
		spriteChildDOMElement3.graphics.beginFill(0x0000FF, 1);
		spriteChildDOMElement3.graphics.drawRect(0, 0, 100, 100);
		spriteChildDOMElement3.graphics.endFill();
		//create a child DOMElement
		var childDOMElement3:DOMElement = new DOMElement(spriteChildDOMElement3);
		
		//in JavaScript
		#elseif js
		//create a new div
		var divParentDOMElement:HtmlDom = js.Lib.document.createElement("div");
		divParentDOMElement.setAttribute("id", "parentDiv");
		
		//create a new DOM object
		var parentDOMElement:DOMElement = new DOMElement(divParentDOMElement);
		
		//parentDOMElement.setWidth(100);
		//parentDOMElement.setHeight(100);
		
		//attach the div to the document body
		rootDOMElement.addChild(parentDOMElement);
		
		//create a new div
		var divChildDOMElement1:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMElement1.setAttribute("id", "childDiv1");
		divChildDOMElement1.style.backgroundColor = "#FF0000";
		
		//create a new DOM object
		var childDOMElement1:DOMElement = new DOMElement(divChildDOMElement1);
		
		//create a new div
		var divChildDOMElement2:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMElement2.setAttribute("id", "childDiv2");
		divChildDOMElement2.style.backgroundColor = "#00FF00";
		
		//create a new DOM object
		var childDOMElement2:DOMElement = new DOMElement(divChildDOMElement2);
		
		//create a new div
		var divChildDOMElement3:HtmlDom = js.Lib.document.createElement("div");
		divChildDOMElement3.setAttribute("id", "childDiv3");
		divChildDOMElement3.style.backgroundColor = "#0000FF";
		
		//create a new DOM object
		var childDOMElement3:DOMElement = new DOMElement(divChildDOMElement3);
		
		//in PHP
		#elseif php
		//create a new div
		var divParentDOMElement:Xml = Xml.createElement("div");
		divParentDOMElement.set("id", "parentDiv");
		
		//create a new DOM object
		var parentDOMElement:DOMElement = new DOMElement(divParentDOMElement);
		
		//parentDOMElement.setWidth(100);
		//parentDOMElement.setHeight(100);
		
		//attach the div to the document body
		rootDOMElement.addChild(parentDOMElement);
		
		//create a new div
		var divChildDOMElement1:Xml = Xml.createElement("div");
		divChildDOMElement1.set("id", "childDiv1");
		//divChildDOMElement1.style.backgroundColor = "#FF0000";
		
		//create a new DOM object
		var childDOMElement1:DOMElement = new DOMElement(divChildDOMElement1);
		
		//create a new div
		var divChildDOMElement2:Xml = Xml.createElement("div");
		divChildDOMElement2.set("id", "childDiv2");
		//divChildDOMElement2.style.backgroundColor = "#00FF00";
		
		//create a new DOM object
		var childDOMElement2:DOMElement = new DOMElement(divChildDOMElement2);
		
		//create a new div
		var divChildDOMElement3:Xml = Xml.createElement("div");
		divChildDOMElement3.set("id", "childDiv3");
		//divChildDOMElement3.style.backgroundColor = "#0000FF";
		
		//create a new DOM object
		var childDOMElement3:DOMElement = new DOMElement(divChildDOMElement3);
		
		#end
		
		//set the width/height and position of the DOMElement
		childDOMElement1.setWidth(100);
		childDOMElement1.setHeight(100);
		childDOMElement2.setWidth(100);
		childDOMElement2.setHeight(100);
		childDOMElement3.setWidth(100);
		childDOMElement3.setHeight(100);
		
		childDOMElement2.setX(50);
		childDOMElement3.setX(80);
		
		//then add them to the parent node
		parentDOMElement.addChild(childDOMElement1);
		parentDOMElement.addChild(childDOMElement2);
		parentDOMElement.addChild(childDOMElement3);
		
		//check the default z-order set when the domElement is tested
		Assert.equals(1, childDOMElement2.getZOrder());
		
		//check z-order manipulation and coherence with another
		//domElement z-index
		childDOMElement2.setZOrder(0);
		Assert.equals(1, childDOMElement1.getZOrder());
		
		//check out of range z-index
		childDOMElement1.setZOrder(999);
		Assert.equals(2, childDOMElement1.getZOrder());
		
	}
	
	/**
	 * Test the container dom object specific method
	 */
	public function testContainerDOMElement()
	{
		#if flash9
		var containerDomObject:ContainerDOMElement = new ContainerDOMElement(new Sprite());
		#elseif js
		var containerDomObject:ContainerDOMElement = new ContainerDOMElement(js.Lib.document.createElement("div"));
		#elseif php
		var containerDomObject:ContainerDOMElement = new ContainerDOMElement(Xml.createElement('div'));
		#end
		
		rootDOMElement.addChild(containerDomObject);
		
		containerDomObject.setSemantic("nav");
		
		Assert.same(containerDomObject.getSemantic(), "nav");
	}
	
	/**
	 * Test the text dom object specific method
	 */
	public function testTextDOMElement()
	{
		#if flash9
		var textDomObject:TextDOMElement = new TextDOMElement(new Sprite());
		#elseif js
		var textDomObject:TextDOMElement = new TextDOMElement(js.Lib.document.createElement("div"));
		#elseif php
		var textDomObject:TextDOMElement = new TextDOMElement(Xml.createElement('div'));
		#end
		
		rootDOMElement.addChild(textDomObject);
		
		textDomObject.setText("<h1>test html text</h1>");
		
		textDomObject.setWidth(500);
		
		Assert.same(textDomObject.getText(), "<h1>test html text</h1>");
	}
	
}