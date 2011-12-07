/*
Cocktail is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package font;

import haxe.Log;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeInstance.NativeInstanceManager;

#if flash9
import flash.display.Loader;
import flash.Lib;
import flash.system.ApplicationDomain;
import flash.text.TextFormat;
#end

import cocktail.nativeElement.NativeElementManager;
import cocktail.classInstance.ClassInstance;
import cocktail.domElement.DOMElement;
import cocktail.font.FontData;
import cocktail.font.FontManager;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;


/**
 * Test the cross-platform font loading
 * @author Yannick DOMINGUEZ & Raphael HARMEL & the.webapp.cat
 */
class FontTests 
{
	
	private static var _fontManager : FontManager;
	
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new FontTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		_fontManager = new FontManager();
	}
	
	
	/**
	 * Test loading a font - ther must be ttf and eot versions
	 */
	public function testFontLoad()
	{
		
		#if js
			var successCallback : FontData->Void = Assert.createEvent(onFontLoaded);
			_fontManager.loadFont("embed_test_font.ttf", "EmbedFontTest", successCallback, onFontLoadError);

			js.Lib.document.body.innerHTML += "<h1>Here is text with embed font</h1><br /><span style=\"font-family: EmbedFontTest;\">ABCDEFGHIJKLMNOPQRSTUVWXYZ<br />abcdefghijklmnopqrstuvwxyz<br />123456789.:,;(:*!?&apos;&quot;)<br />The quick brown fox jumps over the lazy dog.</span><br /><hr /><br />";
		#end
		#if flash9
			var successCallback : FontData->Void = Assert.createEvent(onFontLoaded3, 1000);
			_fontManager.loadFont("embed_test_font.swf", "EmbedFontTest", successCallback, onFontLoadError);
		#end
	}
	
	/**
	 * Called when the Font has been loaded
	 */
	private function onFontLoaded(fontData : FontData):Void
	{
		Assert.isTrue(true);
		var successCallback : FontData->Void = Assert.createEvent(onFontLoaded2);
		_fontManager.loadFont("embed_test_font.eot", "EmbedFontTest", successCallback, onFontLoadError);
	}
	/**
	 * Called when the Font has been loaded
	 */
	private function onFontLoaded2(fontData : FontData):Void
	{
		Assert.isTrue(true);
		var successCallback : FontData->Void = Assert.createEvent(onFontLoaded3);
		_fontManager.loadFont("embed_test_font.otf", "EmbedFontTest", successCallback, onFontLoadError);
	}
	/**
	 * Called when the Font has been loaded
	 */
	private function onFontLoaded3(fontData : FontData):Void
	{
		#if flash9
		    var format1:TextFormat = new TextFormat();
		    format1.font="EmbedFontTest";
		    format1.size=25;

			var tf:flash.text.TextField;
			tf = new flash.text.TextField();
			tf.setTextFormat(format1);
			tf.autoSize = flash.text.TextFieldAutoSize.LEFT;
			tf.multiline = true;
			tf.embedFonts=true;
			tf.htmlText = "<b>Here is text with embed font</b><br /><br /><br /><br /><font size=\"25\" face=\"EmbedFontTest\">ABCDEFGHIJKLMNOPQRSTUVWXYZ<br />abcdefghijklmnopqrstuvwxyz<br />123456789.:,;(:*!?&apos;&quot;)<br />The quick brown fox jumps over the lazy dog.</font><br /><br />--end text--";
//			tf.htmlText = "<b>Here is text with embed font</b><br /><br /><br /><br />ABCDEFGHIJKLMNOPQRSTUVWXYZ<br />abcdefghijklmnopqrstuvwxyz<br />123456789.:,;(:*!?&apos;&quot;)<br />The quick brown fox jumps over the lazy dog.<br /><br />";
	        flash.Lib.current.addChild(tf);
		#end

		Assert.isTrue(true);

		// Test font lists
		trace(_fontManager.getEmbeddedFonts());
		Assert.isTrue(_fontManager.hasFont("EmbedFontTest"));
		
// TO DO: test errors
//		errorCallbackAssync = Assert.createEvent(onFontLoadErrorUTest);
//		_fontManager.loadFont("ERROR_LOADING_TEST", "EmbedFontTest", onFontLoaded4, onFontLoadError);
	}
	var errorCallbackAssync:String->Void ;
	/**
	 * Called when the Font has been loaded
	 */
	private function onFontLoaded4(fontData : FontData):Void
	{
		// never called, just used to test errors
	}

	/**
	 * Called when there is an error while loading Font
	 * @param	msg
	 */
	private function onFontLoadError(fontData : FontData, msg:String):Void
	{
		errorCallbackAssync(msg);
	}
	private function onFontLoadErrorUTest(msg:String):Void
	{
		Assert.isTrue(true);
		Log.trace ("Font loading error : "+msg);
	}
}
