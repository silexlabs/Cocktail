/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.flash_player;

import cocktail.core.resource.AbstractResource;
import flash.display.Loader;
import flash.events.IOErrorEvent;
import flash.net.URLRequest;
#if flash
import flash.system.LoaderContext;
#end

/**
 * Load and store an swf file, for the
 * flash, air and nme target
 * 
 * @author Yannick DOMINGUEZ
 */
class SWFResource extends AbstractResource
{
	/**
	 * The native flash loader used to
	 * load the swf
	 */
	private var _loader:Loader;
	
	public function new(url:String) 
	{
		_loader = new Loader();
		super(url);
	}
	
	/**
	 * start loading the swf. 
	 * If nme is targeted, first check
	 * wether the swf is embedded
	 * 
	 * @param	url the url of the swf
	 * to load
	 */
	override private function load(url:String):Void
	{
		#if nme
		//check wether bytes are available for this
		//url
		var bytes = nme.Assets.getBytes(url);
		if (bytes != null)
		{
			#if air
			
			//if the runtime is air, use native flash api to load
			//content from bytes
			var loadingContext:LoaderContext = new LoaderContext(false);
			loadingContext.allowCodeImport = true;
			_loader = new Loader();
			_loader.contentLoaderInfo.addEventListener(flash.events.Event.INIT, onSWFLoadComplete);
			_loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onSWFLoadIOError);
			_loader.loadBytes(bytes, loadingContext);
			return;
			
			#else
			//if they are, create a movieclip from it
			var swf:format.SWF = new format.SWF(bytes);
			nativeResource = swf.createMovieClip();
			
			//store width height metadata
			//of the swf
			intrinsicHeight = swf.height;
			intrinsicWidth = swf.width;
			
			//call the ready callback and return, no
			//need to load the swf
			onLoadComplete();
			return;
			#end
		}
		#end
		
		_loader = new Loader();
		
		//listen for complete/error event on the loader
		_loader.contentLoaderInfo.addEventListener(flash.events.Event.INIT, onSWFLoadComplete);
		_loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onSWFLoadIOError);
		
		//instantiate a native request object
		var request:URLRequest = new URLRequest(url);
		
		//add a loading context so that the resource will be loaded in the current context
		#if flash
		var loadingContext:LoaderContext = new LoaderContext(false);
		//always check policy file (crossdomain.xml) for cross-domain loading
		loadingContext.checkPolicyFile = true;

		//start the loading
		_loader.load(request, loadingContext);
		#else
		//start the loading
		_loader.load(request);
		#end
	}
	

	/**
	 * When loaded, store the loaded swf, call the
	 * success callback as the plugin is now ready
	 */
	private function onSWFLoadComplete(event:flash.events.Event):Void
	{	
		removeLoaderListeners(_loader);
		nativeResource = _loader.content;
		
		//store width height metadata
		//of the loaded swf
		intrinsicHeight = _loader.contentLoaderInfo.height;
		intrinsicWidth = _loader.contentLoaderInfo.width;
		
		onLoadComplete();
	}
	
	/**
	 * Call the error callback
	 */
	private function onSWFLoadIOError(event:IOErrorEvent):Void
	{
		removeLoaderListeners(_loader);
		onLoadError();
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////// //////////////////////////////////////////////////////
	
	/**
	 * Remove loading listeners from the flash loader
	 */
	private function removeLoaderListeners(loader:Loader):Void
	{
		loader.contentLoaderInfo.removeEventListener(flash.events.Event.INIT, onSWFLoadComplete);
		loader.contentLoaderInfo.removeEventListener(IOErrorEvent.IO_ERROR, onSWFLoadIOError);
	}
}