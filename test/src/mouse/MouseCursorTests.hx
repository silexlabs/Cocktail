/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package mouse;

/**
 * Units tests for mouse events
 * @author Yannick DOMINGUEZ
 */

import cocktail.domElement.ContainerDOMElement;
import haxe.Log;
import cocktail.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.resource.ResourceLoaderManager;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;
import cocktail.domElement.DOMElementData;
import cocktail.domElement.GraphicDOMElement;
import cocktail.mouse.MouseCursorManager;
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElementData;

class MouseCursorTests 
{
	
	public static function main()
	{
		
		new MouseCursorTests();
		
	}
	
	public function new() 
	{
		var stageDOMElement:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		
		var domElement1:GraphicDOMElement = getGraphicDOMElement(0xFF0000);
		var domElement2:GraphicDOMElement = getGraphicDOMElement(0x00FF00);
		var domElement3:GraphicDOMElement = getGraphicDOMElement(0x0000FF);
		var domElement4:GraphicDOMElement = getGraphicDOMElement(0x000000);
		
		stageDOMElement.addChild(domElement1);
		stageDOMElement.addChild(domElement2);
		stageDOMElement.addChild(domElement3);
		stageDOMElement.addChild(domElement4);
		
		domElement2.x = 150;
		domElement3.x = 250;
		domElement4.x = 350;
		
		domElement1.onMouseDown = onPointerPress;
		domElement2.onMouseDown = onBitmapPress;
		domElement3.onMouseDown = onHidePress;
		domElement4.onMouseDown = onAutoPress;
	}
	
	private function getGraphicDOMElement(color:Int):GraphicDOMElement
	{
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(NativeElementManager.createNativeElement(graphic));
		
		graphicDOMElement.width = 50;
		graphicDOMElement.height = 50;
		graphicDOMElement.x = 50;
		graphicDOMElement.y = 50;
		
		graphicDOMElement.beginFill(monochrome( { color:color, alpha:100 } ), LineStyleValue.none);
		graphicDOMElement.drawRect(0, 0, 50, 50);
		graphicDOMElement.endFill();
		
		return graphicDOMElement;
	}
	
	private function onPointerPress(mouseEventData:MouseEventData):Void
	{
		MouseCursorManager.setMouseCursor(native(pointer));
	}
	
	private function onBitmapPress(mouseEventData:MouseEventData):Void
	{
		ResourceLoaderManager.loadImage("testPointer.png", onCursorLoaded, function(err:String){});
	}
	
	private function onCursorLoaded(imageDOMElement:ImageDOMElement):Void
	{
		MouseCursorManager.setMouseCursor(custom(imageDOMElement, { x:0.0, y:0.0 } ));
	}
	
	private function onHidePress(mouseEventData:MouseEventData):Void
	{
		MouseCursorManager.setMouseCursor(MouseCursorValue.none);
	}
	
	private function onAutoPress(mouseEventData:MouseEventData):Void
	{
		MouseCursorManager.setMouseCursor(auto);
	}
	
}