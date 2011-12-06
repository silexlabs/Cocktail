/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package;

/**
 * Class for building an web application looking like an iPhone app
 * 
 * @author	Raphael Harmel
 * @date	2001-11-30
 */

import cocktailCore.style.StyleData;
import cocktail.domElement.ContainerDOMElement;
import cocktail.geom.GeomData;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;

import cocktail.resource.ResourceLoaderManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.nativeElement.NativeElementManager;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// RichList specific
import components.richList.RichList;
import components.richList.RichListModels;
import components.richList.StyleNormal;
import components.richList.StyleApp;
import components.richList.RichListUtils;

// Iphone specific
import Utils;


class WebApp 
{
	
	private static var rootDOMElement:DOMElement;
	
	private var _mainContainer:ContainerDOMElement;
	
	private var _siteLeftFloatBackground:GraphicDOMElement;
	
	public static function main()
	{
		new WebApp();
	}
	
	public function new() 
	{
		#if js
		js.Lib.window.onresize = refresh;
		
		#elseif flash9
		flash.Lib.current.stage.addEventListener(flash.events.Event.RESIZE, refresh);
		
		#end
		drawInterface();
	}
	
	public function drawInterface()
	{
		// create pages
		var applicationStructure:ApplicationStructure = new ApplicationStructure();
		
		// initialize container
		_mainContainer = applicationStructure.pagesContainer;
		WebAppStyle.getDefaultStyle(_mainContainer);
		
		// attach main container to document root
		attach(_mainContainer);
		
		// refresh layout
		refresh();
	}
	
	
	/**
	 * Used to refresh layout
	 * 
	 * @param	event
	 */
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
		
		_mainContainer.style.computedStyle.lineHeight = 70;
		_mainContainer.style.layout( { width:browserWidth, height:browserHeight, isWidthAuto:false, isHeightAuto:false, globalX:0, globalY:0 }, {width:browserWidth, height:browserHeight, globalX:0, globalY:0, isWidthAuto:false, isHeightAuto:false}, {width:browserWidth, height:browserHeight, globalX:0, globalY:0, isWidthAuto:false, isHeightAuto:false}, _mainContainer.style.fontMetrics);
	
	}
	
	/**
	 * Attaches a domElement to the document/root/body/stage
	 * 
	 * @param	domElement
	 */
	private function attach(domElement:DOMElement):Void
	{
		#if flash9
		flash.Lib.current.addChild(domElement.nativeElement);
		#elseif js
		js.Lib.document.body.appendChild(domElement.nativeElement);
		js.Lib.document.body.style.margin = 0;
		#end
	}
	
}