/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.js;

import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktailCore.resource.abstract.AbstractImageLoader;
import haxe.Http;
import haxe.Log;
import js.Lib;
import js.Dom.HtmlDom;
import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.resource.ResourceData;
import cocktail.nativeElement.NativeElementData;

/**
 * This is the Image loader implementation for the JavaScript runtime. It is used to 
 * load pictures that will be attached to the DOM. It loads the picture by creating
 * an <img> tag and setting it's source to the url of the file to load.
 * 
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageLoader extends AbstractImageLoader
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement JS specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * To load a picture, the source of the Image HTML element is
	 * set to the url to load
	 * @param	url the url of the picture
	 */
	override private function doLoad(url:String):Void
	{	
		//create a delegate to call the success callback once the native image element is done loading the source picture
		var onLoadCompleteDelegate:NativeElement->Void = onLoadComplete;
		//create a delegate for the error callback
		var onLoadErrorDelegate:String->Void = onLoadError;
		
		//need to have a local reference to retrieve it in the static onload function
		var nativeElementDelegate:NativeElement = _nativeElement;
		
		//listens to image load complete and load error.
		untyped _nativeElement.onload = function() { 
			
			onLoadCompleteDelegate(nativeElementDelegate);
			
			};
		untyped _nativeElement.onerror = function() { onLoadErrorDelegate("couldn't load picture"); };
		
		// set it's source to start the loading of the picture
		_nativeElement.setAttribute("src", url);
	}
}