/*
This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/

This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.resource;

import cocktailCore.resource.abstract.AbstractResourceLoader;
import cocktail.domElement.DOMElement;
import cocktail.resource.ResourceData;

#if (flash9 || cpp || nme)
import cocktailCore.resource.as3.StringLoader;
import cocktailCore.resource.as3.ImageLoader;
import cocktailCore.resource.as3.SkinLoader;
import cocktailCore.resource.as3.LibraryLoader;

#elseif js
import cocktailCore.resource.js.StringLoader;
import cocktailCore.resource.js.ImageLoader;
import cocktailCore.resource.js.SkinLoader;
import cocktailCore.resource.js.LibraryLoader;

#elseif php
import cocktailCore.resource.php.StringLoader;
import cocktailCore.resource.php.ImageLoader;
import cocktailCore.resource.php.SkinLoader;
import cocktailCore.resource.php.AnimationLoader;
import cocktailCore.resource.php.LibraryLoader;

#elseif doc
class StringLoader extends AbstractStringLoader {}
class SkinLoader extends AbstractSkinLoader {}
class LibraryLoader extends AbstractLibraryLoader {}

#end	

/**
 * Manages a queue of files to load, and exposes method to load resources of diferent types. 
 * @author Yannick DOMINGUEZ
 */
class ResourceLoaderManager 
{	
	/**
	 * Queue of files to load, stored in the order where they must be loaded
	 */
	private static var _resourceDataArray:Array<ResourceData>;
	
	/**
	 * Wheter a file is currently loading
	 */
	private static var _isLoading:Bool = false;
	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, starting the files loading
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadString(url:String, successCallback:String->Void, errorCallback:String->Void , allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			allowCache:allowCache,
			loadingType:data
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadLibrary(url:String, successCallback:Dynamic->Void, errorCallback:String->Void , allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			allowCache:allowCache,
			loadingType:library
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, managing the loading queue
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * stores the ResourceData in resourceDataArray. Call loadNextResource if isLoading is false. 
	 * @param resourceData the new resourceData to add
	 */
	private static function addResourceData(resourceData:ResourceData):Void
	{
		//instantiate the array if first use
		if (_resourceDataArray == null)
		{
			_resourceDataArray = new Array<ResourceData>();
		}
		
		_resourceDataArray.push(resourceData);
		
		if (_isLoading == false)
		{
			loadNextResource();
		}
	}
	
	/**
	 *  Set isLoading to true or false depending on the content of filesArray.
	 *	Retrieve the next ResourceData object.
	 *	Create the corresponding AbstractResourceLoader
	 *	Actually start loading the resource.
	 */
	private static function loadNextResource():Void
	{
		//if there are no more elements to load in the resourceData array,
		//do nothing
		if (_resourceDataArray.length == 0)
		{
			_isLoading = false;
		}
		//else load the next file in the array
		else
		{
			_isLoading = true;
			
			var resourceDataToLoad:ResourceData = _resourceDataArray[0];
			
			var resourceLoader:AbstractResourceLoader;
			switch (resourceDataToLoad.loadingType)
			{
				case data:
				resourceLoader = new StringLoader();
				
				case library:
				resourceLoader = new LibraryLoader();
			}
			
			resourceLoader.load(resourceDataToLoad.url, onLoadComplete, onLoadError, resourceDataToLoad.allowCache);
		}
	}
	
	/**
	 * Remove the 1st ResourceData from resourceDataArray and call the success callback.
	 * Then call loadNextResource.
	 * @param	data the loaded file data
	 */
	private static function onLoadComplete(data:Dynamic):Void
	{
		var loadedResourceData:ResourceData = _resourceDataArray.shift();
		
		loadedResourceData.onLoadComplete(data); 
		
		loadNextResource();
	}
	
	/**
	 * Remove the 1st ResourceData from resourceDataArray and call the error callback.
	 * Then call loadNextResource.
	 * @param	data the loading error data
	 */
	private static function onLoadError(data:Dynamic):Void
	{
		var errorResourceData:ResourceData = _resourceDataArray.shift();
		
		errorResourceData.onLoadError(data);
		
		loadNextResource();
	}
	
}