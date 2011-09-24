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
import cocktail.domElement.abstract.AbstractDOMElement;

import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;

import cocktail.resource.ResourceLoaderManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.nativeElement.NativeElementManager;


class StyledDOMElementTests 
{
	
	private static var rootDOMElement:DOMElement;
	
	public static function main()
	{
		rootDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		new StyledDOMElementTests();
	}
	
	public function new() 
	{
		testStyle();
	}
	
	public function testStyle()
	{
		var rootStyle:StyleData = getDefaultStyle();
		rootStyle.width = DimensionStyleValue.length(pixel(2000));
		rootStyle.height = DimensionStyleValue.length(pixel(2000));
		rootDOMElement.style = rootStyle;
		
		var container1:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(neutral));
		var container1Style:StyleData = getDefaultStyle();
		container1Style.display = inlineBlock;
		container1.style = container1Style;
		
		container1.style.width = DimensionStyleValue.length(pixel(250));
		container1.style.height = DimensionStyleValue.length(pixel(100));
		container1.style.marginTop = MarginStyleValue.length(pixel(20));
		container1.width = 250;
		container1.height = 100;
		
		var domElement1:GraphicDOMElement = getGraph(0xFF0000, 0, 0, 500, 200);
		
		var domElement1Style:StyleData = getDefaultStyle();
		domElement1.style = domElement1Style;
		domElement1.style.width = DimensionStyleValue.length(pixel(500));
		domElement1.style.height = DimensionStyleValue.length(pixel(200));
		
		var domElement2:GraphicDOMElement = getGraph(0x00FF00, 0, 0, 200, 300);
		
		var domElement2Style:StyleData = getDefaultStyle();
		domElement2.style = domElement2Style;
		domElement2.style.width = DimensionStyleValue.length(pixel(200));
		domElement2.style.height = DimensionStyleValue.length(pixel(300));
		
		
		var domElement3:GraphicDOMElement = getGraph(0x0000FF, 0, 0, 50, 300);
		
		var domElement3Style:StyleData = getDefaultStyle();
		//domElement3Style.display = inlineBlock;
		domElement3.style = domElement3Style;
		domElement3.style.width = DimensionStyleValue.length(pixel(50));
		domElement3.style.height = DimensionStyleValue.length(pixel(100));
		domElement3.style.marginLeft = MarginStyleValue.length(pixel(50));
		
		
		rootDOMElement.addChild(domElement1);
		container1.addChild(domElement2);
		rootDOMElement.addChild(container1);
		rootDOMElement.addChild(domElement3);
		
		
		rootDOMElement.layout( { width:1000, height:1000 }, rootDOMElement, rootDOMElement);
	}
	
	private function getGraph(color:Int, x:Int, y:Int, width:Int, height:Int):GraphicDOMElement
	{
		
		
		var ret:GraphicDOMElement = new GraphicDOMElement();
		
		ret.width = width;
		ret.height = height;
		
		ret.beginFill(FillStyleValue.monochrome( { color:color, alpha:100 } ), LineStyleValue.none);
		ret.drawRect(x, y, width, height);
		ret.endFill();
		

		
		return ret;
	}
	
	
	private function getDefaultStyle():StyleData
	{
		return {
			marginLeft:length(pixel(0)),
			marginRight:length(pixel(0)),
			marginTop:length(pixel(0)),
			marginBottom:length(pixel(0)),
			
			paddingLeft:PaddingStyleValue.length(pixel(0)),
			paddingRight:PaddingStyleValue.length(pixel(0)),
			paddingTop:PaddingStyleValue.length(pixel(0)),
			paddingBottom:PaddingStyleValue.length(pixel(0)),
			
			top:PositionOffsetStyleValue.length(pixel(0)),
			left:PositionOffsetStyleValue.length(pixel(0)),
			right:PositionOffsetStyleValue.length(pixel(0)),
			bottom:PositionOffsetStyleValue.length(pixel(0)),
			
			minWidth:ConstrainedDimensionStyleValue.none,
			maxWidth:ConstrainedDimensionStyleValue.none,
			minHeight:ConstrainedDimensionStyleValue.none,
			maxHeight:ConstrainedDimensionStyleValue.none,
			
			display:block,
			
			position:_static,
			
			width:DimensionStyleValue.auto,
			height:DimensionStyleValue.auto
		}
	}
	
}