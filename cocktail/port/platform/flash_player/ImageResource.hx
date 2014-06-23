/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.port.base.ResourceBase;
import cocktail.url.URL;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.DisplayObject;
import flash.display.DisplayObjectContainer;
import flash.display.Loader;
import flash.errors.SecurityError;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.net.URLRequest;
import haxe.Log;

#if flash9
import flash.system.LoaderContext;
#end

/**
 * This is the Flash As3 implementation of the Resource.
 * Load a resource into a native flash Loader, then
 * store the bitmap data retrieved from the loader
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageResource extends ResourceBase
{
	/**
	 * The native flash loader used to
	 * load the resource
	 */
	private var _loader:Loader;
	
	/**
	 * class constructor.
	 */
	public function new(url:String)
	{
		_loader = new Loader();
		super(url);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement Flash AS3 specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Load a resource using a native ActionScript3 Loader object
	 * @param	url the url of the AS3 resource to load
	 */
	override private function load(url:String):Void
	{
		//if built with openfl, the asset might have been embedded
		//at compile-time
		#if openfl
		if (url.indexOf("http://") == -1 && url.indexOf("https://") == -1) {

			var asset:BitmapData = openfl.Assets.getBitmapData(url);
			
			//here the asset was embedded, no need
			//to load
			if (asset != null)
			{
				nativeResource = asset;
				intrinsicHeight = asset.height;
				intrinsicWidth = asset.width;
				intrinsicRatio = intrinsicWidth / intrinsicHeight;
				onLoadComplete();
				return;
			}
		}
		#end
		
		_loader.unload();
		
		//listen for complete/error event on the loader
		_loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onNativeLoadComplete);
		_loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onNativeLoadIOError);
		
		//instantiate a native request object
		var request:URLRequest = new URLRequest(url);
		
		//add a loading context so that the resource will be loaded in the current context
		#if flash
		//always check policy file (crossdomain.xml) for cross-domain loading
		var loadingContext:LoaderContext = new LoaderContext(true);

		//trigger decoding of picture in another thread
		//
		//set with reflection as this is a newish property (flash player 11)
		//this way, cocktail can still be built for older flash player
		if (Reflect.hasField(loadingContext, "imageDecodingPolicy"))
		{
			Reflect.setField(loadingContext, "imageDecodingPolicy", "onLoad");
		}
		
		//start the loading
		_loader.load(request, loadingContext);
		#else
		//start the loading
		_loader.load(request);
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Native loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the resource has been loaded, remove the listener on it, 
	 * then call the load complete method
	 * @param	event the Complete event, contains the native Loader
	 */
	private function onNativeLoadComplete(event:Event):Void
	{	
		removeLoaderListeners(_loader);
		setIntrinsicDimensions(_loader);
		setNativeResource(_loader);
	}
	
	/**
	 * When there was an error during loading, call the error callback 
	 * @param	event the IO_ERROR event, contains info on the error
	 */
	private function onNativeLoadIOError(event:IOErrorEvent):Void
	{
		removeLoaderListeners(_loader);
		onLoadError();
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
	
	/**
	 * Store the intrinsic dimensions of the loaded asset, retrieved
	 * on the flash Loader
	 */
	private function setIntrinsicDimensions(loader:Loader):Void
	{
		#if flash
		intrinsicHeight = Math.round(loader.contentLoaderInfo.height);
		intrinsicWidth = Math.round(loader.contentLoaderInfo.width);
		//openfl don't support contentLoaderInfo
		#elseif openfl
		intrinsicHeight = Math.round(loader.height);
		intrinsicWidth = Math.round(loader.width);
		#end
		
		intrinsicRatio = intrinsicWidth / intrinsicHeight;
	}
	
	/**
	 * Store the bitmap data loaded by the flash loader
	 * 
	 * The security check necessary to load cross-domain picture
	 * are described here : 
	 * http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/flash/system/LoaderContext.html#checkPolicyFile
	 */
	private function setNativeResource(loader:Loader):Void
	{
		//if child allows parent is true, it means that the child
		//was either loaded from the same domain or has a valid cross-domain,
		//it can be used right now
		if (loader.contentLoaderInfo.childAllowsParent == true)
		{
			getBitmapDataFromLoader(loader);
			onLoadComplete();
		}
		//else the child comes from a domain whose crossdomain was not loaded yet
		//or does not exist. It can happen when the picture is request on a domain
		//after an http 30X re-direction, only the crossdomain from the original
		//domain is loaded not the redirected one,
		//so we load the crossdomain of the redirection url explicitely
		else 
		{
			#if flash
			var url:URL = URL.fromString(loader.contentLoaderInfo.url);
			var reconstitutedURL:String = url.scheme +"://"+ url.authority + "/";
			flash.system.Security.loadPolicyFile(reconstitutedURL + "crossdomain.xml");
			//poll at regular interval to see if the 
			//cross domain was loaded. This is the only way,
			//as flash doesn't have an event for it
			onChildAllowsParentTick();
			#end
		}
	}
	
	/**
	 * Store the loader's bitmapData
	 */
	private function getBitmapDataFromLoader(loader:Loader):Void
	{
		var bitmap:Bitmap = cast(loader.content);
		nativeResource = bitmap.bitmapData;
	}
	
	/**
	 * Poll at regular interval to check that the cross-domain
	 * policy file was loaded
	 */
	private function onChildAllowsParentTick():Void
	{
		//while the loaded content can't be manipulated, reschedule
		//a poll
		if (_loader.contentLoaderInfo.childAllowsParent == false)
		{
			haxe.Timer.delay(function() { onChildAllowsParentTick(); } , 50);
		}
		else
		{
			getBitmapDataFromLoader(_loader);
			onLoadComplete();
		}
	}
	
}
