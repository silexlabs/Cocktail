/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.js;

import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktailCore.resource.abstract.AbstractSkinLoader;
import haxe.Http;
import haxe.Log;
import js.Lib;
import js.Dom.HtmlDom;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktailCore.resource.abstract.AbstractResourceLoader;
import cocktail.resource.ResourceData;

/**
 * This is the Skin loader implementation for the JavaScript runtime. It is used to 
 * load complex object, such as a skin formed of multiple HTML tag. It is loaded from
 * an HTML file
 * 
 * @author Yannick DOMINGUEZ
 */
class SkinLoader extends AbstractSkinLoader
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement JS specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Load an URL and return it as an HTML String using the Http class
	 * 
	 * @param	url the url to load
	 */
	override private function doLoad(url:String):Void
	{
		//prepare and send an http request
		var fileRequest:Http = new Http(url);
		fileRequest.onData = this.onLoadComplete;
		fileRequest.onError = this.onLoadError;
		fileRequest.request(false);
	}
	
	/**
	 * When the HTML has been loaded, set the loaded HTML as the
	 * native DOM of the Container DOMElement
	 * @param	data the loaded HTML
	 */
	override private function onLoadComplete(data:Dynamic):Void
	{
		var domElement:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(neutral));
		domElement.nativeElement.innerHTML = data;
		_onLoadCompleteCallback(domElement);
	}
}