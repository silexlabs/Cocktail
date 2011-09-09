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

import haxe.Log;
import cocktail.domObject.base.DOMObjectBase;
import cocktail.domObject.DOMObject;
import cocktail.domObject.ImageDOMObject;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.resource.ResourceLoaderManager;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;
import cocktail.domObject.DOMObjectData;
import cocktail.domObject.GraphicDOMObject;
import cocktail.mouse.MouseCursorManager;
import cocktail.mouse.MouseData;
import cocktail.nativeReference.NativeReferenceData;

class MouseCursorTests 
{
	
	public static function main()
	{
		
		new MouseCursorTests();
		
	}
	
	public function new() 
	{
		var stageDOMObject:DOMObject = new DOMObject(NativeReferenceManager.getRoot());
		
		var domObject1:GraphicDOMObject = getGraphicDOMObject(0xFF0000);
		var domObject2:GraphicDOMObject = getGraphicDOMObject(0x00FF00);
		var domObject3:GraphicDOMObject = getGraphicDOMObject(0x0000FF);
		var domObject4:GraphicDOMObject = getGraphicDOMObject(0x000000);
		
		stageDOMObject.addChild(domObject1);
		stageDOMObject.addChild(domObject2);
		stageDOMObject.addChild(domObject3);
		stageDOMObject.addChild(domObject4);
		
		domObject2.x = 150;
		domObject3.x = 250;
		domObject4.x = 350;
		
		domObject1.onMouseDown = onPointerPress;
		domObject2.onMouseDown = onBitmapPress;
		domObject3.onMouseDown = onHidePress;
		domObject4.onMouseDown = onAutoPress;
	}
	
	private function getGraphicDOMObject(color:Int):GraphicDOMObject
	{
		var graphicDOMObject:GraphicDOMObject = new GraphicDOMObject(NativeReferenceManager.createNativeReference(graphic));
		
		graphicDOMObject.width = 50;
		graphicDOMObject.height = 50;
		graphicDOMObject.x = 50;
		graphicDOMObject.y = 50;
		
		graphicDOMObject.beginFill(monochrome( { color:color, alpha:100 } ), LineStyleValue.none);
		graphicDOMObject.drawRect(0, 0, 50, 50);
		graphicDOMObject.endFill();
		
		return graphicDOMObject;
	}
	
	private function onPointerPress(mouseEventData:MouseEventData):Void
	{
		MouseCursorManager.setMouseCursor(native(pointer));
	}
	
	private function onBitmapPress(mouseEventData:MouseEventData):Void
	{
		ResourceLoaderManager.loadImage("testPointer.png", onCursorLoaded, function(err:String){});
	}
	
	private function onCursorLoaded(imageDOMObject:ImageDOMObject):Void
	{
		MouseCursorManager.setMouseCursor(custom(imageDOMObject, { x:0.0, y:0.0 } ));
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