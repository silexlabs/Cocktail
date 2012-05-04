/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.resource;
import cocktail.core.NativeElement;
import haxe.Http;
import haxe.Log;

/**
 * This class is in charge of loading one file and calling the right callback after the load succedeed/failed. This is a base
 * class implemented for each media/data types.
 * An array of URL can be provided, in which case, the first valid URL will be used. The onError callback is only
 * called when all the provided URLs are invalid
 * 
 * TODO : rename ResourceLoader
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
	 * Store the index of the URL
	 * which is to be loaded next if the 
	 * currently loading URL is invalid
	 */
	private var _urlToLoadIdx:Int;
	
	/**
	 * Stores the URLs to load, the first
	 * valid one will be used
	 */
	private var _urls:Array<String>;
	
	/**
	 * class constructor
	 */
	public function new()
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public method to start the file loading
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start the loading of a file. Stores the success and error callbacks
	 * 
	 * @param	urls the array of files to load, the first valid url is used
	 * @param	onLoadComplete called when the file is done loading
	 * @param	onLoadError called when there is an error during loading or when all the provided urls are invalid
	 */
	public function load(urls:Array<String>, onLoadComplete:Dynamic->Void, onLoadError:Dynamic->Void):Void
	{
		this._onLoadCompleteCallback = onLoadComplete;
		this._onLoadErrorCallback = onLoadError;
		
		this._urls = urls;
		this._urlToLoadIdx = 0;
		
		doLoad(_urls[_urlToLoadIdx]);
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
	 * When the file is done loading, calls the provided success callback
	 * @param	data the loaded file data, passed to the success callback
	 */
	private function onLoadComplete(data:Dynamic):Void
	{
		_onLoadCompleteCallback(data);
	}
	
	/**
	 * When there is an error while loading a file, try to load
	 * the next file
	 * If all the provided files URL throwed an error, call the
	 * error callback
	 * 
	 * @param	msg the error message, passed to the error callback
	 */
	private function onLoadError(msg:String):Void
	{
		_urlToLoadIdx++;
		if (_urlToLoadIdx < _urls.length - 1)
		{
			doLoad(_urls[_urlToLoadIdx]);
		}
		else
		{
			_onLoadErrorCallback(msg);
		}
	}
}