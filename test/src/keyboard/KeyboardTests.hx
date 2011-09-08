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
import cocktail.domObject.base.DOMObjectBase;
import cocktail.domObject.DOMObject;
import cocktail.domObject.ImageDOMObject;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.resource.ResourceLoaderManager;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;
import cocktail.keyboard.KeyboardData;
import cocktail.domObject.DOMObjectData;
import cocktail.domObject.GraphicDOMObject;


class KeyboardTests 
{
	private static var rootDOMObject:DOMObject;
	
	public static function main()
	{
		
		rootDOMObject = new DOMObject(NativeReferenceManager.getRoot());
		
		new KeyboardTests();
		
	}
	
	public function new() 
	{
		testKeyboard();
	}
	
	public function testKeyboard()
	{
		var graphicDOMObject:GraphicDOMObject = new GraphicDOMObject();
		
		graphicDOMObject.width  = 100;
		graphicDOMObject.height = 100;
		graphicDOMObject.x = 0;
		graphicDOMObject.y = 0;
		
		graphicDOMObject.beginFill(monochrome( { color:0xFF0000, alpha:100 } ));
		
		graphicDOMObject.drawRect(0, 0, 100, 100);
		graphicDOMObject.endFill();
		
		
		rootDOMObject.addChild(graphicDOMObject);
		
		graphicDOMObject.onKeyDown = onKeyDown;
		graphicDOMObject.onKeyUp = onKeyUp;
		
		
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