/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.abstract;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import haxe.Http;
import haxe.Log;

/**
 * This class is in charge of loading one file and calling the right callback after the load succedeed/failed. This is a base
 * class implemented for each media/data types.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractResourceLoader 
{	
	/**
	 * Stores the callback to call once the file is successfully loaded
	 */
	private var _onLoadCompleteCallback:Dynamic->Void;
	
	/**
	 * Stores the callback to call if there is an error during loading
	 */ 
	private var _onLoadErrorCallback:Dynamic->Void;
	
	/**
	 * A reference to the native element actually loading
	 * the asset. For instance, for an image in Flash, a Loader, in JS,
	 * an img tag. When multiple loads occurs, this NativeElement is
	 * reused instead of a new one being created.
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, never):NativeElement;
	
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null)
	{
		//a ResourceLoader doesn't necessarily have a NativeElement.
		//for instance when loading a String, flash will use an URLLoader
		//and JS an XMLHttpRequest object
		if (nativeElement != null)
		{
			_nativeElement = nativeElement;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public method to start the file loading
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start the loading of a file. Stores the success and error callbacks. Prevent file caching if requested
	 * then actually start the file loading
	 * @param	url the url of the file to load
	 * @param	onLoadComplete called when the file is done loading
	 * @param	onLoadError called when there is an error during loading
	 * @param	allowCache wether to allow the browser to cache the loaded file
	 */
	public function load(url:String, onLoadComplete:Dynamic->Void, onLoadError:Dynamic->Void, allowCache:Bool = true):Void
	{
		this._onLoadCompleteCallback = onLoadComplete;
		this._onLoadErrorCallback = onLoadError;
		
		//if the loaded resource must not be cached,
		//add a random number at the end of the url to fool
		//the browser into thinking it loads a new resource
		if (allowCache == false)
		{
			url = disableUrlCaching(url);
		}
		
		doLoad(url);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private method actually starting loading
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually start the file loading. Meant to be overriden.
	 * @param	url the url to load
	 */
	private function doLoad(url:String):Void
	{
		//abstract
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private method on file load complete/error
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the file is done loading, calls the success callback
	 * @param	data the loaded file data, passed to the success callback
	 */
	private function onLoadComplete(data:Dynamic):Void
	{
		_onLoadCompleteCallback(data);
	}
	
	/**
	 * When there is an error while loading a file, calls the error
	 * callback
	 * @param	msg the error message, passed to the error callback
	 */
	private function onLoadError(msg:String):Void
	{
		_onLoadErrorCallback(msg);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private utils method 
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Append a random number to the url to make it unique
	 * @param	url the url to transform
	 * @return the randomised url
	 */
	private function disableUrlCaching(url:String):String
	{
		var getId:String = "";
		
		//if this is the first GET variable of the url, start with 
		//a quotation mark
		if (url.indexOf("?") == -1)
		{
			getId =  "?";
		}
		//else start with an 'and'
		else
		{
			getId = "&";
		}
		
		//appand a GET var with a unique random value to make the URL unique
		url += getId + "rand=" + Math.round(Math.random() * 10000);
		
		return url;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getNativeElement():NativeElement
	{
		return _nativeElement;
	}
}