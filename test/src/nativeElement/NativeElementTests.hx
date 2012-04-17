/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package nativeElement;


import haxe.Log;
import cocktail.core.NativeElement;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.nativeElement.NativeElementData;


/**
 * Test the cross-platform native element manager 
 *@author Yannick DOMINGUEZ
 */
class NativeElementTests 
{
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new NativeElementTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	public function testNativeElement()
	{
		var root = NativeElementManager.getRoot();
		
		#if flash9
		Assert.is(root, flash.display.Stage);
		#elseif js
		Assert.same(root.nodeName, "BODY");
		#end
		
		var canvas = NativeElementManager.createNativeElement(canvas);
		
		#if flash9
		Assert.is(canvas, flash.display.Sprite);
		#elseif js
		Assert.same(canvas.nodeName, "CANVAS");
		#end
		
		var img = NativeElementManager.createNativeElement(img);
		
		#if flash9
		Assert.is(img, flash.display.Loader);
		#elseif js
		Assert.same(img.nodeName, "IMG");
		#end
		
		var script = NativeElementManager.createNativeElement(script);
		
		#if flash9
		Assert.is(script, flash.display.Loader);
		#elseif js
		Assert.same(script.nodeName, "SCRIPT");
		#end
		
		var anchor = NativeElementManager.createNativeElement(anchor);
		
		#if flash9
		Assert.is(anchor, flash.display.Sprite);
		#elseif js
		Assert.same(anchor.nodeName, "A");
		#end
		
		var semantic = NativeElementManager.createNativeElement(semantic("div"));
		
		#if flash9
		Assert.is(semantic, flash.display.Sprite);
		#elseif js
		Assert.same(semantic.nodeName, "DIV");
		#end
		
		var input = NativeElementManager.createNativeElement(input);
		
		#if flash9
		Assert.is(input, flash.display.Sprite);
		#elseif js
		Assert.same(input.nodeName, "INPUT");
		#end
		
		
	}
}