/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package keyboard;

/**
 * Units tests for keyboard events
 * @author Yannick DOMINGUEZ
 */

import haxe.Log;
import cocktail.domElement.base.DOMElementBase;
import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.resource.ResourceLoaderManager;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;
import cocktail.keyboard.KeyboardData;
import cocktail.domElement.DOMElementData;
import cocktail.domElement.GraphicDOMElement;


class KeyboardTests 
{
	private static var rootDOMElement:DOMElement;
	
	public static function main()
	{
		
		rootDOMElement = new DOMElement(NativeReferenceManager.getRoot());
		
		new KeyboardTests();
		
	}
	
	public function new() 
	{
		testKeyboard();
	}
	
	public function testKeyboard()
	{
		var graphicDOMElement:GraphicDOMElement = new GraphicDOMElement();
		
		graphicDOMElement.width  = 100;
		graphicDOMElement.height = 100;
		graphicDOMElement.x = 0;
		graphicDOMElement.y = 0;
		
		graphicDOMElement.beginFill(monochrome( { color:0xFF0000, alpha:100 } ));
		
		graphicDOMElement.drawRect(0, 0, 100, 100);
		graphicDOMElement.endFill();
		
		
		rootDOMElement.addChild(graphicDOMElement);
		
		graphicDOMElement.onKeyDown = onKeyDown;
		graphicDOMElement.onKeyUp = onKeyUp;
		
		
	}

	
	private function onKeyDown(key:Key):Void
	{
		Log.trace(key);
	}
	
	private function onKeyUp(key:Key):Void
	{
		Log.trace(key);
	}
	
}