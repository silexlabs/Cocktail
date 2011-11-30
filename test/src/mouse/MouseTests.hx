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
import cocktail.resource.ResourceLoaderManager;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;
import cocktail.domElement.DOMElementData;
import cocktail.domElement.GraphicDOMElement;
import cocktail.mouse.Mouse;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.mouse.MouseData;

class MouseTests 
{
	
	public static function main()
	{
		new MouseTests();
	}
	
	public function new() 
	{
		
		var stageDOMElement:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement(NativeElementManager.createNativeElement(graphic));
		
		graphicDOMElement.width = 200;
		graphicDOMElement.height = 200;
		graphicDOMElement.x = 50;
		graphicDOMElement.y = 50;
		
		graphicDOMElement.beginFill(monochrome( { color:0x00FF00, alpha:100 } ), LineStyleValue.none);
		graphicDOMElement.drawRect(0, 0, 200, 200);
		graphicDOMElement.endFill();
		
		stageDOMElement.addChild(graphicDOMElement);
	
		graphicDOMElement.onMouseDown = onDOMElementPress;
		
		graphicDOMElement.onMouseUp = onDOMElementRelease;
		
		graphicDOMElement.onMouseOver = onDOMElementRollOver;
		
		graphicDOMElement.onMouseOut = onDOMElementRollOut;

		graphicDOMElement.onMouseMove = onDOMElementMouseMove;
		
		graphicDOMElement.onMouseDoubleClick = onDOMElementDoubleClick;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////
	// DOMElement mouse events callbacks
	////////////////////////////////////////////////////////////////////////////////////
	
	private function onDOMElementPress(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse down");
	}
	
	private function onDOMElementDoubleClick(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse double click");
	}
	
	private function onDOMElementRelease(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse release");
	}
	
	private function onDOMElementRollOver(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse roll over");
	}
	
	private function onDOMElementRollOut(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse roll out");
	}
	
	private function onDOMElementMouseMove(mouseEventData:MouseEventData):Void
	{
		Log.trace("mouse move");
	}
	
}