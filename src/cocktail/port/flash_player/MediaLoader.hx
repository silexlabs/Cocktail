/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.flash_player;

import cocktail.port.NativeElement;
import cocktail.core.resource.AbstractMediaLoader;
import flash.display.Loader;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.net.URLRequest;
import haxe.Log;

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
class MediaLoader extends AbstractMediaLoader
{
	/**
	 * class constructor.
	 */
	public function new() 
	{
		_nativeElement = new Loader();
		super();
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
		loader.contentLoaderInfo.addEventListener(Event.INIT, onNativeLoadComplete);
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
		setIntrinsicDimensions(loader);
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
		loader.contentLoaderInfo.removeEventListener(Event.INIT, onNativeLoadComplete);
		loader.contentLoaderInfo.removeEventListener(IOErrorEvent.IO_ERROR, onNativeLoadIOError);
	}
	
	/**
	 * Store the intrinsic dimensions of the loaded asset, retrieved
	 * on the flash Loader
	 */
	private function setIntrinsicDimensions(loader:Loader):Void
	{
		this._intrinsicHeight = Math.round(loader.contentLoaderInfo.height);
		this._intrinsicWidth = Math.round(loader.contentLoaderInfo.width);
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
	}
	
}