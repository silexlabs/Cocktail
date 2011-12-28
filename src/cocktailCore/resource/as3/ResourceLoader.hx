/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.as3;

import cocktail.nativeElement.NativeElement;
import cocktailCore.resource.abstract.AbstractResourceLoader;
import flash.display.Loader;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.net.URLRequest;

#if flash9
import flash.system.LoaderContext;
import flash.system.ApplicationDomain;
#end

/**
 * This is the Flash As3 implementation of the ResourceLoader.
 * Load a resource into a native flash Loader, the Loader
 * can then be used as a NativeElement to attach it to the
 * DOM
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
	// Overriden method to implement Flash AS3 specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Load a resource using a native ActionScript3 Loader object
	 * @param	url the url of the AS3 resource to load
	 */
	override private function doLoad(url:String):Void
	{
		var loader:Loader = cast(_nativeElement);
		
		loader.unload();
		
		//listen for complete/error event on the loader
		loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onNativeLoadComplete);
		loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onNativeLoadIOError);
		
		//instantiate a native request object
		var request:URLRequest = new URLRequest(url);
		
		//add a loading context so that the resource will be loaded in the current context
#if flash9
		var loadingContext:LoaderContext = new LoaderContext(false, ApplicationDomain.currentDomain);
		//always check policy file (crossdomain.xml) for cross-domain loading
		loadingContext.checkPolicyFile = true;

		//start the loading
		loader.load(request, loadingContext);
#else
		//start the loading
		loader.load(request);
#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Native loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the resource has been loaded, remove the listener on it, 
	 * then call the load complete method passing the loaded resource as a NativeElement
	 * @param	event the Complete event, contains the native Loader
	 */
	private function onNativeLoadComplete(event:Event):Void
	{	
		var loader:Loader = cast(_nativeElement);
		removeLoaderListeners(loader);
		onLoadComplete(loader);
	}
	
	/**
	 * When there was an error during loading, call the error callback with the
	 * the message error, remove the event listeners
	 * @param	event the IO_ERROR event, containd info on the error
	 */
	private function onNativeLoadIOError(event:IOErrorEvent):Void
	{
		var loader:Loader = cast(_nativeElement);
		removeLoaderListeners(loader);
		onLoadError(event.toString());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Remove loading listeners from the flash loader
	 */
	private function removeLoaderListeners(loader:Loader):Void
	{
		loader.contentLoaderInfo.removeEventListener(Event.COMPLETE, onNativeLoadComplete);
		loader.contentLoaderInfo.removeEventListener(IOErrorEvent.IO_ERROR, onNativeLoadIOError);
	}
	
}