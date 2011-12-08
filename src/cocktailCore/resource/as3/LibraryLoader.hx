/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.as3;

import flash.system.ApplicationDomain;
import flash.system.LoaderContext;
import haxe.Log;
import cocktailCore.resource.abstract.AbstractResourceLoader;

import flash.events.IOErrorEvent;
import flash.net.URLRequest;
import flash.display.Loader;
import flash.events.Event;

/**
 * This is the implementation of the library loader for the Flash AVM2 runtime. A library in Flash AS3 is a .swf
 * file containing ActionScript3 classes. It is loaded like a visual element (DisplayObject) but it is not added to
 * the Flash DOM
 * @author Yannick DOMINGUEZ
 */
class LibraryLoader extends AbstractResourceLoader
{
	/**
	 * The native flash library loader
	 */
	private var _libraryLoader:Loader;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement Flash AS3 specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Load a .swf file using a native ActionScript3 Loader object
	 * @param	url the url of the AS3 .swf to load
	 */
	override private function doLoad(url:String):Void
	{
		//instantiate a native Flash loader
		_libraryLoader = new Loader();
		
		//listen for complete/error event on the loader
		_libraryLoader.contentLoaderInfo.addEventListener(Event.COMPLETE, onLibraryLoadComplete);
		_libraryLoader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onLibraryLoadIOError);
		
		//instantiate a native request object
		var request:URLRequest = new URLRequest(url);
		
		//add a loading context so that the classes will be loaded in the current context
		var loadingContext:LoaderContext = new LoaderContext(false, ApplicationDomain.currentDomain);
		
		//start the loading
		_libraryLoader.load(request, loadingContext);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Native loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the .swf has been loaded, remove the listener on it, then call the load complete method
	 * @param	event the Complete event, contains the native Loader
	 */
	private function onLibraryLoadComplete(event:Event):Void
	{
		_libraryLoader.contentLoaderInfo.removeEventListener(Event.COMPLETE, onLibraryLoadComplete);
		_libraryLoader.contentLoaderInfo.removeEventListener(IOErrorEvent.IO_ERROR, onLibraryLoadIOError);
		
		onLoadComplete(null);
	}
	
	/**
	 * when there was an error during loading, call the error callback with the
	 * the message error
	 * @param	event the IO_ERROR event, containd info on the error
	 */
	private function onLibraryLoadIOError(event:IOErrorEvent):Void
	{
		onLoadError(event.toString());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method for load complete
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the file is done loading, calls the success callback with no argument, as the loaded
	 * library is stored in memory but is not to be manipulated by the object that started the load.
	 * The loaded Flash classes are now available for any Flash component.
	 * @param	data the loaded library data
	 */
	override private function onLoadComplete(data:Dynamic):Void
	{
		_onLoadCompleteCallback(null);
	}
	
}