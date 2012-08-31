/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;

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
		#if flash9
			if (flash.Lib.current.loaderInfo.url.indexOf("http")==-1)
			{
				trace("Error : you have to run this test from a web server - e.g. http://localhost");
				return;
			}
		#end

		_fontManager = new FontManager();
	}
	
	
	/**
	 * Test loading a font - ther must be ttf and eot versions
	 */
	public function testFontLoad()
	{
		trace("*************** *************** *************** ***************");
		trace("IMPORTANT CHECK TO DO : check that the text on top of the page has an embeded font");
		trace("*************** *************** *************** ***************");
		#if js
			var successCallback : FontData->Void = Assert.createEvent(onFontLoaded);
			_fontManager.loadFont("embed_test_font.ttf", "EmbedFontTest", successCallback, onFontLoadError);
			js.Lib.document.body.innerHTML += "<h1>Here is text with embed font</h1><br />
				<span style=\"font-size: 16pt; font-family: EmbedFontTest;\">ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 123456789.:,;(:*!?&apos;&quot;) The quick brown fox jumps over the lazy dog.<br /><hr /><br />";
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
			var someText:String = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 123456789.:,;(:*!?'\") The quick brown fox jumps over the lazy dog.";
            var fontSize:Int = 22;

            var format:ElementFormat = new ElementFormat();        
            format.fontDescription = new FontDescription("EmbedFontTest", flash.text.engine.FontWeight.NORMAL, flash.text.engine.FontPosture.NORMAL, flash.text.engine.FontLookup.EMBEDDED_CFF, flash.text.engine.RenderingMode.CFF);
            format.fontSize = fontSize;

            var textBlock:TextBlock = new TextBlock();
            textBlock.content = new TextElement(someText, format);
            var textLine = textBlock.createTextLine(null, flash.Lib.current.stage.stageWidth);
            textLine.y = 100;
            flash.Lib.current.addChild(textLine);      
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
