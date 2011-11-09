/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package resource;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeInstance.NativeInstanceManager;
 #if flash9

import flash.display.Loader;
import flash.Lib;
import flash.system.ApplicationDomain;


#end
import cocktail.nativeElement.NativeElementManager;
import cocktail.classInstance.ClassInstance;
import haxe.Log;
import cocktail.domElement.DOMElement;
import cocktail.domElement.abstract.AbstractDOMElement;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;


import cocktail.resource.ResourceLoaderManager;

/**
 * Test the cross-platform resource loading
 *@author Yannick DOMINGUEZ & Raphael HARMEL
 */
class ResourceTests 
{
	
	private static var rootDOMElement:ContainerDOMElement;
	
	public static function main()
	{
	
		
		rootDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		
		var runner = new Runner();
		runner.addCase(new ResourceTests());
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
	 * Test loading a string (might be plain text, XML JSON...)
	 */
	public function testStringLoad()
	{
		var successCallback:String->Void = Assert.createEvent(onStringLoaded);
		ResourceLoaderManager.loadString("testString.txt", successCallback, onStringLoadError);
	}
	
	/**
	 * Called when the string has been loaded
	 * @param	data the loaded string
	 */
	private function onStringLoaded(data:String):Void
	{
		Assert.same("Hello loaded String !",data);
	}
	
	/**
	 * Called when there is an error while loading string
	 * @param	msg
	 */
	private function onStringLoadError(msg:String):Void
	{
		
	}
	
	/**
	 * Test the loading of a container DOMElement
	 */
	public function testContainerLoad()
	{
		var successCallback:Dynamic->Void = Assert.createEvent(onContainerLoaded);
		
		#if flash9
		var containerUrl:String = "domElementAs3.swf";
		#elseif js
		var containerUrl:String = "domElement.html";
		#elseif php
		var containerUrl:String = "domElement.html";
		#end
		
		ResourceLoaderManager.loadContainer(containerUrl, successCallback, onContainerLoadError);
	}
	
	/**
	 * When the DOMElement has been loaded, attach it to the root DOMElement
	 * @param	domElement the loaded DOMElement
	 */
	private function onContainerLoaded(domElement:ContainerDOMElement):Void
	{
		rootDOMElement.addChild(domElement);
		#if flash9
		Assert.is(domElement.nativeElement, Loader);
		#elseif js
		Assert.same(domElement.nativeElement.firstChild.getAttribute("id"), "loadedDOMElement");
		#elseif php
		Assert.equals(domElement.nativeElement.firstChild().get("id"), "loadedDOMElement");
		Assert.equals(domElement.nativeElement.firstChild().firstChild().toString(), "container loaded");
		#end
	}
	
	/**
	 * Called when there is an error while loading the container DOMElement
	 * @param	msg
	 */
	private function onContainerLoadError(msg:String):Void
	{
		Log.trace(msg);
	}
	
	/**
	 * load a class library (.swf in flash, .js in JavaScript, .php in php)
	 */
	public function testLibraryLoad()
	{
		var successCallback:Dynamic->Void = Assert.createEvent(onLibraryLoaded);
		#if flash9
		ResourceLoaderManager.loadLibrary("testLibrary.swf", successCallback, onLibraryError);
		#elseif js
		ResourceLoaderManager.loadLibrary("testLibrary.js", successCallback, onLibraryError);
		#elseif php
		ResourceLoaderManager.loadLibrary("testLibrary.php", successCallback, onLibraryError);
		#end
	}
	
	/**
	 * when the library has been loaded, instantiate one of the loaded classes
	 * @param	data null for a library
	 */
	private function onLibraryLoaded(data:Dynamic):Void
	{
		var nativeInstance:ClassInstance = NativeInstanceManager.getClassInstanceByClassName("LibrarySymbol");
		
		#if flash9
		flash.Lib.current.addChild(nativeInstance.nativeInstance);
		Assert.same(nativeInstance.getField("x"), 0);
		#elseif js
		Assert.same(nativeInstance.callMethod("testMethod", []), "library loaded ok !");
		#elseif php
		Assert.same(nativeInstance.callMethod("testMethod", []), "library loaded ok !");
		#end
	}

	/**
	 * Called when there is an error while loading the library
	 * @param	msg
	 */
	private function onLibraryError(msg:String):Void
	{
		
	}
	
	/**
	 * Test loading a picture for both flash and JS
	 */
	public function testLoadPicture()
	{
		var successCallback:Dynamic->Void = Assert.createEvent(onPictureLoaded);
		ResourceLoaderManager.loadImage("testPicture.jpg", successCallback, onPictureLoadError);
	}
	
	public function onPictureLoaded(domElement:ImageDOMElement):Void
	{
		Assert.same(domElement.width, 65);
		Assert.same(domElement.height, 65);
		
		Assert.same(domElement.src.indexOf("testPicture.jpg") != -1, true);
		
		rootDOMElement.addChild(domElement);
		
		#if flash9
		domElement.x = 200;
		Assert.is(domElement.nativeElement, Loader);
		#elseif js
		
		#elseif php
		Assert.same(domElement.nativeElement._nodeName, "img");
		Assert.same(domElement.nativeElement.get("src"), "testPicture.jpg");
		#end
	}
	
	/**
	 * test a 404 error on a picture
	 * @param	error
	 */
	public function testPictureLoadError():Void
	{
		var errorCallback:Dynamic->Void = Assert.createEvent(onPictureLoadError);
		ResourceLoaderManager.loadImage("falseURL.jpg", onPictureLoaded, errorCallback);
	}
	
	/**
	 * Called when there is an error while loading picture
	 * @param	error
	 */
	public function onPictureLoadError(error:String)
	{
		Assert.equals(1, 1);
		Log.trace(error);
	}
	
	
	public function testPictureLoadWithDOMElement():Void
	{
		var imageDOMElement:ImageDOMElement = new ImageDOMElement();
		var successCallback:Dynamic->Void = Assert.createEvent(onPictureWithDOMElementLoaded);
		ResourceLoaderManager.loadImage("testPicture.jpg", successCallback, onPictureLoadError, imageDOMElement);
	}
	
	public function onPictureWithDOMElementLoaded(imageDOMElement:ImageDOMElement)
	{
		Assert.same(imageDOMElement.src.indexOf("testPicture.jpg") != -1, true);
	}
	
	
	/**
	 * Test loading a picture without caching it
	 */
	public function testLoadNoCache()
	{
		var successCallback:Dynamic->Void = Assert.createEvent(onPictureNoCacheLoaded);
		ResourceLoaderManager.loadImage("testPicture.jpg", successCallback, onPictureLoadError, null, false);
	}
	
	private function onPictureNoCacheLoaded(domElement:DOMElement):Void
	{
		rootDOMElement.addChild(domElement);
		#if flash9
		Assert.is(domElement.nativeElement, Loader);
		#elseif js
		var croppedSrc:String = domElement.nativeElement.getAttribute("src");
		croppedSrc = croppedSrc.substr(0, croppedSrc.indexOf("?"));
		Assert.same(croppedSrc, "testPicture.jpg");
		#elseif php
		Assert.same(domElement.nativeElement._nodeName, "img");
		var croppedSrc:String = domElement.nativeElement.get("src");
		croppedSrc = croppedSrc.substr(0, croppedSrc.indexOf("?"));
		Assert.same(croppedSrc, "testPicture.jpg");
		#end
	}
	

}