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
import cocktail.resource.ResourceLoaderManager;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;
import cocktail.domObject.DOMObjectData;
import cocktail.domObject.GraphicDOMObject;
import cocktail.mouse.Mouse;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.nativeReference.NativeReferenceData;
import cocktail.mouse.MouseData;

class MouseTests 
{
	
	public static function main()
	{
		new MouseTests();
	}
	
	public function new() 
	{
		
		var stageDOMObject:DOMObject = new DOMObject(NativeReferenceManager.getRoot());
		
		var graphicDOMObject:GraphicDOMObject = new GraphicDOMObject(NativeReferenceManager.createNativeReference(graphic));
		
		graphicDOMObject.width = 200;
		graphicDOMObject.height = 200;
		graphicDOMObject.x = 50;
		graphicDOMObject.y = 50;
		
		graphicDOMObject.beginFill(monochrome( { color:0x00FF00, alpha:100 } ), LineStyleValue.none);
		graphicDOMObject.drawRect(0, 0, 200, 200);
		graphicDOMObject.endFill();
		
		stageDOMObject.addChild(graphicDOMObject);
	
		graphicDOMObject.onMouseDown = onDOMObjectPress;
		
		graphicDOMObject.onMouseUp = onDOMObjectRelease;
		
		graphicDOMObject.onMouseOver = onDOMObjectRollOver;
		
		graphicDOMObject.onMouseOut = onDOMObjectRollOut;

		graphicDOMObject.onMouseMove = onDOMObjectMouseMove;
		
		graphicDOMObject.onMouseDoubleClick = onDOMObjectDoubleClick;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////
	// DOMObject mouse events callbacks
	////////////////////////////////////////////////////////////////////////////////////
	
	private function onDOMObjectPress(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse down");
	}
	
	private function onDOMObjectDoubleClick(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse double click");
	}
	
	private function onDOMObjectRelease(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse release");
	}
	
	private function onDOMObjectRollOver(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse roll over");
	}
	
	private function onDOMObjectRollOut(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse roll out");
	}
	
	private function onDOMObjectMouseMove(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse move");
	}
	
}