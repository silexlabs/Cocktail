/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.js;

import core.nativeElement.NativeElement;
import cocktailCore.resource.abstract.AbstractResourceLoader;

/**
 * This is the JavaScript implementation of the ResourceLoader.
 * Load a resource by setting the src attribute on the right
 * HTML tag
 * 
 * @author Yannick DOMINGUEZ
 */
class ResourceLoader extends AbstractResourceLoader
{

	/**
	 * class constructor.
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement JS specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * To load a resource, the source of the HTML element is
	 * set to the url to load
	 * @param	url the url of the picture
	 */
	override private function doLoad(url:String):Void
	{	
		//create a delegate to call the success callback once the native HTML element is done loading the resource
		var onLoadCompleteDelegate:NativeElement->Void = onNativeLoadComplete;
		//create a delegate for the error callback
		var onLoadErrorDelegate:String->Void = onNativeLoadError;
		
		//need to have a local reference to retrieve it in the static onload function
		var nativeElementDelegate:NativeElement = _nativeElement;
		
		//listens to load complete and load error.
		untyped _nativeElement.onload = function() { 
			
			onLoadCompleteDelegate(nativeElementDelegate);
			
			};
		untyped _nativeElement.onerror = function() { onLoadErrorDelegate("couldn't load picture"); };
		
		// set it's source to start the loading of the resource
		_nativeElement.setAttribute("src", url);
	}
	

	//////////////////////////////////////////////////////////////////////////////////////////
	// Native loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the resource has been loaded store the intrinsic dimensions
	 * of the asset and call the success callback
	 */
	private function onNativeLoadComplete(nativeElement:NativeElement):Void
	{	
		setIntrinsicDimensions(nativeElement);
		onLoadComplete(nativeElement);
	}
	
	/**
	 * When there was an error during loading, call the error callback with the
	 * the message error
	 */
	private function onNativeLoadError(event:String):Void
	{
		onLoadError(event.toString());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Store the intrinsic dimensions of the loaded asset, retrieved
	 * on the native HTML element
	 */
	private function setIntrinsicDimensions(nativeElement:NativeElement):Void
	{
		this._intrinsicHeight = untyped nativeElement.naturalHeight;
		this._intrinsicWidth = untyped nativeElement.naturalWidth;
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
	}
	
}