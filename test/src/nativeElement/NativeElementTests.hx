/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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