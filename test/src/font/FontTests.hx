/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package font;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeInstance.NativeInstanceManager;
#if flash9
import flash.display.Loader;
import flash.Lib;
import flash.system.ApplicationDomain;
#end
import cocktail.nativeElement.NativeElementManager;
import cocktail.domElement.TextDOMElement;
import cocktail.classInstance.ClassInstance;
import haxe.Log;
import cocktail.domElement.DOMElement;
import cocktail.domElement.abstract.AbstractDOMElement;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;

import cocktail.font.FontData;
import cocktail.font.FontManager;


/**
 * Test the cross-platform font loading
 * @author Yannick DOMINGUEZ & Raphael HARMEL & the.webapp.cat
 */
class FontTests 
{
	
	private static var rootDOMElement:DOMElement;
	
	public static function main()
	{
	
		
		rootDOMElement = new DOMElement(NativeElementManager.getRoot());
		
		var runner = new Runner();
		runner.addCase(new FontTests());
		Report.create(runner);
		runner.run();
		
		#if php
		// display rootDOMElement filled with all tested elements
		untyped __call__('print_r', '<html>' + rootDOMElement.getReferenceToNativeDOM() + '</html>');
		#end
	}
	
	public function new() 
	{
		
	}
	
	/**
	 * Test loading a font - ther must be ttf and eot versions
	 */
	public function testFontLoad()
	{
		var successCallback:FontData->Void = Assert.createEvent(onFontLoaded);
		FontManager.loadFont("embed_test_font.ttf", "EmbedFontTest", successCallback, onFontLoadError);
		FontManager.loadFont("embed_test_font.eot", "EmbedFontTest", successCallback, onFontLoadError);
	}
	
	/**
	 * Called when the Font has been loaded
	 */
	private function onFontLoaded(fontData : FontData):Void
	{
		Assert.isTrue(true);
	}
	
	/**
	 * Called when there is an error while loading Font
	 * @param	msg
	 */
	private function onFontLoadError(msg:String):Void
	{
		
	}
	
}