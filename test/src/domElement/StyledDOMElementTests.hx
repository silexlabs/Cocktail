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
	
	private var _mainContainer:ContainerDOMElement;
	
	private var _background:GraphicDOMElement;
	
	private var _siteBackground:GraphicDOMElement;
	
	private var _navigation:GraphicDOMElement;
	
	private var _header:GraphicDOMElement;
	
	private var _siteRightBackground:GraphicDOMElement;
	
	private var _footer:GraphicDOMElement;
	
	public static function main()
	{
		//rootDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		new StyledDOMElementTests();
	}
	
	public function new() 
	{
		#if js
		js.Lib.window.onresize = refresh;
		
		#elseif flash9
		flash.Lib.current.stage.addEventListener(flash.events.Event.RESIZE, refresh);
		
		#end
		testLayout();
		
		
		
	}
	
	public function testStyle()
	{
		/**var rootStyle:StyleData = getDefaultStyle();
		rootStyle.width = DimensionStyleValue.percent(100);
		rootStyle.height = DimensionStyleValue.auto;
		rootDOMElement.style = rootStyle;
		
		var container1:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(neutral));
		var container1Style:StyleData = getDefaultStyle();
		//container1Style.display = inlineBlock;
		container1.style = container1Style;
		
		container1.style.width = DimensionStyleValue.auto;
		container1.style.height = DimensionStyleValue.auto;
		container1.style.marginTop = MarginStyleValue.length(pixel(20));
		//container1.style.position = relative;
		//container1.width = 250;
		//container1.height = 100;
		container1.x = 0;
		container1.y = 0;
		
		var domElement1:GraphicDOMElement = getGraph(0xFF0000, 0, 0, 500, 200);
		
		var domElement1Style:StyleData = getDefaultStyle();
		domElement1.style = domElement1Style;
		domElement1.style.width = DimensionStyleValue.percent(100);
		domElement1.style.height = DimensionStyleValue.length(pixel(200));
		
		var domElement2:GraphicDOMElement = getGraph(0x00FF00, 0, 0, 200, 300);
		
		var domElement2Style:StyleData = getDefaultStyle();
		domElement2Style.position = relative;
		domElement2Style.bottom = PositionOffsetStyleValue.length(pixel(100));
		domElement2Style.display = inlineBlock;
		domElement2.style = domElement2Style;
		domElement2.style.width = DimensionStyleValue.length(pixel(200));
		domElement2.style.height = DimensionStyleValue.length(pixel(300));
		
		
		var domElement3:GraphicDOMElement = getGraph(0x0000FF, 0, 0, 50, 300);
		
		var domElement3Style:StyleData = getDefaultStyle();
		domElement3Style.maxHeight = ConstrainedDimensionStyleValue.length(pixel(200));
		domElement3.style = domElement3Style;
		domElement3.style.width = DimensionStyleValue.length(pixel(50));
		domElement3.style.height = DimensionStyleValue.length(pixel(800));
		domElement3.style.marginLeft = MarginStyleValue.length(pixel(50));
		
		var domElement4:GraphicDOMElement = getGraph(0x999999, 0, 0, 600, 30);
		
		var domElement4Style:StyleData = getDefaultStyle();
		domElement4Style.display = inlineBlock;
		domElement4.style = domElement4Style;
		domElement4.style.width = DimensionStyleValue.length(pixel(600));
		domElement4.style.height = DimensionStyleValue.length(pixel(30));
		domElement4.style.marginLeft = MarginStyleValue.length(pixel(20));
		
		var domElement5:TextDOMElement = new TextDOMElement();
		domElement5.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis eu facilisis mi. Curabitur convallis tortor sit amet mi euismod convallis convallis justo placerat. Suspendisse rutrum justo et nunc dapibus semper. Donec id lectus nec lorem consectetur elementum ac eget odio. Curabitur ac ligula sem. Donec diam nisl, cursus eu luctus in, porttitor a tellus. Nullam auctor erat eget mi tristique porttitor. Quisque dignissim mattis purus id hendrerit. Cras turpis enim, ultricies viverra scelerisque eu, pharetra eget nibh. Suspendisse potenti";
		
		domElement5.style = getDefaultStyle();
		domElement5.style.width = DimensionStyleValue.percent(60);
		domElement5.style.position = relative;
		domElement5.style.display = inlineBlock;
		domElement5.style.right = PositionOffsetStyleValue.length(pixel(200));
		domElement5.style.paddingRight = PaddingStyleValue.length(pixel(123));
		domElement5.style.height = DimensionStyleValue.length(pixel(200));
		
		var domElement6:GraphicDOMElement = getGraph(0x000000, 0, 0, 100, 50);
		var domElement6Style:StyleData = getDefaultStyle();
		domElement6.style = domElement6Style;
		domElement6Style.width =  DimensionStyleValue.length(pixel(100));
		domElement6Style.height =  DimensionStyleValue.length(pixel(50));
		domElement6Style.marginRight = MarginStyleValue.auto;
		domElement6Style.marginLeft = MarginStyleValue.auto;
		
		rootDOMElement.addChild(domElement1);
		container1.addChild(domElement2);
		container1.addChild(domElement5);
		container1.addChild(domElement4);
		rootDOMElement.addChild(container1);
		rootDOMElement.addChild(domElement3);
		rootDOMElement.addChild(domElement6);
		

		
		rootDOMElement.applyStyle( { width:1000, height:1000 }, rootDOMElement);
		domElement4.style.width = DimensionStyleValue.percent(10);
		container1.applyStyle( { width : container1.width, height:container1.height }, rootDOMElement);*/
	}
	
	public function testLayout()
	{
		_background = getGraph();
		_background.style.width = DimensionStyleValue.percent(100);
		_background.style.height = DimensionStyleValue.length(pixel(2000));
		_background.style.position = absolute;
		
		
		_mainContainer = getContainer();
		_mainContainer.style.width = DimensionStyleValue.percent(100);
		_mainContainer.style.height = DimensionStyleValue.auto;
		
		
		attach(_mainContainer);
		
		_mainContainer.addChild(_background);
		
		_siteBackground = getGraph();
		_siteBackground.style.width = DimensionStyleValue.percent(100);
		_siteBackground.style.height = DimensionStyleValue.length(pixel(2000));
		_siteBackground.style.position = absolute;
		
		var siteContainer:ContainerDOMElement = getContainer();
		siteContainer.style.position = relative;
		siteContainer.style.width = DimensionStyleValue.percent(70);
		siteContainer.style.height = DimensionStyleValue.auto;
		siteContainer.style.marginLeft = MarginStyleValue.auto;
		siteContainer.style.marginRight = MarginStyleValue.auto;
		siteContainer.style.marginTop = MarginStyleValue.length(pixel(10));
		
		siteContainer.addChild(_siteBackground);
		
		var headerContainer:ContainerDOMElement = getContainer();
		headerContainer.style.width = DimensionStyleValue.percent(100);
		headerContainer.style.height = DimensionStyleValue.length(pixel(150));
		headerContainer.style.paddingTop = PaddingStyleValue.length(pixel(5));
		headerContainer.style.paddingBottom = PaddingStyleValue.length(pixel(5));
		headerContainer.style.paddingLeft = PaddingStyleValue.length(pixel(5));
		headerContainer.style.paddingRight = PaddingStyleValue.length(pixel(5));
		headerContainer.style.marginBottom = MarginStyleValue.length(pixel(10));
		
		_header = getGraph();
		_header.style.width = DimensionStyleValue.auto;
		_header.style.height = DimensionStyleValue.percent(100);
		
		headerContainer.addChild(_header);
		
		siteContainer.addChild(headerContainer);
		
		var siteLeftContainer:ContainerDOMElement = getContainer();
		siteLeftContainer.style.width = DimensionStyleValue.percent(70);
		siteLeftContainer.style.height = DimensionStyleValue.auto;
		siteLeftContainer.style.display = inlineBlock;

		
		_navigation = getGraph();
		_navigation.style.width = DimensionStyleValue.auto;
		_navigation.style.height = DimensionStyleValue.length(pixel(50));
		_navigation.style.paddingLeft = PaddingStyleValue.length(pixel(10));
		_navigation.style.paddingRight = PaddingStyleValue.length(pixel(10));
		_navigation.style.marginLeft = MarginStyleValue.auto;
		_navigation.style.marginRight = MarginStyleValue.auto;
		
		var siteLeftText:TextDOMElement = getText();
		siteLeftText.style.width = DimensionStyleValue.auto;
		siteLeftText.style.paddingLeft = PaddingStyleValue.length(pixel(10));
		siteLeftText.style.paddingRight = PaddingStyleValue.length(pixel(10));
		siteLeftText.style.marginTop = MarginStyleValue.length(pixel(10));
		siteLeftText.style.height = DimensionStyleValue.length(pixel(300));
		siteLeftText.style.marginLeft = MarginStyleValue.auto;
		siteLeftText.style.marginRight = MarginStyleValue.auto;
		
		
		siteContainer.addChild(siteLeftContainer);
		siteLeftContainer.addChild(_navigation);
		siteLeftContainer.addChild(siteLeftText);
		
		var siteContainerRight:ContainerDOMElement = getContainer();
		siteContainerRight.style.width = DimensionStyleValue.percent(30);
		siteContainerRight.style.height = DimensionStyleValue.length(pixel(500));
		siteContainerRight.style.display = inlineBlock;
		
		siteContainer.addChild(siteContainerRight);
	
		
		_siteRightBackground = getGraph();
		_siteRightBackground.style.width = DimensionStyleValue.auto;
		_siteRightBackground.style.height = DimensionStyleValue.percent(100);
		
		siteContainerRight.addChild(_siteRightBackground);
		
		 _footer = getGraph();
		_footer.style.width = DimensionStyleValue.percent(100);
		_footer.style.height = DimensionStyleValue.length(pixel(250));
		_footer.style.marginTop = MarginStyleValue.length(pixel(10));
		
		
		siteContainer.addChild(_footer);
		
		_mainContainer.addChild(siteContainer);
		
		refresh();
		
		
		
	
	}
	
	private function paint(domElement:GraphicDOMElement, color:Int):Void
	{
		domElement.clear();
		domElement.beginFill(FillStyleValue.monochrome( { color:color, alpha:100 } ), LineStyleValue.none);
		domElement.drawRect(0, 0, domElement.width, domElement.height);
		domElement.endFill();
		
	}
	
	private function refresh(event:Dynamic = null)
	{
		var browserWidth:Int;
		var browserHeight:Int;
		
		#if flash9
		browserWidth = Math.round(flash.Lib.current.stage.stageWidth);
		browserHeight = Math.round(flash.Lib.current.stage.stageHeight);
		#elseif js
		browserWidth = js.Lib.document.body.clientWidth;
		browserHeight = js.Lib.document.body.clientHeight;
		#end
		_mainContainer.applyStyle( { width:browserWidth, height:browserHeight }, _mainContainer);
		
		paint(_background, 0x222222);
		paint(_siteBackground, 0xFFFFFF);
		paint(_header, 0xDDDDDD);
		paint(_navigation, 0xDDDDDD);
		paint(_siteRightBackground, 0xDDDDDD);
		paint(_footer, 0xDDDDDD);
	}
	
	private function attach(domElement:DOMElement):Void
	{
		#if flash9
		flash.Lib.current.addChild(domElement.nativeElement);
		#elseif js
		js.Lib.document.body.appendChild(domElement.nativeElement);
		#end
	}
	
	private function getContainer():ContainerDOMElement
	{
		var ret:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(neutral));
		ret.style = getDefaultStyle();
		ret.x = 0;
		ret.y = 0;
		return ret;
	}
	
	private function getText():TextDOMElement
	{
		var ret:TextDOMElement = new TextDOMElement();
		ret.x = 0;
		ret.y = 0;
		ret.style = getDefaultStyle();
		ret.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis eu facilisis mi. Curabitur convallis tortor sit amet mi euismod convallis convallis justo placerat. Suspendisse rutrum justo et nunc dapibus semper. Donec id lectus nec lorem consectetur elementum ac eget odio. Curabitur ac ligula sem. Donec diam nisl, cursus eu luctus in, porttitor a tellus. Nullam auctor erat eget mi tristique porttitor. Quisque dignissim mattis purus id hendrerit. Cras turpis enim, ultricies viverra scelerisque eu, pharetra eget nibh. Suspendisse potenti";
		return ret;
		
	}
	
	private function getGraph():GraphicDOMElement
	{
		
		
		var ret:GraphicDOMElement = new GraphicDOMElement();
		
		ret.style = getDefaultStyle();
		
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