/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.resource.as3;

import flash.display.Loader;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.net.URLRequest;
import flash.system.ApplicationDomain;
import flash.system.LoaderContext;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.resource.abstract.AbstractResourceLoader;
import cocktail.resource.ResourceData;

/**
 * This is the Container loader implementation for the Flash runtime. It is used to 
 * load complex object, such as a skin contained in a .swf file.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerLoader extends AbstractResourceLoader
{
	/**
	 * The native flash skin loader
	 */
	private var _skinLoader:Loader;
	
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
		_skinLoader = new Loader();
		
		//listen for complete/error event on the loader
		_skinLoader.contentLoaderInfo.addEventListener(Event.COMPLETE, onSkinLoadComplete);
		_skinLoader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onSkinLoadIOError);
		
		//instantiate a native request object
		var request:URLRequest = new URLRequest(url);
		
		//add a loading context so that the classes will be loaded in the current context
		var loadingContext:LoaderContext = new LoaderContext(false, ApplicationDomain.currentDomain);
		
		//start the loading
		_skinLoader.load(request, loadingContext);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Native loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the .swf has been loaded, remove the listener on it, 
	 * instantiate a container DOMElement and set the loaded Flash skin
	 * as it's native DOMElement,
	 * then call the load complete method
	 * @param	event the Complete event, contains the native Loader
	 */
	private function onSkinLoadComplete(event:Event):Void
	{
		_skinLoader.contentLoaderInfo.removeEventListener(Event.COMPLETE, onSkinLoadComplete);
		_skinLoader.contentLoaderInfo.removeEventListener(IOErrorEvent.IO_ERROR, onSkinLoadIOError);
		
		var containerDOMElement:DOMElement = new ContainerDOMElement(_skinLoader);
		
		onLoadComplete(containerDOMElement);
	}
	
	/**
	 * when there was an error during loading, call the error callback with the
	 * the message error, remove the event listeners
	 * @param	event the IO_ERROR event, containd info on the error
	 */
	private function onSkinLoadIOError(event:IOErrorEvent):Void
	{
		_skinLoader.contentLoaderInfo.removeEventListener(Event.COMPLETE, onSkinLoadComplete);
		_skinLoader.contentLoaderInfo.removeEventListener(IOErrorEvent.IO_ERROR, onSkinLoadIOError);
		
		onLoadError(event.toString());
	}
}