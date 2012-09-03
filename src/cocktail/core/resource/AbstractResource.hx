/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.resource;

import cocktail.core.event.EventConstants;
import cocktail.core.event.EventTarget;
import cocktail.core.event.UIEvent;

/**
 * Represent a loaded external resource, such as 
 * a loaded picture
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractResource extends EventTarget
{
	/**
	 * Wether the resource was successfully loaded
	 */
	public var loaded(default, null):Bool;
	
	/**
	 * Wether there was an error during the loading
	 * of the resource
	 */
	public var loadedWithError(default, null):Bool;
	
	/**
	 * give access to the native loaded resource. For
	 * instance, for a picture, give access to the bitmap data
	 */
	public var nativeResource(default, null):Dynamic;

	/**
	 * The intrinsic width of the loaded resource
	 */
	public var intrinsicWidth(default, null):Float;
	
	/**
	 * The intrinsic height of the loaded resource
	 */
	public var intrinsicHeight(default, null):Float;
	
	/**
	 * The intrinsic ratio of the loaded resource
	 */
	public var intrinsicRatio(default, null):Float;
	
	public function new(url:String) 
	{
		super();
		
		loaded = false;
		loadedWithError = false;
		load(url);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private loading method
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * starts the loading of the resource using platform
	 * specific APIs
	 */
	private function load(url:String):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private method on resource load complete/error
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Dispatch a load event when the 
	 * resource was successfuly loaded,
	 * and set the right flag
	 */
	private function onLoadComplete():Void
	{
		loaded = true;
		
		var loadEvent:UIEvent = new UIEvent();
		loadEvent.initUIEvent(EventConstants.LOAD, false, false, null, 0.0);
		dispatchEvent(loadEvent);
	}
	
	/**
	 * Dispatch an error event when there
	 * was an error while loading,
	 * and set the right flag
	 */
	private function onLoadError():Void
	{
		loadedWithError = true;
		
		var errorEvent:UIEvent = new UIEvent();
		errorEvent.initUIEvent(EventConstants.ERROR, false, false, null, 0.0);
		dispatchEvent(errorEvent);
	}
}